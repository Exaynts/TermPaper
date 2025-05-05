#include "Line.h"

// Ввод данных линии
void Line::Add() {

    cout << "Coordinates of opposite peaks: " << endl;
    string x1, y1, x2, y2;
    cout << "x1 = ";
    x1 = to_string(Input_int());
    cout << "y1 = ";
    y1 = to_string(Input_int());
    cout << "x2 = ";
    x2 = to_string(Input_int());
    cout << "y2 = ";
    y2 = to_string(Input_int());
    data->Add("Line", "0", x1, y1, x2, y2);
    cout << "The index of new figure: " << data->Length() - 1 << endl;
}

// Отрисовка линии
void Line::Draw(sf::RenderWindow& window, int i) {
    int x1 = stoi(data->Get(i, 2));
    int y1 = stoi(data->Get(i, 3));
    int x2 = stoi(data->Get(i, 4));
    int y2 = stoi(data->Get(i, 5));
    sf::Color color = {
    static_cast<uint8_t>(stoi(data->Get(i, 6))), // Red
    static_cast<uint8_t>(stoi(data->Get(i, 7))), // Green
    static_cast<uint8_t>(stoi(data->Get(i, 8))) // Blue
    };
    std::array line = {
        sf::Vertex{sf::Vector2f(x1 / 1.0f, y1 / 1.0f), sf::Color(color)},
        sf::Vertex{sf::Vector2f(x2 / 1.0f, y2 / 1.0f), sf::Color(color)}

    };

    window.draw(line.data(), line.size(), sf::PrimitiveType::Lines);
}

// Поворот линии
void Line::Rotate(int figure_index) {
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
    // Вычисляем координаты новых точек при повороте вместо задания угла
    string new_x1 = to_string(int(round((x1 + x2) / 2 + b * pow(1 + a * a, -0.5))));
    string new_y1 = to_string(int(round((y1 + y2) / 2 + a * b * pow(1 + a * a, -0.5))));
    string new_x2 = to_string(int(round((x1 + x2) / 2 - b * pow(1 + a * a, -0.5))));
    string new_y2 = to_string(int(round((y1 + y2) / 2 - a * b * pow(1 + a * a, -0.5))));
    data->Set(figure_index, 2, new_x1);
    data->Set(figure_index, 3, new_y1);
    data->Set(figure_index, 4, new_x2);
    data->Set(figure_index, 5, new_y2);


}