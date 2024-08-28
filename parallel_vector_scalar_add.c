#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

int main() {
    int n = 1000000; // Size of the vector
    float scalar = 5.0;
    int thread = 12;
    omp_set_num_threads(thread);

    // Allocate memory for the vector
    float *vector = (float *)malloc(n * sizeof(float));

    // Initialize the vector with random values
    for (int i = 0; i < n; i++) {
        vector[i] = (float)rand() / RAND_MAX;
    }

    // Get start time
    double start_time = omp_get_wtime();

    // Vector scalar addition (parallel)
    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        vector[i] += scalar;
    }

    // Get end time
    double end_time = omp_get_wtime();
    
    printf("No. of Threads: %d\n",thread);
    printf("Time taken (Parallel): %f seconds\n", end_time - start_time);

    // Free the allocated memory
    free(vector);

    return 0;
}
