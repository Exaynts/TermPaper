#pragma once
#include "figures.h"

class Rectangle : public figures {
public:
	// Ввод данных
	static void Add();
	// Поворот прямоугольника
	static void Rotate(int figure_index);
	// Отрисовка
	static void Draw(sf::RenderWindow& window, int i);
};