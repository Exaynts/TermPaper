#pragma once
#include "figures.h"
#include <fstream> // ��� �������� ����� � ������� Load()
using namespace std;
class Menu {
public:
    // ���� � ���������
    static Data Entrance();
    // ��������� ������ ����� � �����
    static bool Load(string file_path, Data& data);
    // ������� ����
    static bool Main_menu(Data& data);

    // ������� ������
    static void Create_figure(Data& data);
    // ������� ������ (�� �������)
    static int Select_figure(Data& data);
    // �������� ������
    static void Change_figure(int figure_index, Data& data);
};