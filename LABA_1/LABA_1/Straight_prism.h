#ifndef STRAIGHT_PRISM
#define STRAIGHT_PRISM
#include "Triangle.h"
class Straight_prism :
	public Triangle {
private:
	double height;
	Triangle base;
public:
	//����������� �� ���������
	Straight_prism() {
		side_1 = 0; 
		side_2 = 0;
		side_3 = 0;
		height = 0;
	}
	//����������� ��������
	Straight_prism(Triangle, double);
	//����������
	~Straight_prism() {}

	//�������
	double getSurfPlace();
	double getVolume();
	double getdiagonal();

	void print();
};
#endif
