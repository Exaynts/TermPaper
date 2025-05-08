#pragma once
#include "figures.h"

class Line: public figures {
public:
	// Ввод данных
	void Adding();
	// Поворот линии
	void Rotating(int figure_index);
	// Отрисовка
	void Draw(sf::RenderWindow& window, int i);
};