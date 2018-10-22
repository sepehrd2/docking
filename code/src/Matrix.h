
#ifndef MATRIX_H_
#define MATRIX_H_
class Matrix
{
public:
	float a11, a12, a13;
	float a21, a22, a23;
	float a31, a32, a33;

	Matrix();
	~Matrix();
	void out();
	Matrix& operator*(const Matrix & );
	Matrix& operator=(const Matrix & );
	float det();
	Matrix mat_inverse();
private:

};

#endif 
