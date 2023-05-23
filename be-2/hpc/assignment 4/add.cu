#include <iostream>
#include <cstdlib>
#include <cuda_runtime.h>

const int VECTOR_SIZE = 1000000;

__global__ void vectorAdd(const int* a, const int* b, int* c, int size)
{
    int tid = blockIdx.x * blockDim.x + threadIdx.x;

    if (tid < size)
    {
        c[tid] = a[tid] + b[tid];
    }
}

int main()
{
    // Allocate memory for host vectors
    int* h_a = new int[VECTOR_SIZE];
    int* h_b = new int[VECTOR_SIZE];
    int* h_c = new int[VECTOR_SIZE];

    // Initialize host vectors with random values
    for (int i = 0; i < VECTOR_SIZE; ++i)
    {
        h_a[i] = std::rand() % 100;
        h_b[i] = std::rand() % 100;
    }

    // Allocate memory for device vectors
    int* d_a, * d_b, * d_c;
    cudaMalloc(&d_a, VECTOR_SIZE * sizeof(int));
    cudaMalloc(&d_b, VECTOR_SIZE * sizeof(int));
    cudaMalloc(&d_c, VECTOR_SIZE * sizeof(int));

    // Copy input data from host to device
    cudaMemcpy(d_a, h_a, VECTOR_SIZE * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b, VECTOR_SIZE * sizeof(int), cudaMemcpyHostToDevice);

    // Launch the vector addition kernel
    int threadsPerBlock = 256;
    int blocksPerGrid = (VECTOR_SIZE + threadsPerBlock - 1) / threadsPerBlock;
    vectorAdd<<<blocksPerGrid, threadsPerBlock>>>(d_a, d_b, d_c, VECTOR_SIZE);

    // Copy the result from device to host
    cudaMemcpy(h_c, d_c, VECTOR_SIZE * sizeof(int), cudaMemcpyDeviceToHost);

    // Print the first few elements of the resulting vector
    for (int i = 0; i < 10; ++i)
    {
        std::cout << h_c[i] << " ";
    }
    std::cout << std::endl;

    // Free device memory
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

    // Free host memory
    delete[] h_a;
    delete[] h_b;
    delete[] h_c;

    return 0;
}
