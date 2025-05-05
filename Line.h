#pragma once
#include "figures.h"

class Line: public figures {
public:
	// Ввод данных
	static void Add();
	// Поворот линии
	static void Rotate(int figure_index);
	// Отрисовка
	static void Draw(sf::RenderWindow& window, int i);
};