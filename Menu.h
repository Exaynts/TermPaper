#pragma once
#include "Shape.h"
#include "Typefigure.h"
#include "Load_data.h"
#include "Save_data.h"
#include "Init_data.h"
#include <vector>

using namespace std;

class Menu {
private:
    // Вектор-список типов фигур
    vector<Shape*> ptype;
    // Статический указатель на список фигур
    static Data* data;
public:
    // Сеттер указателя на список фигур
    static void Set_data(Data* d) { data = d; };

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
