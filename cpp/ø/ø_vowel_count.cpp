#include <iostream>
#include <set>

using namespace std;

int count_vowels(string str) {
    set<char> v = {'a', 'e', 'i', 'o', 'u'};
    int count = 0;
    for (auto letter : str) {
        if (v.find(letter) != v.end()) count++;
    }
    return count;
}

int main() {
    string inp;
    cout << "Enter word to count vowels:\n";
    cin >> inp;

    int res = count_vowels(inp);
    cout << "There are " << res << " vowels in " << inp << '\n';
    return 0;
}
