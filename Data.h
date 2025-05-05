#pragma once
#include <iostream>
#include <vector> // ��� ������� to_string() � stoi()
#include <string>
#include <math.h> // ��� ����������� ��������� � ������� Rotate()
#include <fstream> // ��� ���������� �����
#include <SFML/Graphics.hpp>
using namespace std;

class Data {
protected:
	int par; // ���������� ���������� � ������
	vector<vector<string>> data;
public:
	// ������� ������ ������ � �������
	Data();
	// ���������� �����
	int Length();
	// ������
	string Get(int i, int j);
	// ������
	void Set(int i, int j, string value);
	// ��������� ������ � ����� ������ �� ������ ����������
	void Add(string type, string ar, string x1, string y1, string x2, string y2);

	// ������� ������ � ������
	void Print_data(int figure_index);
	// ������� ������ � ���� �������
	void Print_all_data();
	// ��������� ������ � ������� � ��������� ����
	void Save_data();
	// ������� ������ � ������
	void Delete(int figure_index);
};

// ���������� ������������ ������ ������ ��������������� ����� �����
static int Input_int() {
	int input;
	while (!(cin >> input) or (cin.peek() != '\n') or input < 0) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Enter the number correctly!" << endl;
	}
	return input;
}

// ���������� ������������ ������ ������ ����� �����
static int Input_any_int() {
	int input;
	while (!(cin >> input) or (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Enter the number correctly!" << endl;
	}
	return input;
}

// ���������� ������������ ������ ������ ��������������� �������������� �����
static float Input_float() {
	float input;
	while (!(cin >> input) or (cin.peek() != '\n') or input < 0) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Enter the number correctly!" << endl;
	}
	return input;
}

