#pragma once
#include "Shape.h"

class Square : public Shape {
protected:
	string name;
public:
	Square() : name("Square") {}
	const string& Get_Name() const { return name; }
	// Ввод данных
	void Adding();
	// Поворот квадрата
	void Rotating(int figure_index);
	// Отрисовка
	void Draw(sf::RenderWindow& window, int i);
};

extern Square f_square;