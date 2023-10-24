#include <stdio.h>
#include <stdbool.h>

#define SIZE 24
#define nRows 8
#define nCols 3

// PROTOTYPES
void print_array(int array[], int length);
void print_matrix(int mat[][nCols], int rows);
void set_array(int arr[], int length);
void rem_align(int arr[], int length, int pos);
void insert_align(int arr[], int length, int pos, int value);
void reshape(int arr[], int length, int arr2d[][nCols], int Rows, int Cols);
bool found_duplicate(int arr[], int length);
void flip_array(int arr[], int length);

int main() {
    int arr[SIZE];
    int arr2d[nRows][nCols];
    int pos = 3;
    int value = 66;
    // print_matrix(arr2d, nRows);

    // Call to different functions
    set_array(arr, SIZE);

    // rem_align(arr, SIZE, pos);
    // insert_align(arr, SIZE, pos, value);
    // reshape(arr, SIZE, arr2d, nRows, nCols);
    // found_duplicate(arr, SIZE);
    // flip_array(arr, SIZE);

    return 0;
}

void print_array(int array[], int length) {
    for (int i = 0; i < length; i++)
        printf("array[%d] = %d\n", i, array[i]);
}

void print_matrix(int mat[][nCols], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < nCols; j++)
            printf("mat[%d][%d] = %d\n", i, j, mat[i][j]);
        puts("");
    }
}

// FUNCTION DEFINITIONS

void set_array(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        arr[i] = i;
    }
}

void rem_align(int arr[], int length, int pos) {
    if (pos < 0 || pos >= length) {
        printf("Invalid array index\n");
        return;
    }

    for (int i = pos; i < length - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[length - 1] = 0; // Optional: Clear the last element

    for (int i = 0; i < length; i++) {
        printf("%d\n", arr[i]);
    }
}

void insert_align(int arr[], int length, int pos, int value) {
    if (pos < 0 || pos >= length) {
        printf("Invalid array index\n");
        return;
    }

    for (int i = length; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = value;

    for (int i = 0; i < length; i++) {
        printf("%d\n", arr[i]);
    }
}

void reshape(int arr[], int length, int arr2d[][nCols], int Rows, int Cols) {
    if (length != nRows * nCols) {
        printf("Error: The length of the 1-D array does not match the dimensions of the 2-D array.\n");
        return;
    }

    int k = 0; // Index for the 1-D array

    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            arr2d[i][j] = arr[k];
            k++;
        }
    }

    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            printf("%d ", arr2d[i][j]);
        }
        printf("\n");
    }
}

bool found_duplicate(int arr[], int length) {

    // arr[3] = arr[4];
    
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (arr[i] == arr[j]) {
                printf("Duplicate value found: %d\n", arr[i]);
                return true;
            }
        }
    }
    printf("No duplicates found.\n");
    return false;
}

void flip_array(int arr[], int length) {
    for (int i = 0; i < length / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[length - 1 - i];
        arr[length - 1 - i] = temp;
    }

    for (int i = 0; i < length; i++) {
        printf("%d\n", arr[i]);
    }
}