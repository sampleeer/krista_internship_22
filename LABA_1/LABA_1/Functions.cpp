#include "Functions.h"
#include <iostream>
#include <fstream>
#include "List.h"
#include "Straight_prism.h"
#include "Triangle.h"
#include "Figure.h"
#include <iostream>
using namespace std;

// чтение
void read_fgs(ifstream& in, list<Figure*>& fgs) {
	int num = 0;
	in >> num;
	if (num == 0) throw string("No data");
	for (int i = 0; i < num; i++) {
		int number = -1;
		double side_1 = 0, side_2 = 0, side_3 = 0, height = 0;
		in >> number;
		if (number == 0) {
			in >> side_1 >> side_2 >> side_3;
			try {
				fgs.push_back(new Triangle(side_1, side_2, side_3));
			}
			catch (string mis) {
				if (mis == "Invalid sides") {
					cout << "In line " << i + 1 << ": figure invalid arguments\n";
				}
				else if (mis == "A nonexistent triangle") {
					cout << "In line " << i + 1 << ": figure invalid arguments\n";
				}
			}
		}
		else if (number == 1) {
			in >> side_1 >> side_2 >> side_3 >> height;
			try {
				fgs.push_back(new Straight_prism(Triangle(side_1, side_2, side_3), height));
			}
			catch (string mis) {
				if (mis == "Invalid height") {
					cout << "In line " << i + 1 << ": figure invalid arguments\n";
				}
				else if (mis == "A nonexistent triangle") {
					cout << "In line " << i + 1 << ": figure invalid arguments\n";
				}
			}
		}
	}
}

// печать
void print_fgs(list<Figure*>& figures) {
	for (int i = 0; i < figures.get_size(); i++) {
		figures.find_value(i)->print();
		cout << endl;
	}
}

// поиск максимума
void find_max(list<Figure*>& figures, Triangle& max_trg, Straight_prism& max_prism) {
	for (int i = 0; i < figures.get_size(); i++) {
		if (typeid(*figures.find_value(i)) == typeid(max_trg)) {
			Triangle* trg = dynamic_cast<Triangle*>(figures.find_value(i));
			if (max_trg.getPlace() < trg->getPlace())
				max_trg = *trg;
		}
		else if (typeid(*figures.find_value(i)) == typeid(max_prism)) {
			Straight_prism* prism = dynamic_cast<Straight_prism*>(figures.find_value(i));
			if (max_prism.getdiagonal() < prism->getdiagonal())
				max_prism = *prism;
		}
	}
}