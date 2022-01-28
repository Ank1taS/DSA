#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
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

    bool insertWord(TrieNode *root, string word) {
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
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }

    // search word in tries
    private:
    TrieNode* search(string word, TrieNode *root) {
        // base case
        if (word.size() == 0) {
            return root;
        }

        // small calculation
        int index {word[0] - 'a'};
        
        if (root->children[index] == nullptr) {
            return nullptr;
        }
        
        TrieNode *child {root->children[index]};
        return search(word.substr(1), child);
        
    }

    public:
    TrieNode* search(string word) {
        // Write your code here
        return search(word, root);
    }

    // to create and print possible words  which can be formed using the incomplete word w.
    void possibleWordFormation(TrieNode *root, string pattern, string outPut) {
        if (root->isTerminal == true) {
            cout << pattern << outPut << endl;
        }
        for (int i {0}; i < 26; ++i) {
            if (root->children[i] != nullptr) {
                possibleWordFormation(root->children[i], pattern, outPut + root->children[i]->data);
            }
        }

        return;
    }
    

    void autoComplete(vector<string> input, string pattern) {
        // insert words to tries
        for (auto temp: input) {
            insertWord(temp);
        }

        // serach for pattern in tries
        TrieNode *startNode {search(pattern)};
        if (startNode == nullptr) {
            return;
        }

        // vector to store all possible strings/words having pattern
        possibleWordFormation(startNode, pattern, "");
        
    }
};

int main() {
    Trie t;
    int n;
    cin >> n;

    vector<string> vect;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }

    string pattern;
    cin >> pattern;

    t.autoComplete(vect, pattern);

    return 0;
}