#include "Line.h"
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"

// Инициализация статического члена
Data* figures::data = nullptr;

// Отрисовка фигур
void figures::Draw_all(sf::RenderWindow& window) {
    for (int i = 0; i < data->Length(); i++) {
        if (data->Get(i, 0) == "Line") {
            Line::Draw(window, i);
        }
        else if (data->Get(i, 0) == "Square") {
            Square::Draw(window, i);
        }
        else if (data->Get(i, 0) == "Rectangle") {
            Rectangle::Draw(window, i);
        }
        else if (data->Get(i, 0) == "Circle") {
            Circle::Draw(window, i);
        }
        else
            cout << "TypeFigureError!" << endl;
    }
}

// Добавление фигур в список данных
void figures::Add(string type) {
    if (type == "Line") {
        Line::Add();
    }
    else if (type == "Square") {
        Square::Add();
    }
    else if (type == "Rectangle") {
        Rectangle::Add();
    }
    else if (type == "Circle") {
        Circle::Add();
    }
}

// Заменяем данные координат фигуры
void figures::Move(int figure_index, string type) {
    cout << "Horizontal movement (in pixels): " << endl;
    int h_movement = Input_any_int();
    string new_x1 = to_string(h_movement + stoi(data->Get(figure_index, 2))); // x1
    string new_x2 = to_string(h_movement + stoi(data->Get(figure_index, 4))); // x2
    data->Set(figure_index, 2, new_x1);
    data->Set(figure_index, 4, new_x2);
    cout << "Vertical movement (in pixels): " << endl;
    int v_movement = Input_any_int();
    string new_y1 = to_string(v_movement + stoi(data->Get(figure_index, 3))); // y1
    string new_y2 = to_string(v_movement + stoi(data->Get(figure_index, 5))); // y2
    data->Set(figure_index, 3, new_y1);
    data->Set(figure_index, 5, new_y2);
}

// Поворот фигур
void figures::Rotate(string type, int figure_index) {
    if (type == "Line") {
        Line::Rotate(figure_index);
    }
    else if (type == "Square") {
        Square::Rotate(figure_index);
    }
    else if (type == "Rectangle") {
        Rectangle::Rotate(figure_index);
    }
}

// Изменить размер фигуры
void figures::Resize(int figure_index) {
    cout << "Figure magnification factor (1.0 won't change the size): " << endl;
    float scale = Input_float();
    if (data->Get(figure_index, 0) != "Circle") {
        float x_center = (stoul(data->Get(figure_index, 2)) + stoul(data->Get(figure_index, 4))) / 2;
        float y_center = (stoul(data->Get(figure_index, 3)) + stoul(data->Get(figure_index, 5))) / 2;
        string new_x1 = to_string(int(round(x_center - scale * (x_center - stoul(data->Get(figure_index, 2))))));
        data->Set(figure_index, 2, new_x1);
        string new_y1 = to_string(int(round(y_center - scale * (y_center - stoul(data->Get(figure_index, 3))))));
        data->Set(figure_index, 3, new_y1);
        string new_x2 = to_string(int(round(x_center - scale * (x_center - stoul(data->Get(figure_index, 4))))));
        data->Set(figure_index, 4, new_x2);
        string new_y2 = to_string(int(round(y_center - scale * (y_center - stoul(data->Get(figure_index, 5))))));
        data->Set(figure_index, 5, new_y2);
    }
    else { // Circle
        string radius = to_string(int(round(scale * stoul(data->Get(figure_index, 1)))));
        data->Set(figure_index, 1, radius);
    }
}

// Перекрасить фигуру
void figures::Repaint(int figure_index) {
    cout << "Write three integers from 0 to 255 in GBR (Red, Green, Blue) format: " << endl;
    cout << "Red: ";
    int Red = Input_int();
    while (Red > 255) {
        cout << "Write number (0 <= number <= 255) correctly!" << endl;
        Red = Input_int();
    }
    cout << "Green: ";
    int Green = Input_int();
    while (Green > 255) {
        cout << "Write number (0 <= number <= 255) correctly!" << endl;
        Green = Input_int();
    }
    cout << "Blue: ";
    int Blue = Input_int();
    while (Blue > 255) {
        cout << "Write number (0 <= number <= 255) correctly!" << endl;
        Blue = Input_int();
    }
    data->Set(figure_index, 6, to_string(Red));
    data->Set(figure_index, 7, to_string(Green));
    data->Set(figure_index, 8, to_string(Blue));
}
