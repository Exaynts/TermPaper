#pragma once
#include "Data.h"
#include "Input.h"

class Shape {
protected:
	// Статический указатель на данные, общие для всех фигур
	static Data* data;
public:
	static Data* Set_data(Data* new_data) { return data = new_data; };
	// Ввести и добавить фигуру в список данных
	virtual const string& Get_Name() const { return "0"; };
	virtual void Adding() = 0;
	// Заменить данные координат фигуры
	void Moving(int figure_index);
	// Поворот фигур
	virtual void Rotating(int figure_index) = 0;
	// Изменить размер фигуры
	virtual void Resizing(int figure_index);
	// Перекрасить фигуру
	void Repainting(int figure_index);
	// Вывод фигуры на экран
	virtual void Draw(sf::RenderWindow& window, int i) = 0;
};
