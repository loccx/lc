#include <iostream>
#include <tuple>
#include <queue>
#include <string>

using namespace std;

// MAXN = 8
const int MAXN = 2e3, INF = 1e9;

char field[MAXN][MAXN];
string ans;
int d[MAXN][MAXN];

int n, m, x, y;
