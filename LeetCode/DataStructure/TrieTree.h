//
// Created by faiz on 19-4-29.
//

#ifndef JIANZHIOFFER_TREE_H
#define JIANZHIOFFER_TREE_H

#include <string>
#include <vector>

using namespace std;

//208
class TrieNode {

public:
    TrieNode() {
        for (auto &i : next) {
            i = nullptr;
        }
        isString = false;
    }

    TrieNode *next[26];
    bool isString;
};

class TrieTree {
public:
    /** Initialize your data structure here. */
    TrieTree() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root;
        for (char i : word) {
            if (!p->next[i - 'a']) {
                p->next[i - 'a'] = new TrieNode();
            }
            p = p->next[i - 'a'];
        }
        p->isString = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = root;
        for (char i : word) {
            if (!p->next[i - 'a']) return false;
            p = p->next[i - 'a'];
        }
        return p->isString;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (char i : prefix) {
            if (!p->next[i - 'a']) return false;
            p = p->next[i - 'a'];
        }
        return true;
    }

private:
    TrieNode *root;
};

//211
class WordNode {
public:
    WordNode() {
        for (auto &i : next) {
            i = nullptr;
        }
        isString = false;
    }

    WordNode *next[26];
    bool isString;
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new WordNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        WordNode *p = root;
        for (char i : word){
            if (!p->next[i - 'a']){
                p->next[i - 'a'] = new WordNode();
            }
            p = p->next[i - 'a'];
        }
        p->isString = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        WordNode *p = root;
        return search(word, 0, root);
    }

    bool search (const string& word, int pos, WordNode *cur){
        if (pos == word.size()) return cur->isString;
        if (word[pos] == '.'){
            for (auto & i : cur->next) {
                if (i && search(word, pos +1, i)) return true;
            }
            return false;
        }
        if (cur->next[word[pos] - 'a']){
            return search(word, pos +1, cur->next[word[pos] - 'a']);
        }
        return false;
    }

private:
    WordNode *root;
};

class TrieTreeII {
public:
    //212
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words);
};


#endif //JIANZHIOFFER_TREE_H
