#include <string>
#include "Atom.h"
#include <vector>
#include <fstream>

#ifndef TRAJECTORY_H_
#define TRAJECTORY_H_

void writing_trajectory(ofstream &, const std::vector<Atom> &, const int &);
#endif 
