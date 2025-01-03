#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

void print_matrix( int **matrix, int size )
{
  int i, j;

  for (i = 0; i < size; ++i) {
    for (j = 0; j < size-1; ++j) {
      printf( "%d, ", matrix[ i ][ j ] );
    }
    printf( "%d", matrix[ i ][ j ] );
    putchar( '\n' );
  }
}



int main(int argc, char *argv[]) {
    int size, num_threads;
    double start_time, end_time;
    

    size = atoi(argv[1]);
    num_threads = atoi(argv[2]);

    int **matrix1 = (int **)malloc(size * sizeof(int *));
    int **matrix2 = (int **)malloc(size * sizeof(int *));
    int **matrix3 = (int **)malloc(size * sizeof(int *));

    for (int i = 0; i < size; ++i) {
        matrix1[i] = (int *)malloc(size * sizeof(int));
        matrix2[i] = (int *)malloc(size * sizeof(int));
        matrix3[i] = (int *)malloc(size * sizeof(int));
    }

    srand(time(NULL));

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix1[i][j] = rand() % 100 + 1;
            matrix2[i][j] = rand() % 100 + 1;
        }
    }
    
    int i;
   start_time = omp_get_wtime();
    #pragma omp parallel for num_threads(num_threads) schedule(guided, 1)
    for(i=0; i<size ;i++){
        
        for(int j=0; j<size;j++){
                
            int sum = 0;
            for (int k = 0; k < size; ++k) {
                    
                sum += matrix1[i][k] * matrix2[k][j];
            }
            matrix3[i][j] = sum;
        }
            
        
    }
        end_time = omp_get_wtime();
    
    
    
    if ( size <= 16 ) {
    printf( "Matrix 1:\n" );
    print_matrix( matrix1, size );
    printf( "Matrix 2:\n" );
    print_matrix( matrix2, size );
  }
  if ( size <= 16 ) {
    printf( "Matrix 3:\n" );
    print_matrix( matrix3, size );
  }

    

    //printf("Number of threads: %d\t", num_threads);
    //printf("Execution time: %.3lf ms\n", (end_time - start_time) * 1000);
      printf("%.3lf\n", (end_time - start_time) * 1000);

    // Free memory
    for (int i = 0; i < size; ++i) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(matrix3[i]);
    }
    free(matrix1);
    free(matrix2);
    free(matrix3);

    return 0;
}