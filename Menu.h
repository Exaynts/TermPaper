#pragma once
#include "Shape.h"
#include "Typefigure.h"
#include <fstream> // Для Load()
#include <vector>

using namespace std;

class Menu {
private:
    vector<Shape*> ptype;
protected:
    // 
    // Статический указатель на данные, общие для всех фигур
    static Data* data;
public:
    // Вход в программу
    static Data* Entrance();
    // Загрузить данные фигур с файла
    static bool Load(string& file_path);
    // Главное меню
    static bool Main_Menu();

    // Создать фигуру
    static void Create_figure();
    // Выбрать фигуру (по индексу)
    static int Select_figure();
    // Изменить фигуру
    static void Change_figure(int figure_index);
    Menu(vector<Shape*> _ptype) : ptype(_ptype) {}
    // Выбор типа фигуры
    Shape* Select_Type() const;
};
