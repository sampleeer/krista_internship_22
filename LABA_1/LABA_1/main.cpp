#include <iostream>
#include <fstream>
#include "List.h"
#include "Functions.h"
#include "Straight_prism.h"
#include "Triangle.h"
#include "Figure.h"
#include <iostream>
using namespace std;

int main() {
	list<Figure*> figures;
	ifstream in("input.txt");
	bool flag = true;
	try {
		read_fgs(in, figures); // первая функция
	}
	catch (string mis) {
		if (mis == "No data") cout << "No data";
		flag = false;
	}
	print_fgs(figures); // вторая функция

	if (flag) {
		Triangle max_trg;
		Straight_prism max_prism;
		find_max(figures, max_trg, max_prism);
		if (max_trg.getPerimeter() != 0) {
			cout << endl << "Triangle with maximum Place: " << endl;
			max_trg.print();
		}
		if (max_prism.getdiagonal() != 0) {
			cout << endl << "Straight prism with maximum diagonal: " << endl;
			max_prism.print();
		}
	}

	in.close();
	return 0;
}