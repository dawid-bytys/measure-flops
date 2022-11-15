#include <chrono>
#include <iostream>

#define N 1024

void dgemm(double* A, double* B, double* C);

int main() {
  double* A = new double[N * N];
  double* B = new double[N * N];
  double* C = new double[N * N];
  double flop = 2.0 * N * N * N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      A[i * N + j] = 1.0;
      B[i * N + j] = 1.0;
    }
  }

  for (int i = 0; i < N; i++) {
    auto start = std::chrono::steady_clock::now();
    dgemm(A, B, C);
    auto end = std::chrono::steady_clock::now();

    double diff = std::chrono::duration<double>(end - start).count();

    printf("%f GFLOP/S", flop / diff / 1e9);
  }

  return 0;
}

void dgemm(double* A, double* B, double* C) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        C[i * N + j] += A[i * N + k] * B[k * N + j];
      }
    }
  }
}