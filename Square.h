#pragma once
#include "figures.h"

class Square : public figures {
public:
	// ���� ������
	static void Add(Data& data);
	// ������� ��������
	static void Rotate(int figure_index, Data& data);
	// ���������
	static void Draw(sf::RenderWindow& window, Data data, int i);
};