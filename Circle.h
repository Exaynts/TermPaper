#pragma once
#include "figures.h"

class Circle : public figures {
public:
	// ¬вод данных
	static void Add(Data& data);
	// ќтрисовка
	static void Draw(sf::RenderWindow& window, Data data, int i);
};