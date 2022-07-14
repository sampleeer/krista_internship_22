#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <fstream>
#include "List.h"
#include "Straight_prism.h"
#include "Triangle.h"
#include "Figure.h"
#include <iostream>
using namespace std;

// чтение
void read_fgs(ifstream&, list<Figure*>&);
// вывод
void print_fgs(list<Figure*>&);
// поиск максимума
void find_max(list<Figure*>&, Triangle&, Straight_prism&);
#endif 
