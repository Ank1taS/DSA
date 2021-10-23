// Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".

#include <iostream>
#include <cstring>
// #include "solution.h"
using namespace std;

void pairStar(char input[]) {
    int size = strlen(input);

    if (size == 0) {
        return;
    }

    if(input[0] == input[1]) {
        for (int i = size; i >= 1; --i) {
            input[i + 1] = input[i];
        }

        input[1] = '*';
    }

    return pairStar(input + 1);
}


int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;

   return 0;
}
