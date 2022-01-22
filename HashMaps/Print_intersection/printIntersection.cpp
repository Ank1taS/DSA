// Code : Print Intersection

// You have been given two integer arrays/lists (ARR1 and ARR2) of size N and M, respectively. You need to print their intersection; An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in both the arrays/lists.

// Note :
// Input arrays/lists can contain duplicate elements.

// The intersection elements printed would be in the order they appear in the first sorted array/list (ARR1).
//========================================================================================================================================================================================================================================================================================================================================

#include <iostream>
#include<unordered_map>
using namespace std;

void printIntersection(int arr1[], int arr2[], int n, int m) {
    // unordered map to store elements of arr2 as The intersection elements printed would be in the order they appear in the first sorted array/list (ARR1)
    // key - element , value - frequency of the element
    unordered_map<int, int> mp;

    for (int i {0}; i < m; ++i) {
        mp[arr2[i]]++;
    }

    for (int i {0}; i < n; ++i) {
        if (mp.count(arr1[i]) > 0) {
            --mp[arr1[i]];
            cout << arr1[i] << endl;
        }
    }
}

int main() {
    int n, m;
    cin >> n;

    int* arr1 = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }
    cin >> m;

    int* arr2 = new int[m];

    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }

    printIntersection(arr1, arr2, n, m);

    delete[] arr1;
    delete[] arr2;

}
