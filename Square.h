#pragma once
#include "figures.h"

class Square : public figures {
public:
	// Ввод данных
	static void Add();
	// Поворот квадрата
	static void Rotate(int figure_index);
	// Отрисовка
	static void Draw(sf::RenderWindow& window, int i);
};