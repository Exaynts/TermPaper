#pragma once
#include "figures.h"

class Rectangle : public figures {
public:
	// ���� ������
	static void Add();
	// ������� ��������������
	static void Rotate(int figure_index);
	// ���������
	static void Draw(sf::RenderWindow& window, int i);
};