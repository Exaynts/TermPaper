#include "Circle.h"

// Ввод данных круга
void Circle::Add() {
    string radius, x, y;
    cout << "radius = ";
    radius = to_string(Input_int());
    cout << "x = ";
    x = to_string(Input_int());
    cout << "y = ";
    y = to_string(Input_int());
    data->Add("Circle", radius, x, y, "0", "0");
    cout << "The index of new figure: " << data->Length() - 1 << endl;
}

// Отрисовка круга
void Circle::Draw(sf::RenderWindow& window, int i) {
    sf::CircleShape circle(0.0f);
    circle.setRadius(stoi(data->Get(i, 1)) / 1.0f);
    int radius = stoi(data->Get(i, 1));
    int x = stoi(data->Get(i, 2)) - radius;
    int y = stoi(data->Get(i, 3)) - radius;
    circle.setPosition({ x / 1.0f, y / 1.0f });
    sf::Color color = {
    static_cast<uint8_t>(stoi(data->Get(i, 6))), // Red
    static_cast<uint8_t>(stoi(data->Get(i, 7))), // Green
    static_cast<uint8_t>(stoi(data->Get(i, 8))) // Blue
    };
    circle.setFillColor(color);
    window.draw(circle);
}

// Изменить размер фигуры
void Circle::Resize(int figure_index) {
    cout << "Figure magnification factor (1.0 won't change the size): " << endl;
    float scale = Input_float();
    string radius = to_string(int(round(scale * stoul(data->Get(figure_index, 1)))));
    data->Set(figure_index, 1, radius);
}