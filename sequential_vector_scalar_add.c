#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    int n = 1000000; // Size of the vector
    float scalar = 5.0;
    // Allocate memory for the vector
    float *vector = (float *)malloc(n * sizeof(float));
    
    // Initialize the vector with random values
    for (int i = 0; i < n; i++) {
        vector[i] = (float)rand() / RAND_MAX;
    }

    // Get start time
    double start_time = omp_get_wtime();
    
    // Vector scalar addition (sequential)
    for (int i = 0; i < n; i++) {
        vector[i] += scalar;
    }

    // Get end time
    double end_time = omp_get_wtime();
    
    printf("Time taken (Sequential): %f seconds\n", end_time - start_time);

    // Free the allocated memory
    free(vector);

    return 0;
}

