# A Monte-Carlo (MC) based ligand-protein docking package

This is an ongoing project with the final goal of developing a fast
and reliable docking software which can be executed on CPU/GPU. The
implemented algorithm here is written in C++ and uses orientation
quaternions and a transition matrix to rotate and translate ligands
in a cubic box defined by users. Each rotation or translation is
initiated randomly from a normal distribution, implemented in the
code, exploiting the Box-Muller transform. The generated ligand poses
then each is either accepted or rejected, using their non-bonded
interaction energies with the protein and based on a MC algorithm.
The interaction energies are calculated in the code, employing AMBER
forcefield parameters for different non-bonded interactions.
At the moment, the code is not capable of working with flexible
ligands or/and proteins. Moreover, the implementation at this stage
is serial. The code is not capable of any visualization and users
need to rely on another softwares, e.g. VMD, to visualize the poses
and protein. 
