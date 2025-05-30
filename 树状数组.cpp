#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 1e5 + 10;
int tr[N], a[N], n, m;

int lowbit(int x) {
    return x & -x;
}

void add(int x, int c) {
    for(int i = x; i <= n; i += lowbit(i))
        tr[i] += c;
}

LL sum(int x) {
    int res = 0;
    for(int i = x; i > 0; i -= lowbit(i)) {
        res += tr[i];
    }

    return res;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        add(i, a[i] - a[i - 1]);
    }

    return 0;
}