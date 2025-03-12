#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int p[N];

int find(int x) {
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void Merge(int x, int y) {
    int px = find(x), py = find(y);
    p[px] = py;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}