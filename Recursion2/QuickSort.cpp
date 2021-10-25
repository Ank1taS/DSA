// Sort an array A using Quick Sort.

#include<iostream>
using namespace std;

void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

int partition(int *input, int start, int end) {
    int pivot = start;
    int count = 0;

    // to count numbers of smaller elements then pivot element
    for (int i = start + 1; i <= end; ++i) {
        if (input[pivot] >= input[i]) {
            ++count;
        }
    }

    // swapping pivot element to appropiate pivot index 
    swap(input[pivot], input[pivot + count]);

    // update pivot
    pivot += count;

    // store all smaller element to left of pivot element and all greater elements to the right if pivot element
    int i = start;
    int j = end;

    while (i < pivot && j > pivot) {
        if (input[i] <= input[pivot]) {
            ++i;
        }
        else if (input[j] > input[pivot]) {
            --j;
        }
        else {
            swap(input[i], input[j]);
            ++i;
            --j;
        }
    }

    return pivot;
}

void quickSort(int input[], int start, int end) {
    if (start >= end) {
        return;
    }

    int pivot = partition(input, start, end);

    quickSort(input, start, pivot - 1);
    quickSort(input, pivot + 1, end);
}

void quickSort(int input[], int size) {
    quickSort(input, 0, size - 1);
}

int main() {
    int n;
    cin >> n;
  
    int *input = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);

    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

    return 0;
}
