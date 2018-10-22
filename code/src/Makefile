
SRCDIR = /Scr/sepehr/docking/code/src
OBJS = \
	$(SRCDIR)/main.o \
	$(SRCDIR)/pdb.o \
	$(SRCDIR)/Atom.o \
	$(SRCDIR)/Matrix.o \
	$(SRCDIR)/Vector.o \
	$(SRCDIR)/Quaternion.o \
	$(SRCDIR)/Rigid_Body.o \

output: $(OBJS)
	g++ $(OBJS) -o output

main.o: main.cpp 
	g++ -c main.cpp

pdb.o: pdb.cpp pdb.h
	g++ -c pdb.cpp

Atom.o: Atom.cpp Atom.h
	g++ -c Atom.cpp

Matrix.o: Matrix.cpp Matrix.h
	g++ -c Matrix.cpp

Vector.o: Vector.cpp Vector.h
	g++ -c Vector.cpp

Quaternion.o: Quaternion.cpp Quaternion.h
	g++ -c Quaternion.cpp

Rigid_Body.o: Rigid_Body.cpp Rigid_Body.h
	g++ -c Rigid_Body.cpp

clean:
	rm -f *.o output

