#pragma once
#include "Data.h"

class figures: public Data {
protected:
	// ����������� ��������� �� ������, ����� ��� ���� �����
	static Data* data;
public:
	// ������������� ������
	static void Init(Data& dataRef) {data = &dataRef;}

	// ��������� �����
	static void Draw_all(sf::RenderWindow& window);

	// ���� � ���������� ����� � ������ ������
	void Add(string type);
	// �������� ������ ��������� ������
	void Move(int figure_index, string type);
	// ������� �����
	void Rotate(string type, int figure_index);
	// �������� ������ ������
	virtual void Resize(int figure_index);
	// ����������� ������
	void Repaint(int figure_index);
};