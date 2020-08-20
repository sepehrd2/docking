# Docking

The package here is a docking code written by me. The code is capable of translating and rotatting a ligand, using a transition matrix and quaternions, respectively. Differnt ligand poses are generated using a normal random distribution. Each move is either accepted or rejected based on a Monte-Carlo based algorithm and using Metropolis algorithm. At the moment the captured poses are ranked based on the energy. Furthemore, the code only is capable of working with rigid ligands.

