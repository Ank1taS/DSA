// Given a string S, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same, as in the input string.


#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string uniqueChar(string str) {
    if (str.empty() == true) {
        return str;
    }
	
    string temp;
	unordered_map<char, bool> mp;
    
    for (int i {0}; i < str.size(); ++i) {
        if (mp.count(str.at(i)) == 0) {
            mp[str.at(i)] = true;
            temp += str.at(i);
        }        
    }   

    return temp;
}

int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}
