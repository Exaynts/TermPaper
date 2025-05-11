#include "Menu.h"
#include <string>
using namespace std;

Data* Menu::data = nullptr;

// Вход в программу
Data* Menu::Entrance() {
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
        if (function == "1") {
            break;
        }
        // Заполняем список данными из файла
        else if (function == "2") {
            cout << "Enter the path to the data file: " << endl;
            string file_path = "";
            cin >> file_path;
            // Пока не загрузятся данные
            while (!Menu::Load(file_path)) {
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
bool Menu::Load(string& file_path) {
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

// Главное меню
bool Menu::Main_Menu() {
    string function = "";
    // Показ функций
    cout << "Select one of the following actions (write number):" << endl;
    vector <string> action_list{ "Create", "Select", "Print data", "Save data", "Exit" };
    for (int i = 0; i < action_list.size(); i++) {
        cout << i + 1 << "." << action_list[i] << " ";
    }
    cout << '\n';
    // Выбор функции
    int action = -1;
    action = Input_int();
    while (action > action_list.size()) { // Вводим допустимый индекс
        cout << "This number is too high!";
        action = Input_int();
    }
    // Действие согласно номеру в списке
    switch (action) {
        case 1: Menu::Create_figure(); break;
        case 2:
            if (data->Length() != 0) {
                int figure_index = Menu::Select_figure();
                data->Print_data(figure_index);
                Menu::Change_figure(figure_index);
            }
            else {
                cout << "There is no one figure in the list! Create figure!" << endl;
            }
            break;
        case 3: data->Print_all_data(); break;
        case 4: data->Save_data(); break;
        case 5: return false;
        default:
            cout << "ActionError!" << endl;
    }
    return true;
}

vector<Shape*> type_list = { &f_line, &f_square, &f_rectangle, &f_circle };
// Создать фигуру
void Menu::Create_figure() {
    // Выбираем тип фигуры  
    Menu menu(type_list);
    Shape* shape = menu.Select_Type();
    shape->Adding();
}

// Выбрать фигуру (по индексу)
int Menu::Select_figure() {
    cout << "Write index of your figure " << "(max index = " << data->Length() - 1 << "): ";
    int figure_index = -1;
    while (figure_index < 0 or figure_index >= data->Length()) {
        figure_index = Input_int();
        if (figure_index >= data->Length())
            cout << "This number is too high!" << endl;
    }
    return figure_index;
}
// Изменить фигуру
void Menu::Change_figure(int figure_index) {
    // Показ функций
    cout << "Select one of the following fuctions (write number):" << endl;
    vector <string> action_list {"Move", "Rotate", "Resize", "Repaint", "Print data", "Cancel", "Delete"};
    for (int i = 0; i < action_list.size();  i++) {
        cout << i+1 << "." << action_list[i] << " ";
    }
    cout << '\n';
    // Выбор функции
    int action = -1;
    action = Input_int();
    while (action > action_list.size()) { // Вводим допустимый индекс
        cout << "This number is too high!";
        action = Input_int();
    }
    // Создание шаблона фигуры
    string type = data->Get(figure_index, 0);
    auto shape = TypeFigure::Type(data->Get(figure_index, 0));  
    // Действие согласно номеру в списке
    switch (action) {
    case 1: shape->Moving(figure_index); break;
    case 2: shape->Rotating(figure_index); break;
    case 3: shape->Resizing(figure_index); break;
    case 4: shape->Repainting(figure_index); break;
    case 5: data->Print_data(figure_index);
    case 6: break;
    case 7: data->Delete(figure_index); break;
    default:
        cout << "ActionError!" << endl;
    }
}


Shape* Menu::Select_Type() const {
    int n_item = ptype.size();
    cout << "Select one of the following types: (write number)\n";

    for (int i = 0; i < n_item; ++i) {
        cout << i + 1 << ". ";
        cout << ptype[i]->Get_Name() << endl;
    }
    int item = Select_Item(n_item);
    return ptype[item - 1];
}

int Menu::Select_Item(int n_item) const {
    int item;
    while (true) {
        item = Input_int();
        if ((item > 0) && (item <= n_item) && (cin.peek() == '\n')) {
            cin.get(); break;
        }
        else {
            cout << "Error(must be number from 1 to " << n_item
                << "):\n";
            cin.clear();
        }
    }
    return item;
}