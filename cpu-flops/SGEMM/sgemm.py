import time
import numpy as np

N = 4096

# Single precision GEneral Matrix Multiply (SGEMM)
if __name__ == "__main__":
    # N x N matrix
    A = np.random.randn(N, N).astype(np.float32)

    # N x N matrix
    B = np.random.randn(N, N).astype(np.float32)

    # N * N multiplications * 2 (for A and B)
    flop = 2 * N * N * N

    for i in range(100):
        start = time.monotonic()
        C = A @ B
        end = time.monotonic()
        print(f"{flop / (end - start) / 1e9:.2f} GFLOP/S")
