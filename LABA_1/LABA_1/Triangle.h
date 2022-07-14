#ifndef TRIANGLE
#define TRIANGLE
#include "Figure.h"
#include<string>
const double PI = 3.1415926;

class Triangle :
    public Figure{
protected:
    double side_1, side_2, side_3;
public:
    //Конструктор по умолчанию
    Triangle() : side_1(0), side_2(0), side_3(0) {}
    //Конструктор копирования
    Triangle(const Triangle& obj) : side_1(obj.side_1), side_2(obj.side_2), side_3(obj.side_3) {}
    //Конструктор значений
    Triangle(double, double, double);
    //Деструктор
    ~Triangle() {}

    //Оператор присваивания
    void operator=(const Triangle& trg);

    //Геттеры
    double getAngle(double);
    double getPerimeter();
    double getPlace();
    double getHeight(double);
    double getside_1() { return side_1; }
    double getside_2() { return side_2; }
    double getside_3() { return side_3; }

    virtual void print(); // приписка нужна для того, чтобы перегрузить в призму
};



#endif // !TRIANGLE