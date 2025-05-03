#include "Line.h"
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"

// Отрисовка фигур
void figures::Draw_all(sf::RenderWindow& window, Data& data) {
    //vector<vector<string>> data = data_get();
    for (int i = 0; i < data.Length(); i++) {
        if (data.Get(i, 0) == "Line") {
            Line::Draw(window, data, i);
        }
        else if (data.Get(i, 0) == "Square") {
            Square::Draw(window, data, i);
        }
        else if (data.Get(i, 0) == "Rectangle") {
            Rectangle::Draw(window, data, i);
        }
        else if (data.Get(i, 0) == "Circle") {
            Circle::Draw(window, data, i);
        }
        else
            cout << "TypeFigureError!" << endl;
    }
}

// Добавление фигур в список данных
void figures::Add(string type, Data& data) {
    if (type == "Line") {
        Line::Add(data);
    }
    else if (type == "Square") {
        Square::Add(data);
    }
    else if (type == "Rectangle") {
        Rectangle::Add(data);
    }
    else if (type == "Circle") {
        Circle::Add(data);
    }
}

// Поворот фигур
void figures::Rotate(string type, int figure_index, Data& data) {
    if (type == "Line") {
        Line::Rotate(figure_index, data);
    }
    else if (type == "Square") {
        Square::Rotate(figure_index, data);
    }
    else if (type == "Rectangle") {
        Rectangle::Rotate(figure_index, data);
    }
}
