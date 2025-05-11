#pragma once
#include "Shape.h"

class Rectangle : public Shape {
protected:
	string name;
public:
	Rectangle() : name("Rectangle") {}
	const string& Get_Name() const { return name; }
	// Ввод данных
	void Adding();
	// Поворот прямоугольника
	void Rotating(int figure_index);
	// Отрисовка
	void Draw(sf::RenderWindow& window, int i);
};

extern Rectangle f_rectangle;