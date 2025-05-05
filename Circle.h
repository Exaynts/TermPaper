#pragma once
#include "figures.h"

class Circle : public figures {
public:
	// Ввод данных
	static void Add();
	// Изменить размер фигуры
	void Resize(int figure_index) override;
	// Отрисовка
	static void Draw(sf::RenderWindow& window, int i);
};