#include "Shape.h"

Data* Shape::data = nullptr;

// Заменяем данные координат фигуры
void Shape::Moving(int figure_index) {
    cout << "Horizontal movement (in pixels): " << endl;
    int h_movement = Input::Input_any_int();
    string new_x1 = to_string(h_movement + stoi(data->Get(figure_index, 2))); // x1
    string new_x2 = to_string(h_movement + stoi(data->Get(figure_index, 4))); // x2
    data->Set(figure_index, 2, new_x1);
    data->Set(figure_index, 4, new_x2);
    cout << "Vertical movement (in pixels): " << endl;
    int v_movement = Input::Input_any_int();
    string new_y1 = to_string(v_movement + stoi(data->Get(figure_index, 3))); // y1
    string new_y2 = to_string(v_movement + stoi(data->Get(figure_index, 5))); // y2
    data->Set(figure_index, 3, new_y1);
    data->Set(figure_index, 5, new_y2);
}

// Изменить размер фигуры
void Shape::Resizing(int figure_index) {
    cout << "Figure magnification factor (1.0 won't change the size): " << endl;
    float scale = Input::Input_pos_float();
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
void Shape::Repainting(int figure_index) {
    cout << "Write three integers from 0 to 255 in RGB (Red, Green, Blue) format: " << endl;
    cout << "Red: ";
    int Red = Input::Input_natural0("0", 255);
    cout << "Green: ";
    int Green = Input::Input_natural0("0", 255);
    cout << "Blue: ";
    int Blue = Input::Input_natural0("0", 255);

    data->Set(figure_index, 6, to_string(Red));
    data->Set(figure_index, 7, to_string(Green));
    data->Set(figure_index, 8, to_string(Blue));
}
