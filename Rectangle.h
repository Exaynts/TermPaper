#pragma once
#include "figures.h"

class Rectangle : public figures {
public:
	// Ввод данных
	static void Add(Data& data);
	// Поворот прямоугольника
	static void Rotate(int figure_index, Data& data);
	// Отрисовка
	static void Draw(sf::RenderWindow& window, Data data, int i);
};