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

// ������
void read_fgs(ifstream&, list<Figure*>&);
// �����
void print_fgs(list<Figure*>&);
// ����� ���������
void find_max(list<Figure*>&, Triangle&, Straight_prism&);
#endif 
