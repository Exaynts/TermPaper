#pragma once
#include "figures.h"

class Circle : public figures {
public:
	// ���� ������
	static void Add(Data& data);
	// ���������
	static void Draw(sf::RenderWindow& window, Data data, int i);
};