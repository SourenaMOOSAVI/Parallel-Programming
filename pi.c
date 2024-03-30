#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define N 1000000000 // Number of intervals for integration

double calculate_pi_parallel_trapezoidal() {
    double integral = 0.0;
    double dx = 1.0 / N;

    #pragma omp parallel for reduction(+:integral)
    for (long i = 1; i < N; i++) {
        double x = (i - 0.5) * dx;
        double fx = sqrt(1.0 - x * x);
        integral += fx * dx;
    }

    return 4.0 * integral;
}

int main() {
    double pi;
    double start_time, end_time;
    int num_threads;

    // Set the environment variable to control thread affinity
    setenv("GOMP_CPU_AFFINITY", "0-7", 1);
    // Get the maximum number of threads available
    #pragma omp parallel
    {
        #pragma omp master
        {
            num_threads = omp_get_max_threads();
        }
    }
    printf("Maximum number of threads: %d\n", num_threads);

    // Experiment with different numbers of threads
    for (int threads = 1; threads <= num_threads; threads++) {
        // Set the number of threads using the environment variable
        omp_set_num_threads(threads);

        start_time = omp_get_wtime(); // Record the start time

        pi = calculate_pi_parallel_trapezoidal();

        end_time = omp_get_wtime(); // Record the end time

        printf("Threads: %d, Approximation of Pi (Trapezoidal Rule): %.16f, Time taken: %f seconds\n", threads, pi, end_time - start_time);
    }

    return 0;
}