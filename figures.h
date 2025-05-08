#pragma once
#include "Data.h"
#include <memory>

/*
Шаблон:
Do_something () — создать шаблон фигуры и вызвать основную функцию
DoING_something () — выполнение основной функции, при отсутствии единой реализации оставляется пустой в родительском классе
*/

class figures: public Data {
protected:
	// Статический указатель на данные, общие для всех фигур
	static Data* data;
public:
	// Инициализация данных
	static void Init(Data& dataRef) {data = &dataRef;}
	// Определение типа фигуры
	static unique_ptr<figures> TypeFigure(const string& type);

	// Отрисовка фигур
	static void Draw_all(sf::RenderWindow& window);
	virtual void Draw(sf::RenderWindow& window, int i);

	// Ввести и добавить фигуру в список данных
	void Add(string type);
	virtual void Adding();
	// Заменить данные координат фигуры
	void Moving(int figure_index, string type);
	// Поворот фигур
	void Rotate(string type, int figure_index);
	virtual void Rotating(int figure_index);
	// Изменить размер фигуры
	void Resize(int figure_index, string type);
	virtual void Resizing(int figure_index);
	// Перекрасить фигуру
	void Repainting(int figure_index);
};