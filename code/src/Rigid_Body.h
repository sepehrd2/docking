#include <vector>
#include "Atom.h"
#include "Vector.h"
#include "Quaternion.h"


#ifndef RIGIDBODY_H_
#define RIGIDBODY_H_
class Rigid_Body
{
public:


private:

};

#endif 
void translation  (std::vector<Atom>  &, const Vector &);
void rotation     (std::vector<Atom>  &, Quaternion &);
Vector center_mass(std::vector<Atom>  &);
void rotation_CM  (std::vector<Atom> & , Quaternion & q);