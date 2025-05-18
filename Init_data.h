#pragma once
#include "Data.h"
#include "Shape.h"
#include "Load_data.h"

class Init_data {
protected:
	static Data* data;
public:
	// Инициализация базы данных
	static Data* Init();
};

