#include "Vector.h"

#ifndef QUATERNION_H_
#define QUATERNION_H_
class Quaternion
{
public:
	// float theta;
	// Vector rot_vec;
	float x1, x2, x3, x4;
	Quaternion();
	~Quaternion();
	Quaternion& operator=(const Quaternion & );
	Quaternion& operator*(const Quaternion & );
	float norm();
	Quaternion conjugate();
	Quaternion inverse();
	bool unit();
	Quaternion ang_vec_to_q(const float &, const Vector &);
	void out();
private:

};

#endif 
