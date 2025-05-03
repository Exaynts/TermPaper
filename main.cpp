#include "Menu.h"

// Точка входа программы
int main() {
    // Инициализация базы данных
	Data data = Menu::Entrance();
    // Создание окна
    unsigned int width = 1000;
    unsigned int height = 1000;
    sf::RenderWindow window(sf::VideoMode({ width, height }), "Graphic redactor");
    window.setPosition(sf::Vector2i(10, 50));
    // Программа работает, пока она открыта
    while (window.isOpen()) {
        while (const optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close(); 
        }
        window.clear(); 
        figures::Draw_all(window, data);
        // Заканчиваем текущую рамку
        window.display();
        // Главное меню
        if (Menu::Main_menu(data) == false)
            window.close();
    }
	return 0;
}
