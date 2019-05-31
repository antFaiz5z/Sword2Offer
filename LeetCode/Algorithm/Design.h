//
// Created by Faiz on 2019/5/31 0031.
//

#ifndef SWORD2OFFER_DESIGN_H
#define SWORD2OFFER_DESIGN_H

#include <unordered_map>
#include <iostream>
#include "../DataStructure/Map.h"

using namespace std;

class Node2 {
public:
    int key;
    int value;
    Node2 *prev, *next;

    Node2(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class DoubleLinkedList {
private:
    Node2 *head, *tail;
    int size;
public:
    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~DoubleLinkedList() {
        while (head) {
            Node2 *node = head;
            head = head->next;
            delete node;
        }
    }

    int getSize() {
        return size;
    }

    Node2 *getTail() {
        return tail;
    }

    void unlink(Node2 *node) {

        Node2 *before = node->prev;
        Node2 *after = node->next;
        if (before) before->next = after;
        if (after) after->prev = before;
        if (node == head) head = head->next;
        if (node == tail) tail = tail->prev;
        node->prev = nullptr;
        node->next = nullptr;
        --size;
    }

    Node2 *add2begin(Node2 *node) {
        if (!head) {
            head = node;
            tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        ++size;
        return node;
    }

    Node2 *add2begin(int key, int value) {
        auto *node = new Node2(key, value);
        return add2begin(node);
    }

    Node2 *take2begin(Node2 *node) {
        if (node == head) return node;
        unlink(node);
        return add2begin(node);
    }

    void deleteTail() {
        if (!tail) return;
        Node2 *tmp = tail;
        unlink(tmp);
        delete tmp;
    }

    void print() {
        Node2 *node = head;
        cout << "[";
        while (node) {
            cout << "(" << node->key << ", " << node->value << ")";
            node = node->next;
        }
        cout << "]" << endl;
    }

};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node2 *> mp;
    DoubleLinkedList cache;
public:
    explicit LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        Node2 *node = mp[key];
        cache.take2begin(node);
        return node->value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key]->value = value;
            cache.take2begin(mp[key]);
            return;
        }
        if (cache.getSize() == capacity) {
            mp.erase(cache.getTail()->key);
            cache.deleteTail();
        }
        mp[key] = cache.add2begin(key, value);
    }
};

class Design {

};


#endif //SWORD2OFFER_DESIGN_H
