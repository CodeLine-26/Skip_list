#pragma once
#include <iostream>
#include <limits>
#include <cstdlib>

using namespace std;


template <typename T>
struct Node {
    T key;
    Node** forward;

    Node(const T& key, int level) : key(key) {
        forward = new Node * [level + 1];
        for (int i = 0; i <= level; i++) {
            forward[i] = nullptr;
        }
    }

    ~Node() {
        delete[] forward;
    }
};

template <typename T>
class SkipList {
private:
    int maxLevel;
    float p; 
    Node<T>* header;

    int randomLevel() {
        int lvl = 1;
        while (rand() % 100 < p * 100 && lvl < maxLevel) {
            lvl++;
        }
        return lvl;
    }

public:
    SkipList(int maxLevel = 16, float p = 0.5) : maxLevel(maxLevel), p(p) {
        header = new Node<T>(numeric_limits<T>::min(), maxLevel);
    }

    ~SkipList() {
        Node<T>* current = header->forward[0]; 
        while (current != nullptr) {
            Node<T>* temp = current;
            current = current->forward[0];
            delete temp;
        }
        delete header; 
    }

   
    void insert(const T& key) {
        Node<T>* current = header;
        Node<T>* update[maxLevel + 1];
        for (int i = maxLevel; i >= 0; i--) {
            while (current->forward[i] != nullptr && current->forward[i]->key < key) {
                current = current->forward[i];
            }
            update[i] = current;
        }
        current = current->forward[0];

        if (current != nullptr && current->key == key) {
            return;
        }

        int level = randomLevel();
        if (level > maxLevel) {
            for (int i = maxLevel + 1; i <= level; i++) {
                update[i] = header;
            }
            maxLevel = level;
        }

        Node<T>* newNode = new Node<T>(key, level);
        for (int i = 0; i <= level; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }

    bool search(const T& key) {
        Node<T>* current = header;
        for (int i = maxLevel; i >= 0; i--) {
            while (current->forward[i] != nullptr && current->forward[i]->key < key) {
                current = current->forward[i];
            }
        }
        current = current->forward[0];
        return current != nullptr && current->key == key;
    }

    void erase(const T& key) {
        Node<T>* current = header;
        Node<T>* update[maxLevel + 1];

        for (int i = maxLevel; i >= 0; i--) {
            while (current->forward[i] != nullptr && current->forward[i]->key < key) {
                current = current->forward[i];
            }
            update[i] = current;
        }

        current = current->forward[0];
        if (current != nullptr && current->key == key) {
            for (int i = 0; i <= maxLevel; i++) {
                if (update[i]->forward[i] != current) {
                    break;
                }
                update[i]->forward[i] = current->forward[i];
            }
            delete current;
            while (maxLevel > 0 && header->forward[maxLevel] == nullptr) {
                maxLevel--;
            }
        }
    }

    void print() {
        for (int i = maxLevel; i >= 0; i--) {
            Node<T>* current = header->forward[i];
            cout << "Level " << i << ": ";
            while (current != nullptr) {
                cout << current->key << " ";
                current = current->forward[i];
            }
            cout << endl;
        }
    }

    size_t size() const {
        size_t count = 0;
        Node<T>* current = header->forward[0];
        while (current != nullptr) {
            count++;
            current = current->forward[0];
        }
        return count;
    }

    bool empty() const {
        return size() == 0;
    }
};