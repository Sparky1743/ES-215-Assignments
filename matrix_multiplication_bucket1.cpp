#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

// integer matrices
void multiplyIntegerMatrices(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2, vector<vector<int>>& result, int dimension) {
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            result[i][j] = 0;
            for (int k = 0; k < dimension; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// double matrices
void multiplyFloatingPointMatrices(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2, vector<vector<double>>& result, int dimension) {
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            result[i][j] = 0.0;
            for (int k = 0; k < dimension; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// print time duration
void displayTime(const struct timespec& startTime, const struct timespec& endTime, const string& message) {
    double elapsedTime = (endTime.tv_sec - startTime.tv_sec) * 1e9;
    elapsedTime = (elapsedTime + (endTime.tv_nsec - startTime.tv_nsec)) * 1e-9;
    cout << message << fixed << elapsedTime << setprecision(9) << " seconds" << endl;
}

int main() {
    int dimensions[] = {64, 128, 256, 512, 1024};
    
    for (int dim : dimensions) {
        struct timespec systemStartTime, systemEndTime, cpuStartTime, cpuEndTime;

        // system and CPU times
        clock_gettime(CLOCK_MONOTONIC, &systemStartTime);
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &cpuStartTime);

        vector<vector<int>> matrixInt1(dim, vector<int>(dim, 1));
        vector<vector<int>> matrixInt2(dim, vector<int>(dim, 1));
        vector<vector<int>> matrixIntResult(dim, vector<int>(dim, 0));

        // matrix multiplication time
        struct timespec multiplyStartTime, multiplyEndTime;
        clock_gettime(CLOCK_MONOTONIC, &multiplyStartTime);

        // integer matrix multiplication
        multiplyIntegerMatrices(matrixInt1, matrixInt2, matrixIntResult, dim);

        clock_gettime(CLOCK_MONOTONIC, &multiplyEndTime);

        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &cpuEndTime);
        clock_gettime(CLOCK_MONOTONIC, &systemEndTime);

        cout << "Dimension=" << dim << ", Integer Matrix Multiplication: " << endl;
        displayTime(systemStartTime, systemEndTime, "System Time: ");
        displayTime(cpuStartTime, cpuEndTime, "CPU Time: ");
        displayTime(multiplyStartTime, multiplyEndTime, "Multiplication Time: ");
        
        clock_gettime(CLOCK_MONOTONIC, &systemStartTime);
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &cpuStartTime);
        
        vector<vector<double>> matrixFloat1(dim, vector<double>(dim, 1.0));
        vector<vector<double>> matrixFloat2(dim, vector<double>(dim, 1.0));
        vector<vector<double>> matrixFloatResult(dim, vector<double>(dim, 0.0));

        clock_gettime(CLOCK_MONOTONIC, &multiplyStartTime);

        // floating-point matrix multiplication
        multiplyFloatingPointMatrices(matrixFloat1, matrixFloat2, matrixFloatResult, dim);

        clock_gettime(CLOCK_MONOTONIC, &multiplyEndTime);

        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &cpuEndTime);
        clock_gettime(CLOCK_MONOTONIC, &systemEndTime);

        cout << "Dimension=" << dim << ", Floating-Point Matrix Multiplication: " << endl;
        displayTime(systemStartTime, systemEndTime, "System Time: ");
        displayTime(cpuStartTime, cpuEndTime, "CPU Time: ");
        displayTime(multiplyStartTime, multiplyEndTime, "Multiplication Time: ");
    }

    return 0;
}
