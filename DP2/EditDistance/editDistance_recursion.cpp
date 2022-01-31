#include <cstring>
#include <iostream>
using namespace std;

int editDistance(string s1, string s2) {
    // base case
    // if either of the strings is empty then 
    //insertion opearation will be perform for rest of elements remained in another string. So max smae numbers of op will be perform as the remaining elements
    // or delete all element remain in the string and for it total n operation will be performed    
    if (s1.size() == 0 || s2.size() == 0) {
        return max(s1.size(), s2.size());
    }   

    int result;

    // if 1st character of both the strings matches then no operation needed no this step
    if (s1[0] == s2[0]) {
        result = editDistance(s1.substr(1), s2.substr(1));
    }
    else {
        // insert [0] element of s1 in s2
        int a {editDistance(s1.substr(1), s2)};
        // delete [0] element of s2
        int b {editDistance(s1, s2.substr(1))};
        // replace [0] element of s2 with [0] of s1
        int c {editDistance(s1.substr(1), s2.substr(1))};

        result = 1 + min(a, min(b, c));
    }

    return result;
}

int main() {
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2);
}