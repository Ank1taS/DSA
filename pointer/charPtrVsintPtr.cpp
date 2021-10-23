// char pointer vs int pointer

#include <iostream>

int main() {
    std::cout << "\n============================\n" << std::endl;

    // char[] vs int[]
    int numArr[5] {10, 20, 30};
    char chArr[] = "abc";

    std::cout << numArr << std::endl;   // prints address of numArr or &numArr[0]       : 0x61fe00
    std::cout << chArr  << std::endl;   // prints every character of array untill '\0'  : abc

    char* chPtr = chArr;
    // char* chPtr = &(chArr[0]);       // works similarly
    std::cout << chPtr << std::endl;    // prints every character of array untill '\0'  : abc

    std::cout << "\n============================\n" << std::endl;
    // char vs char*
    char c {'a'};
    char* cptr = &c;

    std::cout << c << std::endl;        // prints : a
    std::cout << cptr << std::endl;     // prints : a___ untill found '\0'

    std::cout << "\n============================\n" << std::endl;
    char arr[] {"abcde"};       // here a temporary memory is allocated for "abcde" and 
                                // then allocates memory of size as temp then contains of the temp memory is copied to the memory. Now this new allocation is for arr.
    
    char* arrPtr {"abcde"};     //  warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]
                                // here a temporary memory is allocated for "abcde" and
                                // then arrptr will point to that temp address . It might be previlaged address or anything and might act unpredictably
    
    std::cout << arr << std::endl;          // abcde
    std::cout << arrPtr << std::endl;       // abcde

    return 0;
}