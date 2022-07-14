#ifndef STRAIGHT_PRISM
#define STRAIGHT_PRISM
#include "Triangle.h"
class Straight_prism :
	public Triangle {
private:
	double height;
	Triangle base;
public:
	//Конструктор по умолчанию
	Straight_prism() {
		side_1 = 0; 
		side_2 = 0;
		side_3 = 0;
		height = 0;
	}
	//Конструктор значений
	Straight_prism(Triangle, double);
	//Деструктор
	~Straight_prism() {}

	//Геттеры
	double getSurfPlace();
	double getVolume();
	double getdiagonal();

	void print();
};
#endif
