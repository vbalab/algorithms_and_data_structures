#include <string>
#include <vector>
#include <cstdint>
#include <iostream>
#include <algorithm>
#include <unordered_map>

class PrefixTree {
public:
    PrefixTree() {}

    PrefixTree(const std::vector<std::string>& strs) {
        for (const std::string& str: strs) {
            Insert(str);
        }
    }

    void Insert(const std::string& str, int32_t n = 0) {
        if (str.size() == n) {
            return;
        }

        char chr = str[n];

        if (!mapa_.contains(chr)) {
            mapa_[chr] = new PrefixTree();
        }

        if (mapa_[chr]->results_.size() < 3) {
            mapa_[chr]->results_.push_back(str);
        }

        mapa_[chr]->Insert(str, ++n);
    }

    std::vector<std::vector<std::string>> SearchWord(std::string& search_word) {
        std::vector<std::vector<std::string>> results;

        PrefixTree* root = this;
        for (char chr: search_word) {
            if (root->mapa_.contains(chr)) {
                root = root->mapa_[chr];
            } else {
                root = new PrefixTree();
            }

            results.push_back(root->results_);
        }

        return results;
    }

private:
    std::unordered_map<char, PrefixTree*> mapa_;
    std::vector<std::string> results_;
};

class Solution {
public:
    std::vector<std::vector<std::string>> suggestedProducts(std::vector<std::string>& products, std::string& searchWord) {
        std::sort(products.begin(), products.end());

        PrefixTree* root = new PrefixTree(products);

        return root->SearchWord(searchWord);
    }
};
