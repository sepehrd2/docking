
SRCDIR = /Scr/sepehr/docking/code/src
OBJS = \
	$(SRCDIR)/main.o \
	$(SRCDIR)/Vector.o \
	$(SRCDIR)/pdb.o \
	$(SRCDIR)/Atom.o \
	$(SRCDIR)/Matrix.o \
	$(SRCDIR)/Quaternion.o \
	$(SRCDIR)/Rigid_Body.o \
	$(SRCDIR)/Random.o \
	$(SRCDIR)/Monte_Carlo.o \

output: $(OBJS)
	g++ $(OBJS) -o output

main.o: main.cpp 
	g++ -c main.cpp

Vector.o: Vector.cpp Vector.h
	g++ -c Vector.cpp

pdb.o: pdb.cpp pdb.h
	g++ -c pdb.cpp

Atom.o: Atom.cpp Atom.h
	g++ -c Atom.cpp

Matrix.o: Matrix.cpp Matrix.h
	g++ -c Matrix.cpp


Quaternion.o: Quaternion.cpp Quaternion.h
	g++ -c Quaternion.cpp

Rigid_Body.o: Rigid_Body.cpp Rigid_Body.h
	g++ -c Rigid_Body.cpp

Random.o: Random.cpp Random.h
	g++ -c Random.cpp

Monte_Carlo.o: Monte_Carlo.cpp Monte_Carlo.h
	g++ -c Monte_Carlo.cpp

clean:
	rm -f *.o output

