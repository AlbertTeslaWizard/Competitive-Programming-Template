#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long LL;

const int N = 2e5 + 10;
int n, m;
LL tr[N]; //tr[i]表示当前数组元素中值 <= i的有多少

int lowbit(int x) {
    return x & -x;
}

void add(int x, int c) {
    for(int i = x; i <= m; i += lowbit(i)) {
        tr[i] += c;
    }
}

LL sum(int x) {
    LL res = 0;
    for(int i = x; i > 0; i -= lowbit(i)) {
        res += tr[i];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    vector<int> a(n);
    
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    LL ans = 0;
    
    //利用树状数组进行数组初始时的逆序数(即k = 0时)
    //把值x存储到位置x + 1
    //那么对于当前位置为i的值a[i]，其位置在之前并比其值大的数组元素有sum(m) - sum(a[i] + 1)
    //然后在把当前的值的个数增加存入到树状数组中, 即add(a[i] + 1, 1)
    for(auto x : a) { // x = a[i]
        ans += sum(m) - sum(x + 1);
        add(x + 1, 1);
    }
    
    cout << ans << '\n';
    return 0;
}