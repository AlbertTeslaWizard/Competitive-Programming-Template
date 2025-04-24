/*
    有一个大小为k的滑动窗口，求滑动窗口位于每个位置时，窗口中的最大值和最小值
*/
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    
    for(int i = 0; i < n; i ++) cin >> nums[i];
    deque<int> q;
    
    //最小值
    for(int i = 0; i < n; i ++) {
        if(! q.empty() && i - k + 1 > q.front()) q.pop_front();
        while(! q.empty() && nums[i] <= nums[q.back()]) q.pop_back();
        q.push_back(i);
        if(i >= k - 1) cout << nums[q.front()] << " ";
    }
    
    cout << '\n';
    q.clear();
    
    //最大值
    for(int i = 0; i < n; i ++) {
        if(! q.empty() && i - k + 1 > q.front()) q.pop_front();
        while(! q.empty() && nums[i] >= nums[q.back()]) q.pop_back();
        q.push_back(i);
        if(i >= k - 1) cout << nums[q.front()] << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
}