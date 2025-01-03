# Matrix Multiplication with OpenMP

A parallel matrix multiplication implementation comparing different OpenMP scheduling strategies (Static, Dynamic, Guided) on multi-core systems.

## Implementation Details

- Written in C using OpenMP library
- Supports variable matrix sizes and thread counts
- Implements three scheduling types:
  - Static: Equal-sized chunks assigned to threads
  - Dynamic: Chunks dynamically assigned as threads become available
  - Guided: Variable chunk sizes that decrease over time

## Requirements

- GCC compiler with OpenMP support
- Linux/Unix environment
- 8-core processor (optimized for)

## Compilation

```bash
gcc -fopenmp 442hw2.c -o matrix_mult
```

## Usage

```bash
./matrix_mult [matrix_size] [num_threads]
```

## Performance Analysis

### Key Findings

1. **Speed Up Analysis:**
   - Optimal performance with threads matching core count (8)
   - Performance plateaus/decreases beyond 8 threads
   - All scheduling types show improvement up to 8 threads

2. **Efficiency Metrics:**
   - Static: Better efficiency with larger thread pools
   - Guided: Improved efficiency near core limit
   - Dynamic: Mixed results depending on matrix size

3. **Scalability:**
   - Good scaling up to 8 threads
   - Limited scalability beyond core count
   - Best performance when thread count matches available cores

## Memory Management

- Dynamic allocation for matrices
- Proper cleanup to prevent memory leaks
- Supports matrices of various sizes

## Output Format

- Prints execution time in milliseconds
- For matrices ≤ 16x16: Displays input and result matrices
- For larger matrices: Only execution time shown

## Authors

- Egemen Doruk SERDAR (71155167474)
- Dogukan Yetgin (15064119490)

## License

MIT License
