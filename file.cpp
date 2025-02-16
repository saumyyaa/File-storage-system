#include <bits/stdc++.h>
using namespace std;

class Trie {
    struct TrieNode {
        unordered_map<string, TrieNode*> children;
        bool isFile = false;
    };
    TrieNode* root;

public:
    Trie() { root = new TrieNode(); }

    void insert(vector<string> path) {
        TrieNode* node = root;
        for (const string& dir : path) {
            if (!node->children.count(dir))
                node->children[dir] = new TrieNode();
            node = node->children[dir];
        }
        node->isFile = true;
    }

    bool search(vector<string> path) {
        TrieNode* node = root;
        for (const string& dir : path) {
            if (!node->children.count(dir))
                return false;
            node = node->children[dir];
        }
        return node->isFile;
    }
};

int main() {
    Trie cloudStorage;
    cloudStorage.insert({"home", "user", "documents", "file.txt"});
    cloudStorage.insert({"home", "user", "pictures", "photo.jpg"});

    cout << "File found: " << cloudStorage.search({"home", "user", "documents", "file.txt"}) << endl;
    cout << "File found: " << cloudStorage.search({"home", "user", "downloads", "movie.mp4"}) << endl;

    return 0;
}
