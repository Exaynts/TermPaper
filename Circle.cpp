#include "Circle.h"
#include "iostream"
#include "string"
using namespace std;

// ¬вод данных круга
void Circle::Add(Data& data) {
    string radius, x, y;
    cout << "radius = ";
    radius = to_string(Input_int());
    cout << "x = ";
    x = to_string(Input_int() - stoi(radius));
    cout << "y = ";
    y = to_string(Input_int() - stoi(radius));
    data.Add("Circle", radius, x, y, "0", "0");
    cout << "The index of new figure: " << data.Length() - 1 << endl;
}

// ќтрисовка круга
void Circle::Draw(sf::RenderWindow& window, Data data, int i) {
    sf::CircleShape circle(0.0f);
    circle.setRadius(stoi(data.Get(i, 1)) / 1.0f);
    int x = stoi(data.Get(i, 2));
    int y = stoi(data.Get(i, 3));
    circle.setPosition({ x / 1.0f, y / 1.0f });
    sf::Color color = {
    static_cast<uint8_t>(stoi(data.Get(i, 6))), // Red
    static_cast<uint8_t>(stoi(data.Get(i, 7))), // Green
    static_cast<uint8_t>(stoi(data.Get(i, 8))) // Blue
    };
    circle.setFillColor(color);
    window.draw(circle);
}