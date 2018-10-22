#include <iostream>
#include "Matrix.h"

using namespace std;

Matrix::Matrix(){
	a11 = 0.0;
	a12 = 0.0;
	a13 = 0.0;
	a21 = 0.0;
	a22 = 0.0;
	a23 = 0.0;
	a31 = 0.0;
	a32 = 0.0;
	a33 = 0.0;
}

Matrix::~Matrix(){}

void Matrix::out(){
	cout << a11 << " " << a12 << " " << a13 << endl;
	cout << a21 << " " << a22 << " " << a23 << endl;
	cout << a31 << " " << a32 << " " << a33 << endl;
}

Matrix& Matrix::operator*(const Matrix & mat) {
	Matrix result;
 	result.a11 = a11 * mat.a11 + a12 * mat.a21 + a13 * mat.a31;
 	result.a12 = a11 * mat.a12 + a12 * mat.a22 + a13 * mat.a32;
 	result.a13 = a11 * mat.a13 + a12 * mat.a23 + a13 * mat.a33;
 	result.a21 = a21 * mat.a11 + a22 * mat.a21 + a23 * mat.a31;
 	result.a22 = a21 * mat.a12 + a22 * mat.a22 + a23 * mat.a32;
 	result.a23 = a21 * mat.a13 + a22 * mat.a23 + a23 * mat.a33;
 	result.a31 = a31 * mat.a11 + a32 * mat.a21 + a33 * mat.a31;
 	result.a32 = a31 * mat.a12 + a32 * mat.a22 + a33 * mat.a32;
 	result.a33 = a31 * mat.a13 + a32 * mat.a23 + a33 * mat.a33;

	// return *this;
	return result;
}

Matrix& Matrix::operator=(const Matrix & mat) {
	a11 = mat.a11; a12 = mat.a12; a13 = mat.a13;
	a21 = mat.a21; a22 = mat.a22; a23 = mat.a23;
	a31 = mat.a31; a32 = mat.a32; a33 = mat.a33;

	return *this;
}

float Matrix::det()
{
	return (a11 * (a33 * a22 - a32 * a23) \
		  - a21 * (a33 * a12 - a32 * a13) \
		  + a31 * (a23 * a12 - a22 * a13) );
}

Matrix Matrix::mat_inverse()
{
	float det_inv = 1.0/ this->det();
	Matrix inverse;
	inverse.a11 =   a33 * a22 - a32 * a23;
	inverse.a12 = -(a33 * a12 - a32 * a13);
	inverse.a13 =   a23 * a12 - a22 * a13;
	inverse.a21 = -(a33 * a21 - a31 * a23);
	inverse.a22 =   a33 * a11 - a31 * a13;
	inverse.a23 = -(a23 * a11 - a21 * a13);
	inverse.a31 =   a32 * a21 - a31 * a22;
	inverse.a32 = -(a32 * a11 - a31 * a12);
	inverse.a33 =   a22 * a11 - a21 * a12;

	inverse.a11 *= det_inv;
	inverse.a12 *= det_inv;
	inverse.a13 *= det_inv;
	inverse.a21 *= det_inv;
	inverse.a22 *= det_inv;
	inverse.a23 *= det_inv;
	inverse.a31 *= det_inv;
	inverse.a32 *= det_inv;
	inverse.a33 *= det_inv;

	return inverse;
}

