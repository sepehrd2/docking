#include <iostream>
#include <cmath>
#include "Quaternion.h"
using namespace std;

Quaternion::Quaternion(){
	x1 = 0.0;
	x2 = 0.0;
	x3 = 0.0;
	x4 = 0.0;
}
Quaternion::~Quaternion(){}
Quaternion& Quaternion::operator=(const Quaternion & q) {
	x1 = q.x1;
	x2 = q.x2;
	x3 = q.x3;
	x4 = q.x4;
	return *this;
}
Quaternion& Quaternion::operator*(const Quaternion & q) {
	Quaternion q1;
	q1.x1 = x1 * q.x1 - x2 * q.x2 - x3 * q.x3 - x4 * q.x4;
	q1.x2 = x1 * q.x2 + x2 * q.x1 + x3 * q.x4 - x4 * q.x3;
	q1.x3 = x1 * q.x3 - x2 * q.x4 + x3 * q.x1 + x4 * q.x2;
	q1.x4 = x1 * q.x4 + x2 * q.x3 - x3 * q.x2 + x4 * q.x1;
	return q1;
}

float Quaternion::norm(){
	return (x1 * x1 + \
			x2 * x2 + \
			x3 * x3 + \
			x4 * x4);
}
Quaternion Quaternion::conjugate(){
	Quaternion q;
	q.x1 =  x1;
	q.x2 = -x2;
	q.x3 = -x3;
	q.x4 = -x4;
	return q;
}

Quaternion Quaternion::inverse(){
	Quaternion q;
	q = this->conjugate();
	float n = this->norm();
	q.x1 = q.x1 / n;
	q.x2 = q.x2 / n;
	q.x3 = q.x3 / n;
	q.x4 = q.x4 / n;
	return q;
}
bool Quaternion::unit(){
	float n = this->norm();
	if (n == 1.0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
Quaternion	Quaternion::ang_vec_to_q(const float & theta \
	, const Vector & u){
	float theta_half, sint;
	theta_half = theta * 0.5;
	sint = sin(theta_half);
	
	x1 = cos(theta_half);
	x2 = sint * u.x;
	x3 = sint * u.y;
	x4 = sint * u.z;
	return *this;
}
void Quaternion::out(){
	std::cout << x1 << " " << x2 << " " \
		 	  << x3 << " " << x4 << std::endl; 
}