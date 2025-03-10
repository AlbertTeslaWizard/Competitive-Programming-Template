#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
using LL = long long;
using PII = pair<int, int>;

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

LL qmi(LL a, LL k) {
    LL res = 1;
    while(k != 0) {
        if(k & 1) res = res * a; 
        a = a * a;
        k >>= 1;
    }

    return res;
}

void solve() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}