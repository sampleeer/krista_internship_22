#include "Triangle.h"
#include <iostream>
using namespace std;

//Конструктор с параметром
Triangle::Triangle(double _side_1, double _side_2, double _side_3) {
	if (_side_1 < 0 || _side_2 < 0 || _side_3 < 0)
		throw string("Invalid sides");
	if (((_side_1 + _side_2) <= _side_3) || ((_side_1 + _side_3) <= _side_2) || ((_side_3 + _side_2) <= _side_1))
		throw string("A nonexistent triangle");
	side_1 = _side_1;
	side_2 = _side_2;
	side_3 = _side_3;
}

//Оператор присваивания
void Triangle::operator=(const Triangle& trg) {
	side_1 = trg.side_1;
	side_2 = trg.side_2;
	side_3 = trg.side_3;
}

//Геттеры
double Triangle::getAngle(double side) {
	if (side == 0)
		return 0;
	if (side_1 == side)
		return acos((pow(side_2, 2) + pow(side_3, 2) - pow(side_1, 2)) / (2 * side_2 * side_3)) * 180 / PI;
	if (side_2 == side)
		return acos((pow(side_1, 2) + pow(side_3, 2) - pow(side_2, 2)) / (2 * side_1 * side_3)) * 180 / PI;
	if (side_3 == side)
		return acos((pow(side_1, 2) + pow(side_2, 2) - pow(side_3, 2)) / (2 * side_1 * side_2)) * 180 / PI;
	return 0;
}
double Triangle::getPerimeter() {
	return (side_1 + side_2 + side_3);
}
double Triangle::getPlace() {
	double p = this->getPerimeter() / 2;
	return sqrt(p * (p - side_1) * (p - side_2) * (p - side_3));
}
double Triangle::getHeight(double base) {
	if (base == 0)
		return 0;
	return getPlace() / base;
}

void Triangle::print() {
	cout << "Side 1: " << side_1 << endl;
	cout << "Side 2: " << side_2 << endl;
	cout << "Side 3: " << side_3 << endl;
	cout << "Angle 1 = " << this->getAngle(side_1) << endl;
	cout << "Angle 2 = " << this->getAngle(side_2) << endl;
	cout << "Angle 3 = " << this->getAngle(side_3) << endl;
	cout << "Height base 1: " << this->getHeight(side_1) << endl;
	cout << "Height base 2: " << this->getHeight(side_2) << endl;
	cout << "Height base 3: " << this->getHeight(side_3) << endl;
	cout << "Perimeter = " << this->getPerimeter() << endl;
	cout << "Place = " << this->getPlace() << endl;
}