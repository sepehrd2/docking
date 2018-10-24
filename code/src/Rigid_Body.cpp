#include <iostream>
#include "Rigid_Body.h"

using namespace std;

void translation (vector<Atom> & ATOMS, const Vector & T){

	for (int i = 0; i < ATOMS.size(); ++i)
	{
		ATOMS[i].position.x += T.x;
		ATOMS[i].position.y += T.y;
		ATOMS[i].position.z += T.z;
	}
}
void rotation (vector<Atom> & ATOMS, Quaternion & q){
	Quaternion q_inv, rot_v, q_new;
	rot_v.x1 = 0.0;
	q_inv = q.inverse();
	for (int i = 0; i < ATOMS.size(); ++i)
	{
		rot_v.x2 = ATOMS[i].position.x;
		rot_v.x3 = ATOMS[i].position.y;
		rot_v.x4 = ATOMS[i].position.z;
		q_new = (q_inv * rot_v);
		q_new = q_new * q;
		ATOMS[i].position.x = q_new.x2;
		ATOMS[i].position.y = q_new.x3;
		ATOMS[i].position.z = q_new.x4;
	}
}
Vector center_mass(std::vector<Atom> & ATOMS)
{
	Vector CM;
	int N = ATOMS.size();
	CM.x = 0.0;
	CM.y = 0.0;
	CM.z = 0.0;
	for (int i = 0; i < N; ++i)
	{
		CM.x += ATOMS[i].position.x;
		CM.y += ATOMS[i].position.y;
		CM.z += ATOMS[i].position.z;
	}
	CM.x /= N;
	CM.y /= N;
	CM.z /= N;
	return CM;
}
void rotation_CM(vector<Atom> & ATOMS, Quaternion & q){
	Quaternion q_inv, rot_v, q_new;
	rot_v.x1 = 0.0;
	q_inv = q.inverse();
	Vector CM;
	CM = center_mass(ATOMS);
	for (int i = 0; i < ATOMS.size(); ++i)
	{
		ATOMS[i].position -= CM;
		rot_v.x2 = ATOMS[i].position.x;
		rot_v.x3 = ATOMS[i].position.y;
		rot_v.x4 = ATOMS[i].position.z;
		q_new = (q_inv * rot_v);
		q_new = q_new * q;
		ATOMS[i].position.x = q_new.x2;
		ATOMS[i].position.y = q_new.x3;
		ATOMS[i].position.z = q_new.x4;
		ATOMS[i].position += CM;
	}
}
