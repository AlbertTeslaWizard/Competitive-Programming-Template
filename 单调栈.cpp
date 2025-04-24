/*
    背景：给定一个长度为 N的整数数列，输出每个数左边第一个比它小的数，如果不存在则输出-1
*/
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    
    stack<int> st;
    for(int i = 0; i < n; i ++) {
        while(! st.empty() && a[i] <= a[st.top()]) st.pop();
        if(st.empty()) cout << -1 << " ";
        else cout << a[st.top()] << " ";
        st.push(i);
    }
    
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
}