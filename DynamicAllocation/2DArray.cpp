// 2D array Dynamic memory allocation.

#include <iostream>

int main() {
    int row, col;

    std::cout << "Enter row and column : ";
    std::cin >> row >> col;

    int** arr = new int*[row];
    for (size_t i = 0; i < row; ++i) {
        arr[i] = new int[col];
        
        for (size_t j = 0; j < col; ++j) {
            std::cin >> arr[i][j];
        }
    } 

    // display
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            std::cout << *(*(arr + i) + j) << "  ";
        }
        std::cout << std::endl;
    }

    // dealloction
    for(size_t i = 0; i < row; ++i) {
        delete [] arr[i];
    }
    delete [] arr;

    return 0;
}