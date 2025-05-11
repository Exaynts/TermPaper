#pragma once
#include "Shape.h"
#include "Typefigure.h"
#include <fstream> // Для загрузки файла в функции Load()
using namespace std;
class Menu {
protected:
    // Статический указатель на данные, общие для всех фигур
    static Data* data;
public:
    // Вход в программу
    static Data Entrance();
    // Загрузить данные фигур с файла
    static bool Load(string file_path);
    // Главное меню
    static bool Main_menu();

    // Создать фигуру
    static void Create_figure();
    // Выбрать фигуру (по индексу)
    static int Select_figure();
    // Изменить фигуру
    static void Change_figure(int figure_index);

};