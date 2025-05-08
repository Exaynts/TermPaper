#pragma once
#include "figures.h"

class Circle : public figures {
public:
	// Ввод данных
	void Adding();
	// Изменить размер фигуры
	void Resizing(int figure_index) override;
	// Отрисовка
	void Draw(sf::RenderWindow& window, int i);
};