// OpenMP program to write the SSD to it's 95% capacity
// using C language
 
// OpenMP header
#include <omp.h>
 
#include <stdio.h>
#include <stdlib.h>

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
 
int main(int argc, char* argv[])
{
    
    float SSD_size = 3.5; // SSD total size in terabyte
    float fill_rate = 0.95; // how full do you want the SSD
    int num_omp_threads = 32;
    int total_file_size = SSD_size*fill_rate*1024*1024; // total file size in MB
    int thread_file_size = total_file_size/num_omp_threads; // file size for each thread in MB
    int thread_num_int_K = thread_file_size *1024 / 4;

    string fname = "/mnt/SmartSSD/fill";

    printf("Writing %d MB files with %d threads to %s, each thread write %dMB equal to %d K ints\n", total_file_size, num_omp_threads, fname, thread_file_size, thread_num_int_K);

    // Beginning of parallel region
    #pragma omp parallel num_threads(num_omp_threads)
    {
 
        printf("Writing from thread = %d\n",
               omp_get_thread_num());
        
        ofstream file;
        file.open(fname+to_string(omp_get_thread_num()));
        
        for (int i = 0; i<thread_num_int_K; i++) {
            for (int j =0; j < 1024; j++)
                file<<i;
        }
        // printf("Rank %d Test size is %d\n", omp_get_thread_num(), j[N%arr_size-1]);
        
    }
    // Ending of parallel region
}