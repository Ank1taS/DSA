// inplace heap sort

// time complexity -  O(n logn) 
// space complexity - O(1)

#include <iostream>

// create min heap
// idea is - rearrage element of array with in it self that it will sartisfy the conditions of CBT and min-heap order property.
void createMinHeap(int *arr, int size) {
    int currentIndex {1};

    while (currentIndex < size) {
        int childIndex {currentIndex};

        while (childIndex > 0) {
            int parentIndex {(childIndex - 1) / 2};

            if (arr[parentIndex] > arr[childIndex]) {
                int temp {arr[parentIndex]};
                arr[parentIndex] = arr[childIndex];
                arr[childIndex] = temp;

                childIndex = parentIndex;
            }
            else {
                break;
            }
        }

        ++currentIndex;
    }
}

// sort min-heap by applying remove min element from the array
// The idea is smallest element of min-heap is present at 0th index swap it with the last index. Then we will not delete the last index rather ignore it by reducing the size by 1 so that from next iterartion the last index will not be considered
// Then new 0th index element will be placed at its appropiate position (same logic as remove element) implement down heapify  
void sortMinHeap(int *arr, int size) {
    int lastIndex {size - 1};
    while (lastIndex > 0) {
        int currentIndex {0};

        // swap element bet currentindex (min element) and last index
        int temp {arr[lastIndex]};
        arr[lastIndex] = arr[currentIndex];
        arr[currentIndex] = temp;

        // reduce last index by 1 so that ultimately we will consider size is reduced by 1
        --lastIndex;

        int leftChildIndex {(2 * currentIndex) + 1};
        int rightChildIndex {(2 * currentIndex) + 2};

        while (leftChildIndex <= lastIndex) {
            int minIndex {leftChildIndex};

            if (rightChildIndex <= lastIndex && arr[rightChildIndex] < arr[leftChildIndex]) {
                minIndex = rightChildIndex;
            }

            if (arr[minIndex] < arr[currentIndex]) {
                temp = arr[minIndex];
                arr[minIndex] = arr[currentIndex];
                arr[currentIndex] = temp;

                currentIndex = minIndex;
                leftChildIndex = (2 * currentIndex) + 1;
                rightChildIndex = (2 * currentIndex) + 2; 
            }
            else {
                break;
            }
        }
    }
}

// 1st place each element of given array in apropriate position in order to certisfy min-heap order property
// implement remove min element algorithm to get sorted array
void heapSort(int arr[], int n) {
    // create min-heap (insert)
    createMinHeap(arr, n);
    // sort by implement remove min element of min-heap
    sortMinHeap(arr, n);
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}