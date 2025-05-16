#include "Input.h"

// Ввод неотрицательного целого числа, не превышающее max (по умолчанию 65535). Аргумент "!0" дополительно отсекает число ноль
int Input::Input_natural0(string iszero, int max) {
	int begin = 0; // Проверка на исключение нуля
	if (iszero == "!0")
		begin = 1;

	int input;
	while (!(cin >> input) or (cin.peek() != '\n') or (input < 0) or (input == begin - 1) or (input > max)) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Error (must be number from " << begin << " to " << max << "):" << endl;
	}
	return input;
}

// Ввод целого числа
int Input::Input_any_int() {
	int input;
	while (!(cin >> input) or (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Enter the number correctly!" << endl;
	}
	return input;
}

// Ввод неотрицательного действительного числа
float Input::Input_pos_float() {
	float input;
	while (!(cin >> input) or (cin.peek() != '\n') or input < 0) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Enter the number correctly!" << endl;
	}
	return input;
}
