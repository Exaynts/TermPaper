#pragma once
#include "figures.h"

class Square : public figures {
public:
	// Ввод данных
	void Adding();
	// Поворот квадрата
	void Rotating(int figure_index);
	// Отрисовка
	void Draw(sf::RenderWindow& window, int i);
};