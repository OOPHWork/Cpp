#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include "Shape.h"
using namespace std;

class Rectangle : public Shape {
protected:
	virtual void draw();

};

#endif