#include <iostream>
#include "Vector.h"
using namespace std;

Vector::Vector(){
	x = 0.0;
	y = 0.0;
	z = 0.0;
}
Vector::~Vector(){}
Vector& Vector::operator-(const Vector & v) {
	Vector v1;
	v1.x = x - v.x;
	v1.y = y - v.y;
	v1.z = z - v.z;
	return v1;
}
Vector& Vector::operator=(const Vector & v) {
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}
Vector& Vector::operator-=(const Vector & v) {
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}
Vector& Vector::operator+(const Vector & v) {
	Vector v1;
	v1.x = x + v.x;
	v1.y = y + v.y;
	v1.z = z + v.z;
	return v1;
}
Vector& Vector::operator+=(const Vector & v) {
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

void Vector::out(){
	std::cout << x << " "
			  << y << " "
			  << z << std::endl;
}
