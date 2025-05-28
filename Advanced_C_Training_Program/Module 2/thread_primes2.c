#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include <signal.h>

int N;
volatile sig_atomic_t keepRunning = 1;

// SIGINT handler (Ctrl+C)
void sigint_handler(int sig) {
    printf("\nSIGINT received (Ctrl+C ignored). Use proper termination.\n");
}

// Time helper
double get_time_diff(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
}

// Prime check
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i*i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Thread A: Compute sum of first N prime numbers
void* threadA_function(void* arg) {
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);

    printf("Thread A started.\n");

    int count = 0, num = 2, sum = 0;
    while (count < N && keepRunning) {
        if (isPrime(num)) {
            sum += num;
            count++;
        }
        num++;
    }

    clock_gettime(CLOCK_REALTIME, &end);
    printf("Thread A: Sum of first %d prime numbers = %d\n", N, sum);
    printf("Thread A completed in %.3f seconds.\n\n", get_time_diff(start, end));
    pthread_exit(NULL);
}

// Thread B: Every 2 seconds for 100 seconds
void* threadB_function(void* arg) {
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);

    printf("Thread B started.\n");

    int elapsed = 0;
    while (elapsed < 100 && keepRunning) {
        printf("Thread 1 running (TID: %lu)\n", pthread_self());
        sleep(2);
        elapsed += 2;
    }

    clock_gettime(CLOCK_REALTIME, &end);
    printf("Thread B completed in %.3f seconds.\n\n", get_time_diff(start, end));
    pthread_exit(NULL);
}

// Thread C: Every 3 seconds for 100 seconds
void* threadC_function(void* arg) {
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);

    printf("Thread C started.\n");

    int elapsed = 0;
    while (elapsed < 100 && keepRunning) {
        printf("Thread 2 running (TID: %lu)\n", pthread_self());
        sleep(3);
        elapsed += 3;
    }

    clock_gettime(CLOCK_REALTIME, &end);
    printf("Thread C completed in %.3f seconds.\n\n", get_time_diff(start, end));
    pthread_exit(NULL);
}

// Main
int main() {
    signal(SIGINT, sigint_handler); // Set signal handler

    pthread_t tA, tB, tC;

    printf("Enter value of N: ");
    scanf("%d", &N);

    printf("\nLaunching threads...\n");

    pthread_create(&tA, NULL, threadA_function, NULL);
    pthread_create(&tB, NULL, threadB_function, NULL);
    pthread_create(&tC, NULL, threadC_function, NULL);

    pthread_join(tA, NULL);
    pthread_join(tB, NULL);
    pthread_join(tC, NULL);

    printf("All threads finished successfully.\n");
    return 0;
}
