#pragma once
#include "figures.h"
#include <fstream> // ��� �������� ����� � ������� Load()
using namespace std;
class Menu: public figures{
public:
    // ���� � ���������
    static Data Entrance();
    // ��������� ������ ����� � �����
    static bool Load(string file_path);
    // ������� ����
    static bool Main_menu();

    // ������� ������
    static void Create_figure();
    // ������� ������ (�� �������)
    static int Select_figure();
    // �������� ������
    static void Change_figure(int figure_index);

};