#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

#define Eps 1e-16

class Circle;
class Field
{
    Circle *head;
    Circle *cur;
    int k;
public:
    Field();
    ~Field();
    int read(const char* filename);
    void print();
    friend class Circle;
    Circle* operator[] (const int index);
    void check();

};

class Circle
{
    double x;
    double y;
    double r;
    Circle *pNext;
    int k;
public:
    friend class Field;
    Circle();
    Circle(double x, double y, double r, int n)
    {
        this->x = x;
        this->y = y;
        this->r = r;
        this->k = n;
    }
    ~Circle() = default;
    void destroy();
    void check(Circle* cir);
};
