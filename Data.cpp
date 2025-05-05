#include "Data.h"
using namespace std;

/* ���������:
[[������.0], [������.1], ... [������.�����_������-1)]]
[������.i] ��� ������ �� ���������� �����:
[���, angle/radius, x1, y1, x2, y2, Red_color, Green_color, Blue_color]
�������������� ��� ������-�� ���� ������ �������� ����� �����������, ��� "0" � �� ������ ����������
*/


// ������� ������ ������ � �������
Data::Data() {
    par = 9; // ���������� ���������� � ������
	data = vector<vector<string>> (0, vector <string>(par));
}
// ���������� �����
int Data::Length() {
    return size(data);
}
// ������
string Data::Get(int i, int j) {
    return data[i][j];
}
// ������
void Data::Set(int i, int j, string value) {
    data[i][j] = value;
}

// ��������� ������ � ����� ������
void Data::Add(string type, string ar, string x1, string y1, string x2, string y2) {
    vector<string> figure{type, ar, x1, y1, x2, y2, "255", "255", "255"};
    data.push_back(figure);
}

// ������� ������ � ������
void Data::Print_data(int figure_index) {
    cout << "[type, angle/radius, x1, y1, x2, y2, Red_color, Green_color, Blue_color]" << endl;
    cout << "[ ";
    for (int i = 0; i < par; i++) {
        cout << data[figure_index][i] << " ";
    }
    cout << "]" << endl;
}

// ������� ������ � ���� �������
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

// ��������� ������ � ������� � ��������� ����
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

// ������� ������ � ������
void Data::Delete(int figure_index) {
    cout << "After deleting the element with index[i], the indices of all the following elements in the list decreased by one" << endl;
    data.erase(data.begin() + figure_index);
}