#pragma once
#include "figures.h"

class Circle : public figures {
public:
	// ���� ������
	static void Add();
	// �������� ������ ������
	void Resize(int figure_index) override;
	// ���������
	static void Draw(sf::RenderWindow& window, int i);
};