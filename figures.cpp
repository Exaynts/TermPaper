#include "Line.h"
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"

// Инициализация статического члена
Data* figures::data = nullptr;
// Определение типа фигуры
unique_ptr<figures> figures::TypeFigure(const string& type) {
    if (type == "Line") {
        return make_unique<Line>();
    }
    else if (type == "Square") {
        return make_unique<Square>();
    }
    else if (type == "Rectangle") {
        return make_unique<Rectangle>();
    }
    else if (type == "Circle") {
        return make_unique<Circle>();
    }
    else {
        throw invalid_argument("Unknown TypeFigure");
    }
}

// Отрисовка фигур
void figures::Draw_all(sf::RenderWindow& window) {
    for (int i = 0; i < data->Length(); i++) {
        auto figure = TypeFigure(data->Get(i, 0));
        figure->Draw(window, i);
    }
}
void figures::Draw(sf::RenderWindow& window, int i) {}

// Ввести и добавить фигуру в список данных
void figures::Add(string type) {
    auto figure = TypeFigure(type);
    figure->Adding();
}
void figures::Adding() {}

// Заменяем данные координат фигуры
void figures::Moving(int figure_index, string type) {
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
    auto figure = TypeFigure(type);
    figure->Rotating(figure_index);
}
void figures::Rotating(int figure_index) {}

// Изменить размер фигуры
void figures::Resize(int figure_index, string type) {
    auto figure = TypeFigure(type);
    figure->Resizing(figure_index);
}
void figures::Resizing(int figure_index) {
    cout << "Figure magnification factor (1.0 won't change the size): " << endl;
    float scale = Input_float();
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

// Перекрасить фигуру
void figures::Repainting(int figure_index) {
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