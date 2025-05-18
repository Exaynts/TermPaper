#pragma once
#include "Data.h"

class Load_data {
public:
	// Загрузить данные фигур с файла
	static bool Load(string& file_path, Data* data);
};

