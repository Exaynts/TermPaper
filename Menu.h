#pragma once
#include "figures.h"
#include <fstream> // Для загрузки файла в функции Load()
using namespace std;
class Menu {
public:
    // Вход в программу
    static Data Entrance();
    // Загрузить данные фигур с файла
    static bool Load(string file_path, Data& data);
    // Главное меню
    static bool Main_menu(Data& data);

    // Создать фигуру
    static void Create_figure(Data& data);
    // Выбрать фигуру (по индексу)
    static int Select_figure(Data& data);
    // Изменить фигуру
    static void Change_figure(int figure_index, Data& data);
};