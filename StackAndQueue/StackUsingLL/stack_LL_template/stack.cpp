#include <iostream>
#include "stack_template_linkedList.h"

int main() {
    Stack<int> s1;
    std::cout << s1.isEmpty() << std::endl;
    std::cout << s1.getSize() << std::endl;
    std::cout << s1.top() << std::endl;
    std::cout << s1.pop() << std::endl;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    std::cout << s1.top() << std::endl;
    std::cout << s1.pop() << std::endl;
    std::cout << s1.pop() << std::endl;
    std::cout << s1.pop() << std::endl;
    std::cout << s1.isEmpty() << std::endl;
    std::cout << s1.getSize() << std::endl;

    return 0;
}