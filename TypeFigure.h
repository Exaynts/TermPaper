#pragma once
#include "Line.h"
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"

class Shape;

class TypeFigure
{
public:
	// Определение типа фигуры
	static unique_ptr<Shape> Type(const string& type);
};

