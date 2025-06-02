#include "Input.h"

// Ââîä íåîòðèöàòåëüíîãî öåëîãî ÷èñëà, íå ïðåâûøàþùåå max (ïî óìîë÷àíèþ 65535). Àðãóìåíò "!0" äîïîëèòåëüíî îòñåêàåò ÷èñëî íîëü
int Input::Input_natural0(string iszero, int max) {
	int begin = 0; // Ïðîâåðêà íà èñêëþ÷åíèå íóëÿ
	if (iszero == "!0")
		begin = 1;

	int input;
	while (!(cin >> input) or (cin.peek() != '\n') or (input < 0) or (input == begin - 1) or (input > max)) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Error (must be number from " << begin << " to " << max << "):" << endl;
	}
	cin.ignore();
	return input;
}

// Ââîä öåëîãî ÷èñëà
int Input::Input_any_int() {
	int input;
	while (!(cin >> input) or (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Enter the number correctly!" << endl;
	}
	cin.ignore();
	return input;
}

// Ââîä íåîòðèöàòåëüíîãî äåéñòâèòåëüíîãî ÷èñëà
double Input::Input_pos_double() {
	double input;
	while (!(cin >> input) or (cin.peek() != '\n') or input < 0) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Enter the number correctly!" << endl;
	}
	cin.ignore();
	return input;
}
