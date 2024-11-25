#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include "Shape.h"
using namespace std;

class Circle : public Shape {
protected:
	virtual void draw();

};
#endif