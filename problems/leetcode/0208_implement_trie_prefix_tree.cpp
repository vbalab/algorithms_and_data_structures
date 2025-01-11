#include <iostream>
#include <string>
#include <unordered_map>

class Trie {
public:
    Trie() {
    }

    void insert(std::string word) {
        Trie* trie = this;

        for (char c: word) {
            if (!trie->chars.contains(c)) {
                trie->chars[c] = new Trie();
            }

            trie = trie->chars[c];
        }

        trie->has_word = true;
    }

    bool search(std::string word) {
        Trie* trie = this;

        for (char c: word) {
            if (!trie->chars.contains(c)) {
                return false;
            }

            trie = trie->chars[c];
        }

        return trie->has_word;
    }

    bool startsWith(std::string prefix) {
        Trie* trie = this;

        for (char c: prefix) {
            if (!trie->chars.contains(c)) {
                return false;
            }

            trie = trie->chars[c];
        }

        return true;
    }

protected:
    std::unordered_map<char, Trie*> chars;
    bool has_word = false;
};
