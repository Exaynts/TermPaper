#pragma once
#include <iostream>
#include <vector>
#include <string> // Для функций to_string() и stoi()
#include <math.h> // Для вычисления координат в функции Rotate()
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
	void Add(string type = "Unknown", string ar = "0", string x1 = "0", string y1 = "0", string x2 = "0", string y2 = "0", string r_color = "255", string g_color = "255", string b_color = "255");

	// Вывести данные о фигуре
	void Print_data(int figure_index);
	// Вывести данные о всех фигурах
	void Print_all_data();
	// Сохранить данные о фигурах в отдельный файл
	void Save_data();
	// Удаляем данные о фигуре
	void Delete(int figure_index);
};