#include "Menu.h"
using namespace std;

// Вход в программу
Data Menu::Entrance() {
    // Определение списка данных по умолчанию
    Data data = Data();
    string function = "";
    while (true) {
        cout << "Create or load picture?" << endl;
        cout << "(Create, Load)" << endl;
        cin >> function;
        // Оставляем всё, как есть
        if (function == "Create") {
            break;
        }
        // Заполняем список данными из файла
        else if (function == "Load") {
            cout << "Enter the path to the data file: " << endl;
            string file_path = "";
            cin >> file_path;
            // Пока не загрузятся данные
            while (Load(file_path, data) == false) {
                cin >> file_path;
            }
            break;
        }
        else
            cout << "Enter the text correctly!" << endl;
    }
    return data;
}

// Загрузить данные фигур с файла
bool Menu::Load(string file_path, Data& data) {
    ifstream file(file_path);
    if (file_path == "break")
        return true;
    else if (!file.is_open()) {
        cerr << "The file was not found. To create an empty data list, write \"break\"." << endl;
        return false;
    }
    else {
        string type, ar, x1, y1, x2, y2;
        vector <string> data_i;
        while (file >> type >> ar >> x1 >> y1 >> x2 >> y2) {
            data.Add(type, ar, x1, y1, x2, y2);
        }
        file.close();
    }
    return true;
}

// Главное меню
bool Menu::Main_menu(Data& data) {
    string function = "";
    while (function != "Create" and function != "Select") {
        cout << "Select one of the following fuctions for a figure:" << endl;
        cout << "(Create, Select, Print_data, Save_data, Exit)" << endl;
        cin >> function;
        if (function == "Create") {
            Menu::Create_figure(data);
        }
        else if (function == "Select") {
            int figure_index = Menu::Select_figure(data);
            data.Print_data(figure_index);
            Menu::Change_figure(figure_index, data);
        }
        else if (function == "Print_data") {
            data.Print_all_data();
        }
        else if (function == "Save_data") {
            data.Save_data();
        }
        else if (function == "Exit") {
            return false;
        }
        else
            cout << "Enter function's name correctly!" << endl;
    }
    return true;
}

// Создать фигуру
void Menu::Create_figure(Data& data) {
    // Выбираем тип фигуры
    string type;    
    while (true) {
        cout << "Choose type of your figure:" << endl;
        cout << "(Line, Square, Rectangle, Circle)" << endl;
        cin >> type;
        if (type == "Line" or type == "Square" or type == "Rectangle" or type == "Circle") {
            figures::Add(type, data);
            break;
        }
        else
            cout << "Enter the type correctly!" << endl;
    }
}

// Выбрать фигуру (по индексу)
int Menu::Select_figure(Data& data) {
    if (data.Length() == 0) // Если список фигур пуст, создаём фигуру
        Create_figure(data);
    cout << "Write index of your figure " << "(max index = " << data.Length() - 1 << "): ";
    int figure_index = -1;
    while (figure_index < 0 or figure_index >= data.Length()) {
        figure_index = Input_int();
        if (figure_index >= data.Length())
            cout << "This number is too high!" << endl;
    }
    return figure_index;
}
// Изменить фигуру
void Menu::Change_figure(int figure_index, Data& data) {
    while (true) {
        string function;
        cout << "Select one of the following fuctions:" << endl;
        cout << "(Move, Rotate, Resize, Print_data, Repaint, Cancel, Delete)" << endl;
        cin >> function;
        if (function == "Move") {
            string type = data.Get(figure_index, 0);
            data.Move(figure_index, type);
            break;
        }
        else if (function == "Rotate") {
            string type = data.Get(figure_index, 0);
            figures::Rotate(type, figure_index, data);
            break;
        }
        else if (function == "Resize") {
            data.Resize(figure_index);
            break;
        }
        else if (function == "Print_data") {
            data.Print_data(figure_index);
            break;
        }
        else if (function == "Repaint") {
            data.Repaint(figure_index);
            break;
        }
        else if (function == "Cancel") {
            break;
        }
        else if (function == "Delete") {
            data.Delete(figure_index);
            break;
        }
        else
            cout << "Enter function's name correctly!" << endl;
    }
}
