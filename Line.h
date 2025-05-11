#pragma once
#include "Shape.h"

class Line: public Shape {
protected:
	string name;
public:
	Line() : name("Line") {}
	const string& Get_Name() const { return name; }
	// Ввод данных
	void Adding();
	// Поворот линии
	void Rotating(int figure_index);
	// Отрисовка
	void Draw(sf::RenderWindow& window, int i);
};

extern Line f_line;