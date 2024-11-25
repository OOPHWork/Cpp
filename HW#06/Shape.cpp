#include <iostream>
#include "Shape.h"
Shape::Shape() { next = NULL; }
Shape* Shape::add(Shape* p) {
	this->next = p;
	return p;
}
void Shape::paint() {
	draw();
}
Shape* Shape::getNext() { return next; }