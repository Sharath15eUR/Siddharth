#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>

int N;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i*i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Thread A: Computes sum of first N prime numbers
void* sumPrimes(void* arg) {
    int count = 0, num = 2, sum = 0;
    while (count < N) {
        if (isPrime(num)) {
            sum += num;
            count++;
        }
        num++;
    }
    printf("Thread A: Sum of first %d prime numbers = %d\n", N, sum);
    pthread_exit(NULL);
}

// Thread B: Prints every 2 seconds
void* threadB(void* arg) {
    int elapsed = 0;
    while (elapsed < 100) {
        printf("Thread 1 running\n");
        sleep(2);
        elapsed += 2;
    }
    pthread_exit(NULL);
}

// Thread C: Prints every 3 seconds
void* threadC(void* arg) {
    int elapsed = 0;
    while (elapsed < 100) {
        printf("Thread 2 running\n");
        sleep(3);
        elapsed += 3;
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t tA, tB, tC;

    printf("Enter value of N: ");
    scanf("%d", &N);

    // Create threads
    pthread_create(&tA, NULL, sumPrimes, NULL);
    pthread_create(&tB, NULL, threadB, NULL);
    pthread_create(&tC, NULL, threadC, NULL);

    // Wait for threads to finish
    pthread_join(tA, NULL);
    pthread_join(tB, NULL);
    pthread_join(tC, NULL);

    printf("All threads completed.\n");
    return 0;
}
