#include "Menu.h"

//vector<Shape*> func_list = { &f_line, &f_square, &f_rectangle, &f_circle };
// Точка входа программы
int main() {
    // Инициализация базы данных
	Data data = Menu::Entrance();
    Shape::Set_data(&data);
    // Создание окна
    unsigned int width = 800;
    unsigned int height = 800;
    sf::RenderWindow window(sf::VideoMode({ width, height }), "Graphic redactor");
    window.setPosition(sf::Vector2i(10, 50));
    // Программа работает, пока она открыта
    while (window.isOpen()) {
        while (const optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close(); 
        }
        window.clear(); 
        for (int i = 0; i < data.Length(); i++) {
            auto shape = TypeFigure::Type(data.Get(i, 0));
            shape->Draw(window, i);
        }
        // Заканчиваем текущую рамку
        window.display();
        // Главное меню
        if (!Menu::Main_menu())
            window.close();
    }
	return 0;
}
