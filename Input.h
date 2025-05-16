#pragma once
#include <iostream>
using namespace std;
class Input {
public:
	// ¬вод неотрицательного целого числа, не превышающее max (по умолчанию 65535). јргумент "!0" дополительно отсекает число ноль
	static int Input_natural0(string iszero = "0", int max = 65535);
	// ¬вод целого числа
	static int Input_any_int();
	// ¬вод неотрицательного действительного числа
	static float Input_pos_float();
};

