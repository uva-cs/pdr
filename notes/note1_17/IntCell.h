#ifndef INTCELL_H
#define INTCELL_H

class IntCell {
	//Visibility block
	public:
		IntCell(int initialValue = 0);

		int getValue() const;
		void setValue(int val);

	private:
		int storedValue;
		int max(int m) const;
};

#endif // INTCELL_H