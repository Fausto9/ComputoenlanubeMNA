// SolucionSumaArreglosParalela.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <omp.h>
using namespace std;

const int ARRAY_SIZE = 10;

void sumArrays(int A[], int B[], int C[]) {
    // Parallel for loop to sum the elements of A and B
#pragma omp parallel for
    for (int i = 0; i < ARRAY_SIZE; i++) {
        C[i] = A[i] + B[i];
    }
}

int main() {
    int A[ARRAY_SIZE], B[ARRAY_SIZE], C[ARRAY_SIZE];

    // Initialize the arrays with random values
    for (int i = 0; i < ARRAY_SIZE; i++) {
        A[i] = rand() % 1000 + 1;
        B[i] = rand() % 1000 + 1;
    }

    // Print the initial arrays
    cout << "Array A: ";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    cout << "Array B: ";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << B[i] << " ";
    }
    cout << endl;

    // Sum the arrays
    sumArrays(A, B, C);

    // Print the final array
    cout << "Array C (sums A and B): ";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    return 0;
}
