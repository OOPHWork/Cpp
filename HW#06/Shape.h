#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
using namespace std;
class Shape {
	Shape* next;
protected:
	virtual void draw() = 0;
public:
	Shape();
	virtual ~Shape() {}
	Shape* add(Shape* p);
	void paint();
	Shape* getNext();
};

#endif