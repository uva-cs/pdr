const INSTRUCTION_REGEX = /[a-fA-F0-9]{4}/;
const WATCHDOG_MAX_LIMIT = 1000;

let instructions = [];

let pc = "0000";
let pchexbak = "0000";
let awaiting_input = false;

// Handle enter
const userInput = document.getElementById('input');
userInput.addEventListener('keyup', event => { if (event.key === 'Enter') run_simulator(); });

// Reload table when `loadmem` is toggled
const loadmemInput = document.getElementById('loadmem');
loadmemInput.addEventListener('change', create_ibcm_memory_table);

const fileInput = document.getElementById('userfile');
fileInput.addEventListener('change', readIBCMFile);

function readIBCMFile(event) {
    if (this.files.length !== 1) {
        return;
    }

    const file = this.files[0];

    // TODO: There is a newer promise-based API, Blob.readText(),
    // but it is not yet supported by Safari as of March 2020.
    // Would be nice to switch over to that API when browser support improves.
    const reader = new FileReader();
    reader.onload = e => processIBCMFile(e.target.result);
    reader.readAsText(file);
    event.preventDefault();
}

function processIBCMFile(text) {
    instructions = []; // Reset instructions array

    const lines = text.split(/\r?\n/) // Split on newlines
    let currentLine = 0; // Zero-indexed indicator of which line we are parsing
    for (let line of lines) {
        line = line.trim(); // Trim whitespace

        // Ignore blank or commented-out lines
        if (line.length === 0 || line.startsWith('#') || line.startsWith('//')) {
            continue;
        }

        // Test for invalid input
        const result = INSTRUCTION_REGEX.exec(line);
        if (result === null || result.index !== 0) {
            document.getElementById('error').innerText = `Could not read line ${currentLine + 1} -- make sure it is valid and try again`;
            revert();
            return;
        }

        instructions.push(result[0]);
        document.getElementById(`v${currentLine.toString(16).padStart(4, '0')}`).value = result[0];

        // Only increment currentLine if we successfully parse the line
        currentLine++;
    }

    // Fill in everything else with 0000s
    for (let i = currentLine; i < document.getElementsByClassName('address').length; i++) {
        document.getElementById(`v${i.toString(16).padStart(4, '0')}`).value = '0000';
    }
}

function create_ibcm_memory_table() {
    const top = loadmemInput.checked ? 4096 : 100;

    for (let i = 0; i < top; i++) {
        const divname = i.toString(16).padStart(4, '0');
        const elem = `<tr><td><code>${divname}</code></td><td><input type="text" id="v${divname}" class="address monospace-input" size=4></td><td><div id="pc${divname}"></div></td></tr>`;
        document.getElementById('instructionsTable').getElementsByTagName('tbody')[0].innerHTML += elem;
    }
}

function init() {
    create_ibcm_memory_table();
    revert();
}

function revert() {
    reset();
    for (let i = 0; i < instructions.length; i++) {
        document.getElementById(`v${i.toString(16).padStart(4, '0')}`).value = instructions[i];
    }
}

function reset() {
    document.getElementById("accum").value = "0000";
    document.getElementById("pc").value = "0000";
    if (pc !== "xxxx") {
        document.getElementById("pc" + pc).innerHTML = ""; // erase old PC
    }

    document.getElementById("pc" + pchexbak).innerHTML = ""; // erase old PC
    document.getElementById("pc0000").innerHTML = "<-";
    pc = "0000";
    document.getElementById("inputtitle").innerHTML = "Input:";
    document.getElementById("input").value = "";
    document.getElementById("output").value = "";
    awaiting_input = false;
    document.getElementById("bptitle").innerHTML = "Breakpoint (hex): ";
    document.getElementById("watchwarning").innerHTML = "";
}

function run_simulator() {
    // initialize watchdog vars
    const useWatchdogTimer = document.getElementById("watchtimer").checked;
    let watchdogCounter = 1;
    document.getElementById("watchwarning").innerHTML = "";

    // initialize breakpoint vars
    const breakpoint = document.getElementById("breakpoint").value.toLowerCase();
    document.getElementById("bptitle").innerHTML = "Breakpoint (hex): ";

    // run until the breakpoint is hit or the watchdog counter reaches its limit
    do {
        execute_instruction();
        watchdogCounter++;
    } while (pc !== "xxxx" && !awaiting_input && pc != breakpoint && (useWatchdogTimer ? watchdogCounter < WATCHDOG_MAX_LIMIT : true));

    if (pc === breakpoint) {
        document.getElementById("bptitle").innerHTML = "<em>Breakpoint (hex): </em>";
    } else if (useWatchdogTimer && watchdogCounter >= WATCHDOG_MAX_LIMIT) {
        document.getElementById("watchwarning").innerHTML = `Watchdog timed out after ${WATCHDOG_MAX_LIMIT} instructions. If this is expected, continue with 'Run'.`;
    }
}

function step_simulator() {
    document.getElementById("bptitle").innerHTML = "Breakpoint (hex): ";
    execute_instruction();
}

function execute_instruction() {
    let instruction = document.getElementById('v' + pc).value;
    if (instruction === "") {
        instruction = "0000";
    }

    const opcode = get_IBCM_opcode(instruction);
    const address = instruction.substring(1, 4).toLowerCase();
    let accum = document.getElementById("accum").value;
    document.getElementById("pc" + pc).innerHTML = ""; // erase old PC
    if (!awaiting_input) {
        increment_pc();
    }

    let immediate = '';
    switch (opcode) {
        case 0x0: // halt
            pc = dec_to_hex(hex_to_dec(pc) - 1);
            document.getElementById("pc" + pc).innerHTML = "H";
            document.getElementById("pc").value = pc + " (halted)";
            pchexbak = pc; // so the 'H' can be erased by the reset button
            pc = "xxxx";
            break;
        case 0x1: // I/O
            const output = document.getElementById("output");
            const asciimode = get_IBCM_2bitop(instruction);
            switch (asciimode) {
                case 0: // read hex
                // FALL THRU
                case 1: // read ascii
                    if (!awaiting_input) {
                        if (asciimode) {
                            document.getElementById("inputtitle").innerHTML = "<em>Input (asc):</em>";
                        } else {
                            document.getElementById("inputtitle").innerHTML = "<em>Input (hex):</em>";
                        }

                        document.getElementById("input").value = "";
                        pc = dec_to_hex(hex_to_dec(pc) - 1);
                        document.getElementById("pc" + pc).innerHTML = "I";
                        document.getElementById("pc").value = pc + " (awaiting input)";
                        awaiting_input = true;
                        document.getElementById("input").focus();
                        return;
                    } else {
                        // is the value empty?
                        if (document.getElementById("input").value === "") {
                            document.getElementById("pc" + pc).innerHTML = "I";
                            document.getElementById("input").focus();
                            return;
                        }

                        document.getElementById("inputtitle").innerHTML = "Input:";
                        document.getElementById("pc" + pc).innerHTML = ""; // remove the 'I'
                        awaiting_input = false;
                        increment_pc();
                        if (asciimode) {
                            accum = dec_to_hex(document.getElementById("input").value.charCodeAt(0));
                        } else { // hex
                            accum = dec_to_hex(parseInt(document.getElementById("input").value, 16));
                        }
                    }
                    break;
                case 2: // write hex
                    output.value += accum + "\n";
                    break;
                case 3: // write ascii
                    output.value += String.fromCharCode(hex_to_dec(accum) & 0xff) + "\n";
                    break;
            }
            break;
        case 0x2: // shifts
            const shiftamount = get_IBCM_shift(instruction);
            let accdec = hex_to_dec(accum);
            switch (get_IBCM_2bitop(instruction)) {
                case 0: // shift left
                    accdec = (accdec << shiftamount) & 0xffff;
                    break;
                case 1: // shift right
                    accdec = (accdec >> shiftamount) & (0xffff >> shiftamount);
                    break;
                case 2: // rotate left
                    accdec = ((accdec << shiftamount) & 0xffff) | ((accdec >> 16 - shiftamount) & (0xffff >> 16 - shiftamount));
                    break;
                case 3: // rotate right
                    accdec = ((accdec >> shiftamount) & (0xffff >> shiftamount)) | ((accdec << 16 - shiftamount) & 0xffff);
                    break;
            }
            accum = dec_to_hex(accdec);
            break;
        case 0x3: // load
            accum = document.getElementById("v0" + address).value;
            break;
        case 0x4: // store
            document.getElementById("v0" + address).value = accum;
            break;
        case 0x5: // add
            immediate = document.getElementById("v0" + address).value;
            accum = dec_to_hex(hex_to_dec(accum) + hex_to_dec(immediate));
            break;
        case 0x6: // sub
            immediate = document.getElementById("v0" + address).value;
            accum = dec_to_hex(hex_to_dec(accum) - hex_to_dec(immediate));
            break;
        case 0x7: // and
            immediate = document.getElementById("v0" + address).value;
            accum = dec_to_hex(hex_to_dec(accum) & hex_to_dec(immediate));
            break;
        case 0x8: // or
            immediate = document.getElementById("v0" + address).value;
            accum = dec_to_hex(hex_to_dec(accum) | hex_to_dec(immediate));
            break;
        case 0x9: // xor
            immediate = document.getElementById("v0" + address).value;
            accum = dec_to_hex(hex_to_dec(accum) ^ hex_to_dec(immediate));
            break;
        case 0xa: // not
            accum = dec_to_hex(~hex_to_dec(accum));
            break;
        case 0xb: // nop
            // do nothing
            break;
        case 0xc: // jmp
            pc = "0" + address;
            break;
        case 0xd: // jmpe
            if (accum === "0000")
                pc = "0" + address;
            break;
        case 0xe: // jmpl
            if (hex_to_dec(accum) < 0)
                pc = "0" + address;
            break;
        case 0xf: // brl
            accum = pc;
            pc = "0" + address;
            break;
    }

    if (pc !== "xxxx") {
        document.getElementById("pc" + pc).innerHTML = "<-"; // set new PC
        document.getElementById("pc").value = pc;
    }

    document.getElementById("accum").value = accum.toLowerCase();
}

function increment_pc() {
    pc = dec_to_hex(hex_to_dec(pc) + 1);
}

// Given an IBCM instruction abcd:
// a is the opcode
// For I/O instructions:
// - b is the input/output and ascii/hex switch
//    - 0: input hex (binary 0000, dec 0)
//    - 4: input ascii (binary 0100, dec 4)
//    - 8: output hex (binary 1000, dec 8)
//    - c: output ascii (binary 1100, dec 12)
// - c, d unused
// For shift instructions:
// - b is the shift/rotate and left/right switch
//    - 0: shift left (binary 0000, dec 0)
//    - 4: shift right (binary 0100, dec 4)
//    - 8: rotate left (binary 1000, dec 8)
//    - c: rotate right (binary 1100, dec 12)
// - c is unused
// - d is the count to shift by
// For all other instructions:
// - bcd is the address
function get_IBCM_opcode(instruction) {
    return hex_to_dec(instruction.charAt(0));
}

function get_IBCM_address(instruction) {
    return hex_to_dec(instruction.substring(1, 4));
}

function get_IBCM_2bitop(instruction) {
    return Math.floor(hex_to_dec(instruction.charAt(1)) / 4);
}

function get_IBCM_shift(instruction) {
    return hex_to_dec(instruction.charAt(3));
}

// Treats the hex value as a signed short (4 bytes),
// but is otherwise the same as Number.parseInt(hex, 16)
function hex_to_dec(hex) {
    let result = Number.parseInt(hex, 16);
    if (result > 32767) {
        return result - 65536;
    } else {
        return result;
    }
}

function dec_to_hex(dec) {
    if (dec < 0) {
        dec += 65536;
    }
    return dec.toString(16).padStart(4, '0');
}
