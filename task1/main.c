#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Задано масив 2х15. Відомо, що серед його елементів два та тільки 2 рівні між собою.
 * Надрукувати їх індекси. Програму написати з використання виразів над вказівниками.
 *
 */

const int ROW_SIZE = 2;
const int COLUMN_SIZE = 15;
/**
 * parameter for generate unique number in matrix
 */
const int SHIFT = 7;

int main() {
    int equal_number;
    int *matrix = (int *) malloc(ROW_SIZE * COLUMN_SIZE * sizeof(int)); //allocate size of matrix
    init_matrix(matrix);
    print_matrix(matrix);
    equal_number = insert_number(matrix, 2);
    print_matrix(matrix);
    print_position(matrix, equal_number);

}

/**
 * initialize matrix with unique numbers
 * @param matrix
 */
void init_matrix(int *matrix) {
    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COLUMN_SIZE; j++) {
            matrix[i * COLUMN_SIZE + j] = i + j * SHIFT;
        }
    }
}

/**
 *
 * @param min
 * @param max
 * @return integer random number in range
 */
int get_rand_num_range(int min, int max) {
    return rand() % (max + 1 - min) + min;
}

/**
 * check if element exists in matrix
 * @param matrix
 * @param elem
 * @return boolean
 */
bool is_element_exists(int *matrix, int elem) {
    bool isNumberExist = false;
    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COLUMN_SIZE; j++) {
            isNumberExist = matrix[i * COLUMN_SIZE + j] == elem;
            if (isNumberExist) {
                return isNumberExist;
            }
        }
    }
    return isNumberExist;
}

/**
 * prints row of matrix
 * @param arr
 */
void print_array(int *arr) {
    int *ptr, *lastPtr;
    lastPtr = &arr[COLUMN_SIZE];

    ptr = &arr[0];
    while (ptr != lastPtr) {
        printf("%d\t", *ptr);
        ptr++;
    }
}

/**
 * prints matrix
 * @param matrix
 */
void print_matrix(int *matrix) {
    for (int i = 0; i < ROW_SIZE; i++) {
        print_array(&matrix[i * COLUMN_SIZE]);
        printf("\n");
    }
}

/**
 * Gets a number that is not exists in matrix.
 * @param matrix
 * @return integer
 */
int get_valid_equal_number(int *matrix) {
    int equal_number;
    do {
        printf("Type a number for equality check:\t");
        scanf("%d", &equal_number);
    } while (is_element_exists(matrix, equal_number));
    return equal_number;
}

/**
 * Insert into matrix integer number of insertion_count times
 * @param matrix
 * @param insertion_count
 * @return integer number that was inserted
 */
int insert_number(int *matrix, int insertion_count) {

    int equal_number = get_valid_equal_number(matrix);
    int rand_row_pos, rand_col_pos;
    while (insertion_count) {
        rand_row_pos = get_rand_num_range(0, ROW_SIZE);
        rand_col_pos = get_rand_num_range(0, COLUMN_SIZE);
        //to check that position is correct
        //printf("position x: %d, y: %d\n", rand_row_pos + 1, rand_col_pos + 1);
        if (matrix[rand_row_pos * COLUMN_SIZE + rand_col_pos] == equal_number) {
            continue;
        }
        matrix[rand_row_pos * COLUMN_SIZE + rand_col_pos] = equal_number;
        insertion_count--;
    }
    return equal_number;
}

/**
 * print position of inserted nubers using pointers
 * @param matrix
 * @param elem
 */
void print_position(int *matrix, int elem) {
    int *ptr, *lastPtr;
    int row_num = 0, col_num = 0;
    ptr = &matrix[0];
    lastPtr = &matrix[ROW_SIZE * COLUMN_SIZE - 1];

    while (ptr != lastPtr) {
        if (*ptr == elem) {
            printf("position row: %d, column: %d\n", row_num + 1, col_num + 1);
        }
        if (col_num == COLUMN_SIZE) {
            row_num++;
            col_num = 0;
        }
        ptr++;
        col_num++;
    }
}




