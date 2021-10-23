// array vs pointers
#include <iostream>

int main() {
    int arr[10];
    int *ptr = &arr[0];

    std::cout << sizeof(arr) << std::endl;
    std::cout << sizeof(ptr) << std::endl;
    

    // In Symbol table address entry for a varriable is const.
    // for pointers separate 8bytes of memory is allocated and that contains address of another varriable 
    // but for array no separate memory is allocated 
    // no separate memory allocates for a array so   : address of array = address stored in array
    // Separate memory allocates for pointer so      : address of pointer (&p) != address strored in pointer (p)  
    std::cout << arr << std::endl;
    std::cout << ptr << std::endl;
    std::cout << &arr[0] << std::endl;
    std::cout << &ptr << std::endl;

    *(arr) = 10;
    *(arr + 1) = 20;
    *(arr + 2) = 30;

    std::cout << *arr << std::endl;
    std::cout << *ptr << std::endl;

    ptr += 1;
    // arr += 1;    error: incompatible types in assignment of 'int' to 'int [10]'

    std::cout << *arr << std::endl;
    std::cout << *ptr << std::endl;

    return 0;
}