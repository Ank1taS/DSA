#include <iostream>
#include <cstring>
using namespace std;

int editDistance(string s1, string s2, int **arr) {
    int size1 {s1.size()};
    int size2 {s2.size()};

    // base case
    if (size1 == 0 || size2 == 0) {
        return max(size1, size2);
    }

    // search if result exits
    if (arr[size1][size2] != -1) {
        return arr[size1][size2];
    }

    int result;

    // if result not found then recursive call
    if (s1[0] == s2[0]) {
        result = editDistance(s1.substr(1), s2.substr(1), arr);
    }
    else {
        // insert [0] element of s1 in s2
        int a {editDistance(s1.substr(1), s2, arr)};
        // delete [0] element of s2
        int b {editDistance(s1, s2.substr(1), arr)};
        // replace [0] element of s2 with [0] of s1
        int c {editDistance(s1.substr(1), s2.substr(1), arr)};

        result = 1 + min(a, min(b, c));
    }

    arr[size1][size2] = result;
    return result;
}

int editDistance(string s1, string s2) {
    int size1 {s1.size()};
    int size2 {s2.size()};

	int **arr {new int*[size1 + 1]};
    for (int i {0}; i <= size1; ++i) {
        arr[i] = new int[size2 + 1];
    }

    // initialise arr each index with -1
    for (int i {0}; i <= size1; ++i) {
        for (int j {0}; j <= size2; ++j) {
            arr[i][j] = -1;
        }
    }

    int result{editDistance(s1, s2, arr)};
    for (int i {0}; i <= size1; ++i) {
        delete[] arr[i];
    }

    return result;
}

int main()
{
	string s1;
	string s2;

	cin >> s1;
	cin >> s2;

	cout << editDistance(s1, s2) << endl;
}