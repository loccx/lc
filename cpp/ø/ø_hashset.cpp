#include <iostream>
#include <list>

using namespace std;

class MyHashSet {
private:
    int prime;
    vector<list<int>> map;

    int hash(int key) {
        return key % prime;
    }

    list<int>::iterator search(int key) {
        int code = hash(key);
        return find(map[code].begin(), map[code].end(), key); // returns iterator to the first instance of key in the list
    }

public:
    MyHashSet() : prime(10007), map(prime) {} // initializes prime to 10007, initializes vector to size 10007

    void add(int key) {
        int code = hash(key);
        if (!contains(key)) {
            map[code].push_back(key);
        }
    }

    void remove(int key) {
        int code = hash(key);
        auto mark = search(key);
        if (mark != map[code].end()) {
            map[code].erase(mark);
        }
    }

    bool contains(int key) {
        int code = hash(key);
        return search(key) != map[code].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main() {
    MyHashSet test;
    test.add(10);
    test.add(20);
    test.add(30);
    test.add(1000);
    if (!test.contains(21)) cout << "21 is not in the hashset\n";

    if (test.contains(1000)) {
        cout << "1000 is in the hashset\n";
    }
}
