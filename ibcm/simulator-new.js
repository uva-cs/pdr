const INSTRUCTION_REGEX = /[a-fA-F0-9]{4}/;

const input = document.getElementById('userfile');

input.addEventListener('change', readIBCMFile);

function readIBCMFile(event) {
    if (this.files.length != 1) {
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
    const lines = text.split(/\r?\n/) // Split on newlines
    for (let i = 0; i < lines.length; i++) {
        const line = lines[i].trim(); // Trim whitespace

        // Ignore blank or commented-out lines
        if (line.length === 0 || line.startsWith('#') || line.startsWith('//')) {
            continue;
        }

        // Test for invalid input
        const result = INSTRUCTION_REGEX.exec(line);
        if (result === null || result.index !== 0) {
            document.getElementById('error').innerText = `Could not read line ${i + 1} -- make sure it is valid and try again`;
            revert();
            return;
        }

        document.getElementById(`v${i.toString(16).padStart(4, '0')}`).value = result[0];
    }

    // Fill in everything else with 0000s
    for (let i = lines.length; i < 100; i++) {
        document.getElementById(`v${i.toString(16).padStart(4, '0')}`).value = '0000';
    }
}

function create_ibcm_memory_table() {
    str = "<table id=\"tbl\" BORDER=\"7\" width=\"98%\">\n";
    var top = 100;
    if (document.simulate.loadmem.checked)
        top = 4096;
    for (i = 0; i < top; i++) {
        const divname = i.toString(16).padStart(4, '0');
        str += "\n<tr><td>" + divname + "</td><td><input type=\"text\" id=\"v" + divname + "\" size=5></td><td><div id=\"pc" + divname + "\"></div></td></tr>";
    }
    str += "</table>";
    document.getElementById("memtable").innerHTML = str;
}

function init() {
    create_ibcm_memory_table();
    revert();
}
