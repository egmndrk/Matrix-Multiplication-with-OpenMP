# Matrix Multiplication with OpenMP

A parallel matrix multiplication implementation comparing different OpenMP scheduling strategies (Static, Dynamic, Guided) on multi-core systems.

## Implementation Details

- Written in C using OpenMP library
- Supports variable matrix sizes and thread counts
- Implements three scheduling types:
  - Static: Equal-sized chunks assigned to threads. Syntax: #pragma omp parallel for schedule(static, chunk_size)
  - Dynamic: Chunks dynamically assigned as threads become available. Syntax: #pragma omp parallel for schedule(dynamic, chunk_size)
  - Guided: Variable chunk sizes that decrease over time. Syntax: #pragma omp parallel for schedule(guided, chunk_size)

## Requirements

- GCC compiler with OpenMP support
- Linux/Unix environment
- 8-core processor (optimized for)

## Compilation

```bash
gcc -fopenmp MatrixMultiplication.c -o matrix_mult
```

## Usage

```bash
./matrix_mult [matrix_size] [num_threads]
```

## Performance Analysis

### Key Findings

1. **Speed Up Analysis:**
   - ![image](https://github.com/user-attachments/assets/f1110e70-c360-403f-a286-35319daed9ba)
   - ![image](https://github.com/user-attachments/assets/3b2dfbda-24f8-471f-bdcf-91fd66c828fa)
   - ![image](https://github.com/user-attachments/assets/c75d52f1-97ce-47cd-8a6a-bf132b6e1412)

     The Speed Up analysis, taking into account the 8-core configuration of the system, provides valuable insights into parallel computing performance. Across various matrix multiplication operations, Speed Up generally improves as the number of threads increases from 1 to 8, indicating some level of scalability within the system's core capabilities. However, beyond 8 threads, Speed Up either plateaus or decreases, highlighting the system's limitation in handling additional threads efficiently due to core constraints. This trend is particularly evident in the decreasing Speed Up values for larger thread counts across Static, Guided, and Dynamic scheduling modes. The impact of core limitations on scalability is further reflected in the Efficiency metrics, which also show a decline after 8 threads. This analysis underscores the importance of optimizing thread utilization and selecting suitable scheduling strategies based on the system's core configuration to achieve optimal Speed Up and Efficiency in parallel computing tasks.




2. **Efficiency Metrics:**
   - ![image](https://github.com/user-attachments/assets/99d6e0d5-1b66-4e6b-a171-96b130b34e33)
   - ![image](https://github.com/user-attachments/assets/da6dcb4c-0162-4a84-a394-f03ca4b9c21b)
   - ![image](https://github.com/user-attachments/assets/b15b0fbf-d2fd-4915-8b99-6e1e34a9afc8)

     The choice of scheduling type in OpenMP significantly impacts the efficiency of parallel computations, particularly on systems with a limited number of cores like the 8-core setup in this analysis. The Efficiency values for Static, Guided, and Dynamic scheduling strategies across various matrix multiplication tasks reflect this influence. In the Static scheduling mode, Efficiency initially decreases as the number of threads increases, which is expected on systems with fewer cores due to overheads and less efficient workload distribution. However, as the thread count grows, Static scheduling shows improved Efficiency, indicating better workload balance with larger thread pools within the system's core limitations. Similarly, Guided scheduling exhibits a decline in Efficiency for lower thread counts but experiences notable improvement as thread count approaches the core limit, suggesting a more optimized workload distribution strategy under core constraints. Dynamic scheduling, known for its flexibility, demonstrates mixed Efficiency results across different matrix sizes and thread counts, highlighting the complexity of dynamic workload management on systems with limited cores. These insights emphasize the importance of selecting an appropriate scheduling strategy based on core limitations and workload characteristics to achieve optimal parallel computing



3. **Scalability:**
   The scalability analysis based on Speed Up and Efficiency values for different matrix multiplication operations reveals insights into the performance of parallel computing on the system with 8 cores. As the number of threads increases from 1 to 8, Speed Up generally shows improvements across all scheduling types, indicating some level of scalability. However, beyond 8 threads, the Speed Up values plateau or decrease, suggesting limited scalability due to the system's core constraints. This observation aligns with the Efficiency metrics, which show a noticeable decrease in efficiency after 8 threads across Static, Guided, and Dynamic scheduling modes. The decrease in efficiency beyond 8 threads underscores the impact of core limitations on the system's ability to handle increasing thread counts effectively. Overall, while there is some scalability up to 8 threads, further scalability is limited due to the system's 8-core configuration, highlighting the importance of optimizing workload distribution and selecting appropriate scheduling strategies based on core constraints for better parallel computing performance.

## Memory Management

- Dynamic allocation for matrices
- Proper cleanup to prevent memory leaks
- Supports matrices of various sizes

## Output Format

- Prints execution time in milliseconds
- For matrices ≤ 16x16: Displays input and result matrices
- For larger matrices: Only execution time shown

## Authors

- Egemen Doruk SERDAR

## License

MIT License
