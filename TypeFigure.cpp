#include "TypeFigure.h"

// Определение типа фигуры
unique_ptr<Shape> TypeFigure::Type(const string& type) {
    if (type == "Line") {
        return make_unique<Line>();
    }
    else if (type == "Square") {
        return make_unique<Square>();
    }
    else if (type == "Rectangle") {
        return make_unique<Rectangle>();
    }
    else if (type == "Circle") {
        return make_unique<Circle>();
    }
    else {
        throw invalid_argument("Unknown TypeFigure");
    }
}
