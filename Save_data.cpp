#include "Save_data.h"

// Сохранить данные о фигурах в отдельный файл
void Save_data::Save(Data* data) {
    cout << "Enter the name the file will have. Use only letters, numbers and sign \"_\"!" << endl;
    string filename;
    cin >> filename;
    ofstream file(filename + ".txt");
    if (!file.is_open()) {
        cerr << "The file can not be created" << endl;
    }
    else {
        for (int i = 0; i < data->Length(); i++) {
            for (int j = 0; j < data->Get_par(); j++) {
                file << data->Get(i, j) << " ";
            }
            cout << endl;
        }
        file.close();
        cout << "The file was saved with the name \"" << filename << ".txt\"" << endl;
    }
}