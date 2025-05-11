#pragma once
#include "Shape.h"

class Circle : public Shape {
protected:
	string name;
public:
	Circle() : name("Circle") {}
	const string& Get_Name() const { return name; }
	// Ввод данных
	void Adding();
	// Изменить размер фигуры
	void Resizing(int figure_index) override;
	// Отрисовка
	void Draw(sf::RenderWindow& window, int i);

	void Rotating(int figure_index) {}
};

extern Circle f_circle;