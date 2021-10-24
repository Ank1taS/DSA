// Sort an array A using Merge Sort.


#include <iostream>
using namespace std;

void merge(int *input, int size) {
    int leftSize = size / 2;
    int rightSize = size - leftSize;

    int* left  = new int[leftSize];
    int* right = new int[rightSize];

    for (int i = 0; i < leftSize; ++i) {
        left[i] = input[i];
    }

    for (int i = 0; i < rightSize; ++i) {
        right[i] = input[leftSize + i];
    }

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            input[k++] = left[i++];
        }
        else {
            input[k++] = right[j++]; 
        }
    }

    while (i < leftSize) {
        input[k++] = left[i++];
    }

    while (j < rightSize) {
        input[k++] = right[j++];
    }
}

void mergeSort(int input[], int size){
    if (size <= 1) {
        return;
    }        

    int leftArrSize  = size / 2;
    int rightArrSize = size - leftArrSize;

    mergeSort(input, leftArrSize);
    mergeSort(input + leftArrSize , rightArrSize);

    merge(input, size);
}

int main() {
    int length;

    cin >> length;
    
    int* input = new int[length];
    
    for(int i=0; i < length; i++)
      cin >> input[i];
    
    mergeSort(input, length);
    
    for(int i = 0; i < length; i++) {
      cout << input[i] << " ";
    }

    return 0;
}