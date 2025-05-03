#include "Data.h"
using namespace std;

/* Структура:
[[фигура.0], [фигура.1], ... [фигура.длина_списка-1)]]
[фигура.i] это список из нескольких строк:
[тип, angle/radius, x1, y1, x2, y2, Red_color, Green_color, Blue_color]
Неопределяемые для какого-то типа фигуры значения будут добавляться, как "0" и не должны вызываться
*/


// Создаем список данных о фигурах
Data::Data() {
    par = 9; // Количество параметров у фигуры
	data = vector<vector<string>> (0, vector <string>(par));
}
// Количество фигур
int Data::Length() {
    return size(data);
}
// Геттеры
string Data::Get(int i, int j) {
    return data[i][j];
}
vector<vector<string>> Data::data_get() {
    return data;
}
// Сеттер
void Data::Set(int i, int j, string value) {
    data[i][j] = value;
}

// Добавляем данные о новой фигуре
void Data::Add(string type, string ar, string x1, string y1, string x2, string y2) {
    vector<string> figure{type, ar, x1, y1, x2, y2, "255", "255", "255"};
    data.push_back(figure);
}

// Заменяем данные координат о фигуре
void Data::Move(int figure_index, string type) {
	cout << "Horizontal movement (in pixels): " << endl;
    int h_movement = Input_any_int();
    data[figure_index][2] = to_string(h_movement + stoi(data[figure_index][2])); // x1
    data[figure_index][4] = to_string(h_movement + stoi(data[figure_index][4])); // x2
	cout << "Vertical movement (in pixels): " << endl;
    int v_movement = Input_any_int();
    data[figure_index][3] = to_string(v_movement + stoi(data[figure_index][3])); // y1
    data[figure_index][5] = to_string(v_movement + stoi(data[figure_index][5])); // y2
}
// Заменяем данные о повороте фигуры
void Data::Rotate(int figure_index) {
    cout << "Rotate the figure clockwise (in degrees): " << endl;
    int angle = Input_any_int();

    float x1 = float(stoi(data[figure_index][2]));
    float y1 = float(stoi(data[figure_index][3]));
    float x2 = float(stoi(data[figure_index][4]));
    float y2 = float(stoi(data[figure_index][5]));
    float a;
    if (x2 == x1)
        a = tan(3.141592 / 2 + angle * 3.141592 / 180.0);
    else
        a = tan(atan((y2 - y1) / (x2 - x1)) + angle * 3.141592 / 180.0);
    float b = pow(((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)), 0.5) / 2;

    if (data[figure_index][0] == "Square" or data[figure_index][0] == "Rectangle") {
        int new_angle = (angle + stoi(data[figure_index][1])) % 360;

        if (new_angle < 0) // Обрабатываем случай поворота против часовой стрелки
            new_angle += 360;
        data[figure_index][1] = to_string(new_angle); // angle
    }
    else if (data[figure_index][0] == "Line") { // Вычисляем координаты новых точек при повороте вместо задания угла
        string new_x1 = to_string(int(round((x1 + x2) / 2 + b * pow(1 + a * a, -0.5))));
        string new_y1 = to_string(int(round((y1 + y2) / 2 + a * b * pow(1 + a * a, -0.5))));
        string new_x2 = to_string(int(round((x1 + x2) / 2 - b * pow(1 + a * a, -0.5))));
        string new_y2 = to_string(int(round((y1 + y2) / 2 - a * b * pow(1 + a * a, -0.5))));
        data[figure_index][2] = new_x1;
        data[figure_index][3] = new_y1;
        data[figure_index][4] = new_x2;
        data[figure_index][5] = new_y2;
    }
}

// Изменить размер фигуры
void Data::Resize(int figure_index) {
    cout << "Figure magnification factor (1.0 won't change the size): " << endl;
    float scale = Input_float();
    if (data[figure_index][0] != "Circle") {
        float x_center = (stoul(data[figure_index][2]) + stoul(data[figure_index][4])) / 2;
        float y_center = (stoul(data[figure_index][3]) + stoul(data[figure_index][5])) / 2;
        data[figure_index][2] = to_string(int(round(x_center - scale * (x_center - stoul(data[figure_index][2])))));
        data[figure_index][3] = to_string(int(round(y_center - scale * (y_center - stoul(data[figure_index][3])))));
        data[figure_index][4] = to_string(int(round(x_center - scale * (x_center - stoul(data[figure_index][4])))));
        data[figure_index][5] = to_string(int(round(y_center - scale * (y_center - stoul(data[figure_index][5])))));
    }
    else { // Circle
        data[figure_index][1] = to_string(scale*stoul(data[figure_index][1]));
    }
}

// Перекрасить фигуру
void Data::Repaint(int figure_index) {
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
    data[figure_index][6] = to_string(Red);
    data[figure_index][7] = to_string(Green);
    data[figure_index][8] = to_string(Blue);
}

// Вывести данные о фигуре
void Data::Print_data(int figure_index) {
    cout << "[type, angle/radius, x1, y1, x2, y2, Red_color, Green_color, Blue_color]" << endl;
    cout << "[ ";
    for (int i = 0; i < par; i++) {
        cout << data[figure_index][i] << " ";
    }
    cout << "]" << endl;
}

// Вывести данные о всех фигурах
void Data::Print_all_data() {
    cout << "[type, angle/radius, x1, y1, x2, y2, Red_color, Green_color, Blue_color]" << endl;
    for (int i = 0; i < Length(); i++) {
        cout << "[ ";
        for (int j = 0; j < par; j++) {
            cout << data[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

// Сохранить данные о фигурах в отдельный файл
void Data::Save_data() {
    cout << "Enter the name the file will have. Use only Latin letters, numbers and sign \"_\"!" << endl;
    string filename;
    cin >> filename;
    ofstream file(filename + ".txt");
    if (!file.is_open()) {
        cerr << "The file can not be created" << endl;
    }
    else {
        for (int i = 0; i < Length(); i++) {
            for (int j = 0; j < par; j++) {
                file << data[i][j] << " ";
            }
            cout << endl;
        }
        file.close();
        cout << "The file was saved with the name \"" << filename << ".txt\"" << endl;
    }
}

// Удаляем данные о фигуре
void Data::Delete(int figure_index) {
    cout << "After deleting the element with index[i], the indices of all the following elements in the list decreased by one" << endl;
    data.erase(data.begin() + figure_index);
}