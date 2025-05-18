#include "Init_data.h"
#include "Menu.h"
Data* Init_data::data = nullptr;

// Инициализация базы данных
Data* Init_data::Init() {
    // Проверяем, не инициализированы ли данные ранее
    if (data != nullptr) {
        return data;
    }
    // Определение списка данных по умолчанию
    data = new Data();
    Shape::Set_data(data);
    string function = "";
    while (true) {
        cout << "To select a function, enter the desired number" << endl;
        cout << "Create or load picture?" << endl;
        cout << "1.Create 2.Load" << endl;
        cin >> function;
        // Оставляем всё, как есть
        if (function == "1") { // "Create"
            break;
        }
        // Заполняем список данными из файла
        else if (function == "2") { // "Load"
            cout << "Enter the path to the data file: " << endl;
            string file_path = "";
            cin >> file_path;
            // Пока не загрузятся данные
            while (!Load_data::Load(file_path, data)) {
                cin >> file_path;
            }
            break;
        }
        else
            cout << "Enter the text correctly!" << endl;
    }

    Menu::Set_data(data);
    return data;
}