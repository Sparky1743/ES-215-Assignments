#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <vector>

using namespace std;

long long fibo_iterative_memoized(int n, vector<long long> &memo) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    memo[0] = 0;
    memo[1] = 1;

    for (int i = 2; i <= n; i++) {
        memo[i] = memo[i - 1] + memo[i - 2];
    }

    return memo[n];
}

int main(){
    vector <long long> answer(50 + 1, -1);
    struct timespec start, end;

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

    fibo_iterative_memoized(50, answer);

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);

    // time taken
    long long seconds = end.tv_sec - start.tv_sec;
    long long nanoseconds = end.tv_nsec - start.tv_nsec;
    if (nanoseconds < 0) {
        seconds--;
        nanoseconds += 1000000000L;
    }

    printf("%s took %lld.%09lld seconds\n\n", "iterative memoized implementation", seconds, nanoseconds);

    printf("The first 50 fibonacci numbers are:\n");

    fibo_iterative_memoized(50, answer);
    for (int i = 2; i < answer.size(); i ++){
        printf("%lld", answer[i]);
        printf(" ");
    }
}