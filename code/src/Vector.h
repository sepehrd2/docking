#ifndef VECTOR_H_
#define VECTOR_H_
class Vector
{
public:
	float x, y, z;
	Vector();
	~Vector();
	Vector& operator-(const Vector & );
	Vector& operator=(const Vector & );
	Vector& operator-=(const Vector & );
	Vector& operator+(const Vector & );
	Vector& operator+=(const Vector & );

	void out();
private:
};

#endif 
