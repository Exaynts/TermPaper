#pragma once
#include "figures.h"

class Square : public figures {
public:
	// ���� ������
	void Adding();
	// ������� ��������
	void Rotating(int figure_index);
	// ���������
	void Draw(sf::RenderWindow& window, int i);
};