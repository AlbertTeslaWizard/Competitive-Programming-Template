#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
using LL = long long;
using PII = pair<int, int>;
const int N = 2e5 + 10;

/*
    用懒标记思想，即延时传递变更的值来减小时间复杂度解决问题
    题目链接：https://www.luogu.com.cn/problem/AT_abc157_d
*/

int n, tt;
vector<int> G[N];
LL score[N];

void dfs(int u, int fa) {
    score[u] += score[fa];
    for(int i = 0; i < G[u].size(); i ++) {
        int v = G[u][i];
        if(v != fa) dfs(v, u);
    }
}

void solve() {
    cin >> n >> tt;
    for(int i = 1; i <= n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        G[x].pb(y);
        G[y].pb(x);
    }
    
    for(int i = 1; i <= tt; i ++) {
        int x;
        LL v;
        cin >> x >> v;
        score[x] += v;
    }
    
    dfs(1, 0);
    for(int i = 1; i <= n; i ++) cout << score[i] << " ";
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}