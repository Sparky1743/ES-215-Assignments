#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <vector>

using namespace std;

long long fibo_iterative(long long n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    long long n_minus_one = 1;
    long long n_minus_two = 0;
    long long n_th_term;

    for (int i = 2; i <= n; i++) {
        n_th_term = n_minus_one + n_minus_two;
        n_minus_two = n_minus_one;
        n_minus_one = n_th_term;
    }

    return n_th_term;
}

vector <long long> n_fibo_iterative(int n){
    vector <long long> n_fibo_numbers;
    for (int i = 1; i < n + 1; i ++){
        n_fibo_numbers.push_back(fibo_iterative(i));
    }
    return n_fibo_numbers;
}

int main(){
    struct timespec start, end;

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

    n_fibo_iterative(50);

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);

    // time taken
    long long seconds = end.tv_sec - start.tv_sec;
    long long nanoseconds = end.tv_nsec - start.tv_nsec;
    if (nanoseconds < 0) {
        seconds--;
        nanoseconds += 1000000000L;
    }

    printf("%s took %lld.%09lld seconds\n\n", "iterative implementation", seconds, nanoseconds);

    printf("The first 50 fibonacci numbers are:\n");

    vector <long long> answer = n_fibo_iterative(50);
    for (int i = 0; i < answer.size(); i ++){
        printf("%lld", answer[i]);
        printf(" ");
    }
}