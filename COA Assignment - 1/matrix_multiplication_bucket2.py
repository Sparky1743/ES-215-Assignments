import time

def multiply_matrices_int(matrix_a, matrix_b, size): 
    result_matrix = [[0] * size for _ in range(size)] 
    for row in range(size): 
        for col in range(size): 
            for k in range(size): 
                result_matrix[row][col] += matrix_a[row][k] * matrix_b[k][col] 
    return result_matrix 

def multiply_matrices_double(matrix_a, matrix_b, size): 
    result_matrix = [[0.0] * size for _ in range(size)] 
    for row in range(size): 
        for col in range(size): 
            for k in range(size): 
                result_matrix[row][col] += matrix_a[row][k] * matrix_b[k][col] 
    return result_matrix 

matrix_sizes = [64, 128, 256, 512, 1024] 
for size in matrix_sizes: 
    # Timing Integer Matrix Multiplication
    sys_start = time.time() 
    cpu_start = time.process_time() 
    matrix_a_int = [[1] * size for _ in range(size)] 
    matrix_b_int = [[1] * size for _ in range(size)] 
    mult_start = time.time() 
    result_matrix_int = multiply_matrices_int(matrix_a_int, matrix_b_int, size) 
    mult_end = time.time() 
    cpu_end = time.process_time() 
    sys_end = time.time() 
    total_sys_time = sys_end - sys_start 
    total_cpu_time = cpu_end - cpu_start 
    matrix_mult_time = mult_end - mult_start 
    print(f"Size={size}, Integer Matrix Multiplication:") 
    print(f"Total System Time: {total_sys_time:.9f} seconds") 
    print(f"Total CPU Time: {total_cpu_time:.9f} seconds") 
    print(f"Matrix Multiplication Time: {matrix_mult_time:.9f} seconds") 

    # Timing Double Matrix Multiplication
    sys_start = time.time() 
    cpu_start = time.process_time() 
    matrix_a_double = [[1.0] * size for _ in range(size)] 
    matrix_b_double = [[1.0] * size for _ in range(size)] 
    mult_start = time.time() 
    result_matrix_double = multiply_matrices_double(matrix_a_double, matrix_b_double, size) 
    mult_end = time.time() 
    cpu_end = time.process_time() 
    sys_end = time.time() 
    total_sys_time = sys_end - sys_start 
    total_cpu_time = cpu_end - cpu_start 
    matrix_mult_time = mult_end - mult_start 
    print(f"Size={size}, Double Matrix Multiplication:") 
    print(f"Total System Time: {total_sys_time:.9f} seconds") 
    print(f"Total CPU Time: {total_cpu_time:.9f} seconds") 
    print(f"Matrix Multiplication Time: {matrix_mult_time:.9f} seconds")
