all:
	g++ -o OpenMP_hello_world -fopenmp OpenMP_simple.cpp
	mpicxx -o MPI_hello_world MPI_simple.cpp

run_OpenMP:
	./OpenMP_hello_world

run_MPI:
	mpirun -np 16 ./MPI_hello_world

clean:
	rm OpenMP_hello_world MPI_hello_world