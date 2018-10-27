//============================================================================
// Name        : main.cpp
// Author      : Sepehr
#include <iostream>
#include <fstream>
#include <string>
#include "pdb.h"
#include <stdlib.h>     /* strtof */
#include <vector>
#include "Atom.h"
#include "Vector.h"
#include "Rigid_Body.h"
#include "Matrix.h"
#include "Quaternion.h"
#include "Constants.h"
#include "Random.h"
#include <string>     // std::string, std::to_string
#include <sstream>
#include <iomanip> // setprecision

#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost;
int main() {
  ifstream myfile;
	string d;
	string a = "/Scr/sepehr/docking/ligand.pdb";
  string b = "/Scr/sepehr/docking/ligand_new.XYZ";
  Vector T;
  

  Quaternion q, p, l;
  // q.x1 = 1;
  // q.x2 = 0;
  // q.x3 = 0;
  // q.x4 = 0;
  
  ofstream XYZfile;
  XYZfile.open (b.c_str());
  double rand_rot_angle;
  vector<Atom>  ATOMS;
  read_pdb (a, ATOMS);
  // 
  for (int i = 0; i < 600; ++i)
  {
    // cout << i << endl;
    rand_rot_angle = gaussian() * 1.0;
    T.x = gaussian();
    T.y = gaussian();
    T.z = gaussian();
    // translation(ATOMS, T);
    q.ang_vec_to_q(rand_rot_angle * deg_to_rad, T);
    rotation_CM(ATOMS, q);
    XYZfile << ATOMS.size() << endl;
    XYZfile << i  << endl;
    for (int j = 0; j < ATOMS.size(); ++j)
    {
      XYZfile << ATOMS[j].name     << " ";
      XYZfile << ATOMS[j].position.x << " ";
      XYZfile << ATOMS[j].position.y << " ";
      XYZfile << ATOMS[j].position.z << endl; 
    } 
  }
  XYZfile.close();
  float cc;
  char* pEnd;
  Vector TT, TTT;
  TT.x = 1.0;
  TT.y = 3.0;
  TT.z = 3.0;
  T -= TT;
  T.out();
  TT.out();
  TTT.out();
  // cc = strtof("123", NULL);
//   string st;
//   st = "123";
//   cc = atof(st.c_str());
//   cout << cc * 2 << endl;
//   string str(" 123 ");
//   // trim(str);
//   // cout << str;
// int pi = 123;
// stringstream stream;
// stream << fixed << setprecision(3) << pi;
// string s = stream.str();
// while (s.length() < 4)
// {
//   s  = s + " ";
// }
// cout << s;
  // string.erase(std::remove_if(string.begin(), string.end(), std::isspace), string.end());
 //  q.out();
	// read_XYZ (a, ATOMS);
 //  // translation (ATOMS, T);
 //  rotation(ATOMS, q);
 //  write_XYZ(b, ATOMS);
 //  // Matrix m;
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

