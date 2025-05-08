#pragma once
#include "Data.h"
#include <memory>

/*
������:
Do_something () � ������� ������ ������ � ������� �������� �������
DoING_something () � ���������� �������� �������, ��� ���������� ������ ���������� ����������� ������ � ������������ ������
*/

class figures: public Data {
protected:
	// ����������� ��������� �� ������, ����� ��� ���� �����
	static Data* data;
public:
	// ������������� ������
	static void Init(Data& dataRef) {data = &dataRef;}
	// ����������� ���� ������
	static unique_ptr<figures> TypeFigure(const string& type);

	// ��������� �����
	static void Draw_all(sf::RenderWindow& window);
	virtual void Draw(sf::RenderWindow& window, int i);

	// ������ � �������� ������ � ������ ������
	void Add(string type);
	virtual void Adding();
	// �������� ������ ��������� ������
	void Moving(int figure_index, string type);
	// ������� �����
	void Rotate(string type, int figure_index);
	virtual void Rotating(int figure_index);
	// �������� ������ ������
	void Resize(int figure_index, string type);
	virtual void Resizing(int figure_index);
	// ����������� ������
	void Repainting(int figure_index);
};