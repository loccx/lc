#include <iostream>

using namespace std;

class Minstack {
    private:
        vector<int> minvec;
        vector<int> vec;

    public:
        Minstack () {}

        void push(int inp);
        void pop();
        int top(int inp);
        int get_min();
}

void Minstack::push(int inp) {
    if (inp < minvec[minvec.end()]) minvec.push_back(inp);
    vec.push_back(inp);
}
void Minstack::pop() {
    if (vec[vec.end()] == minvec[minvec.end()]) minvec.pop();
    vec.pop();
}

int Minstack::top(int inp) {
    return vec[vec.end()];
}
int Minstack::get_min() {
    return minvec[minvec.end()];
}
