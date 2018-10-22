//============================================================================
// Name        : Hacketon.cpp
// Author      : Sepehr
#include <iostream>
#include <fstream>
#include <string>
#include "pdb.h"
#include <vector>
#include "Atom.h"
#include "Vector.h"
#include "Rigid_Body.h"
#include "Matrix.h"
#include "Quaternion.h"
#include "Constants.h"
// inline bool starts_with(const std::string& str, const std::string& start) {
// 	return str.size() >= start.size() && str.substr(0, start.size()) == start;
// }

using namespace std;
  
int main() {
  ifstream myfile;
	string d;
	string a = "/Scr/sepehr/docking/protein.XYZ";
  string b = "/Scr/sepehr/docking/protein_new.XYZ";
  Vector T;
  T.x = 1.0;
  T.y = 0.0;
  T.z = 0.0;

  Quaternion q, p, l;
  // q.x1 = 1;
  // q.x2 = 0;
  // q.x3 = 0;
  // q.x4 = 0;
  q.ang_vec_to_q(60.0 * deg_to_rad, T);
  q.out();
  vector<Atom>  ATOMS;
	read_XYZ (a, ATOMS);
  // translation (ATOMS, T);
  rotation(ATOMS, q);
  write_XYZ(b, ATOMS);
  // Matrix m;
  // Matrix m_inv;
  // Matrix n;
  // m.a11 = 1;
  // m.a12 = 1;
  // m.a13 = 3;
  // m.a21 = 4;
  // m.a22 = 5;
  // m.a23 = 6;
  // m.a31 = 7;
  // m.a32 = 8;
  // m.a33 = 9;
  // cout << m.det() << endl;
  // m_inv = m.mat_inverse();
  // n = m * m_inv;
  // m.out();
  // p = q.inverse();
  // l = p * q;
  // l.out();

  // cout << "-----" << endl;
  // n.out();
  // for (int i = 0; i < ATOMS.size(); ++i)
  // {
  //   cout << i << " " << ATOMS[i].x << " " \
  //   << ATOMS[i].y << " " << ATOMS[i].z \
  //   << endl;
  //   // cout << ATOMS.size() << endl;
  // }
  // Matrix mat;
  // mat.out();

}

