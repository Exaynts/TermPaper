#include "Load_data.h"

// Загрузить данные фигур с файла
bool Load_data::Load(string& file_path, Data* data) {
    ifstream file(file_path);
    if (file_path == "break")
        return true;
    else if (!file.is_open()) {
        cerr << "The file was not found. To create an empty data list, write \"break\"." << endl;
        return false;
    }
    else {
        string type, ar, x1, y1, x2, y2, r_color, g_color, b_color;
        while (file >> type >> ar >> x1 >> y1 >> x2 >> y2 >> r_color >> g_color >> b_color) {
            data->Add(type, ar, x1, y1, x2, y2, r_color, g_color, b_color);
        }
        file.close();
    }
    return true;
}
