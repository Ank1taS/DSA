// time complexity - O(n * m)
// space complexity - O(n * m)


#include <iostream>
#include <cstring>
using namespace std;


int editDistance(string s1, string s2) {
    int size1 {s1.size()};
    int size2 {s2.size()};

	int **arr {new int*[size1 + 1]};
    for (int i {0}; i <= size1; ++i) {
        arr[i] = new int[size2 + 1];
    }

    // initialising [0][0] index with 0
    arr[0][0] = 0;

    // initialise 1st row with coresponding col value
    for (int i {1}; i <= size2; ++i) {
        arr[0][i] = i;
    }

    // initialise 1st col with coresponding row value
    for (int i {1}; i <= size1; ++i) {
        arr[i][0] = i;
    }

    for (int i {1}; i <= size1; ++i) {
        for (int j {1}; j <= size2; ++j) {

            if (s1[size1 - i] == s2[size2 - j]) {
                arr[i][j] = arr[i - 1][j - 1];
            }
            else {
             arr[i][j] = 1 + min(arr[i - 1][j], min(arr[i][j - 1], arr[i - 1][j - 1]));

            }
        }
    }

    int result{arr[size1][size2]};
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