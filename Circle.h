#pragma once
#include "figures.h"

class Circle : public figures {
public:
	// ���� ������
	void Adding();
	// �������� ������ ������
	void Resizing(int figure_index) override;
	// ���������
	void Draw(sf::RenderWindow& window, int i);
};