#pragma once
#include <iostream>
#include "Data.h"
#include <SFML/Graphics.hpp>
using namespace std;

class figures: public Data {
public:
	vector<vector<string>> data = data_get();
	// ��������� �����
	static void Draw_all(sf::RenderWindow& window, Data& data);
	// ���� � ���������� ����� � ������ ������
	static void Add(string type, Data& data);
	// ������� �����
	static void Rotate(string type, int figure_index, Data& data);
};