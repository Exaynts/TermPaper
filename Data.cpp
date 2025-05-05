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
// Геттер
string Data::Get(int i, int j) {
    return data[i][j];
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