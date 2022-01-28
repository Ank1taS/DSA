#include <bits/stdc++.h>
using namespace std;

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word) {
        if (add(root, word)) {
            this->count++;
        }
    }

    // search word in tries
    private:
    bool search(string word, TrieNode *root) {
        // base case
        if (word.size() == 0) {
            return true;
        }

        // small calculation
        int index {word[0] - 'a'};
        
        if (root->children[index] == nullptr) {
            return false;
        }
        
        TrieNode *child {root->children[index]};
        return search(word.substr(1), child);
        
    }

    public:
    bool search(string word) {
        // Write your code here
        return search(word, root);
    }

    /*..................... Palindrome Pair................... */

    bool isPalindromePair(vector<string> words) {
        // Write your code here
        // insert words of vector-words in tries
        for (auto temp : words) {
            while (temp.empty() == false) {
                if (search(temp)) { // true - word already exist
                    break;
                }

                // if word does not exist then insert it
                add(temp);
                // update temp with it's immidiate suffix
                temp = temp.substr(1);
            }
        }

        // pick each word from the vector
        for (auto temp: words) {
            // reverse the picked word 
            reverse(temp.begin(), temp.end());

            // search for reversed word in the tries
            // if found that means palindrome is present, return true
            if(search(temp)) {
                return true;
            }
        }

        // if loops over that means no reverse matches
        return false;
    }
};

int main() {
    Trie t;
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    cout << (t.isPalindromePair(words) ? "true" : "false");
}