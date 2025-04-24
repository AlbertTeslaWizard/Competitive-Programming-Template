#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long LL;

//求解数组arr的逆序数 
LL merge(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return 0;
    }
    
    int mid = (left + right) >> 1;
    LL res = merge(arr, left, mid) + merge(arr, mid + 1, right);

    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    
    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j]) {
            temp[k ++] = arr[i ++];
        } else {
            res += mid - i + 1;
            temp[k ++] = arr[j ++];
        }
    }
    
    while(i <= mid) temp[k ++] = arr[i ++];
    while(j <= right) temp[k ++] = arr[j ++];
    for(int p = 0; p < k; p ++) {
        arr[left + p] = temp[p];
    }
    
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    LL ans = merge(a, 0, n - 1);
    cout << ans << '\n';
    
    return 0;
}