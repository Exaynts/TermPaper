#pragma once
#include "figures.h"

class Rectangle : public figures {
public:
	// Ввод данных
	void Adding();
	// Поворот прямоугольника
	void Rotating(int figure_index);
	// Отрисовка
	void Draw(sf::RenderWindow& window, int i);
};