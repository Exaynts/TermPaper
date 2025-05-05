#pragma once
#include <iostream>
#include <vector> // Для функций to_string() и stoi()
#include <string>
#include <math.h> // Для выичисления координат в функции Rotate()
#include <fstream> // Для сохранения файла
#include <SFML/Graphics.hpp>
using namespace std;

class Data {
protected:
	int par; // Количество параметров у фигуры
	vector<vector<string>> data;
public:
	// Создаем список данных о фигурах
	Data();
	// Количество фигур
	int Length();
	// Геттер
	string Get(int i, int j);
	// Сеттер
	void Set(int i, int j, string value);
	// Добавляем данные о новой фигуре по списку аргументов
	void Add(string type, string ar, string x1, string y1, string x2, string y2);

	// Вывести данные о фигуре
	void Print_data(int figure_index);
	// Вывести данные о всех фигурах
	void Print_all_data();
	// Сохранить данные о фигурах в отдельный файл
	void Save_data();
	// Удаляем данные о фигуре
	void Delete(int figure_index);
};

// Заставляем пользователя ввести именно неотрицательное целое число
static int Input_int() {
	int input;
	while (!(cin >> input) or (cin.peek() != '\n') or input < 0) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Enter the number correctly!" << endl;
	}
	return input;
}

// Заставляем пользователя ввести именно целое число
static int Input_any_int() {
	int input;
	while (!(cin >> input) or (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Enter the number correctly!" << endl;
	}
	return input;
}

// Заставляем пользователя ввести именно неотрицательное действительное число
static float Input_float() {
	float input;
	while (!(cin >> input) or (cin.peek() != '\n') or input < 0) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Enter the number correctly!" << endl;
	}
	return input;
}

