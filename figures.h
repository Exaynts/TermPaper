#pragma once
#include "Data.h"

class figures: public Data {
protected:
	// Статический указатель на данные, общие для всех фигур
	static Data* data;
public:
	// Инициализация данных
	static void Init(Data& dataRef) {data = &dataRef;}

	// Отрисовка фигур
	static void Draw_all(sf::RenderWindow& window);

	// Ввод и добавление фигур в список данных
	void Add(string type);
	// Заменяем данные координат фигуры
	void Move(int figure_index, string type);
	// Поворот фигур
	void Rotate(string type, int figure_index);
	// Изменить размер фигуры
	virtual void Resize(int figure_index);
	// Перекрасить фигуру
	void Repaint(int figure_index);
};