#include "Square.h"

// Ввод данных квадрата
void Square::Add() {
    cout << "coordinates of upper left corner: " << endl;
    string x1, y1, side_length, x2, y2;
    cout << "x = ";
    x1 = to_string(Input_int());
    cout << "y = ";
    y1 = to_string(Input_int());
    cout << "side length = ";
    side_length = to_string(Input_int());
    x2 = to_string(stoi(x1) + stoi(side_length)); // Вычисляем x2
    y2 = to_string(stoi(y1) + stoi(side_length)); // Вычисляем y2
    data->Add("Square", "0", x1, y1, x2, y2);
    cout << "The index of new figure: " << data->Length() - 1 << endl;
}

// Отрисовка квадрата
void Square::Draw(sf::RenderWindow& window, int i) {
    int x = (stoi(data->Get(i, 2)) + stoi(data->Get(i, 4))) / 2;
    int y = (stoi(data->Get(i, 3)) + stoi(data->Get(i, 5))) / 2;
    int width = stoi(data->Get(i, 4)) - stoi(data->Get(i, 2));
    int height = stoi(data->Get(i, 5)) - stoi(data->Get(i, 3));
    int angle = stoi(data->Get(i, 1));
    sf::RectangleShape square({ width / 1.0f, height / 1.0f });
    square.setPosition({ x / 1.0f, y / 1.0f });
    square.setOrigin({ width / 2.0f, height / 2.0f });
    square.rotate(sf::degrees(angle));
    sf::Color color = {
    static_cast<uint8_t>(stoi(data->Get(i, 6))), // Red
    static_cast<uint8_t>(stoi(data->Get(i, 7))), // Green
    static_cast<uint8_t>(stoi(data->Get(i, 8))) // Blue
    };
    square.setFillColor(color);
    window.draw(square);
}

// Поворот квадрата
void Square::Rotate(int figure_index) {
    cout << "Rotate the figure clockwise (in degrees): " << endl;
    int angle = Input_any_int();

    float x1 = float(stoi(data->Get(figure_index, 2)));
    float y1 = float(stoi(data->Get(figure_index, 3)));
    float x2 = float(stoi(data->Get(figure_index, 4)));
    float y2 = float(stoi(data->Get(figure_index, 5)));
    float a;
    if (x2 == x1)
        a = tan(3.141592 / 2 + angle * 3.141592 / 180.0);
    else
        a = tan(atan((y2 - y1) / (x2 - x1)) + angle * 3.141592 / 180.0);
    float b = pow(((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)), 0.5) / 2;

    int new_angle = (angle + stoi(data->Get(figure_index, 1))) % 360;

    if (new_angle < 0) // Обрабатываем случай поворота против часовой стрелки
        new_angle += 360;
    data->Set(figure_index, 1, to_string(new_angle)); // angle
}