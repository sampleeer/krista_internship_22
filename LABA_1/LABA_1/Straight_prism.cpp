#include "Straight_prism.h"
#include <iostream>
using namespace std;

//Конструктор значений
Straight_prism::Straight_prism(Triangle trian, double _height){
	height = _height;
	side_1 = trian.getside_1();
	side_2 = trian.getside_2();
	side_3 = trian.getside_3();
	if (_height <= 0)
		throw string("Invalid height");
	if (((side_1 + side_2) <= side_3) || ((side_1 + side_3) <= side_2) || ((side_3 + side_2) <= side_1))
		throw string("A nonexistent triangle");
}

//Геттеры
double Straight_prism::getSurfPlace() {
	if (height == 0)
		return 0;
	return (Triangle::getPerimeter() * height + 2 * Triangle::getPlace());
}
double Straight_prism::getVolume() {
	return height * Triangle::getPlace();
}

//диагональ призмы (высота треугольнка в сечении призмы по диагонали)
double Straight_prism::getdiagonal() {
	double side;
	//основание сечения
	double new_base;
	if (side_3 > side_1) {
		side = side_3;
		new_base = side_1;
	}
	else {
		side = side_1;
		new_base = side_3;
	}
	//диагональ грани
	double diagonal_facet = sqrt(height * height + side * side);
	return sqrt(diagonal_facet * diagonal_facet - (new_base / 2) * (new_base / 2));
}

void Straight_prism::print() {
	cout << "Height = " << height << endl;
	cout << "Triangle in base: " << endl; Triangle::print();
	cout << "Surface Place = " << getSurfPlace() << endl;
	cout << "Volume = " << getVolume() << endl;
}
