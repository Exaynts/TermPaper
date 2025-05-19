#include <iostream>
#include <vector>
#include <string> // Для функций to_string() и stoi()
#include <math.h> // Для вычисления координат в функции Rotate()
#include <fstream> // Для сохранения файла

#include "Data.h"
#include "Menu.h"
#include "Shape.h"
#include "Line.h"
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"
#include "TypeFigure.h"
#include "Input.h"
#include "Load_data.h"
#include "Save_data.h"
#include "Init_data.h"

#include <SFML/Graphics.hpp>
using namespace std;

// Точка входа в программу
int main() {
    system("color F0"); // Цвет консоли (белый)
    // Инициализация базы данных
	Data* data = Init_data::Init();
    // Создание окна
    unsigned int width = 800;
    unsigned int height = 800;
    cout << "Creating window 800x800..." << endl;
    sf::RenderWindow window(sf::VideoMode({ width, height }), "Graphic redactor");
    window.setPosition(sf::Vector2i(10, 50));
    window.setPosition(sf::Vector2i(10, 50));
    // Программа работает, пока она открыта
    while (window.isOpen()) {
        while (const optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close(); 
        }
        window.clear(sf::Color::White);
        for (int i = 0; i < data->Length(); i++) {
            auto shape = TypeFigure::Type(data->Get(i, 0));
            shape->Draw(window, i);
        }
	    // Отображает окно
        window.display();
        // Главное меню
        if (!Menu::Main_Menu())
            window.close();
    }
    delete data;
	return 0;
}
