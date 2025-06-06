/**
 * Problem: C. Need More Arrays
 * Contest: Codeforces Round  1027 (Div. 3)
 * OnlineJudge: Codeforces 
 * @Author: Chizer
 * DateTime: 2025-05-26 22:50  
 * 适度编程益脑，沉迷编程伤身，合理安排时间，享受快乐生活。
 */
#include "bits/stdc++.h"
#define rep(i, j, k) for(int i = (j); i <= (k); ++i)
#define dep(i, j, k) for(int i = (j); i >= (k); --i)
using i64 = int64_t;
using f64 = double_t;
#define pb push_back
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define ull unsigned long long
#define mod 1000000007
#define inf 0x3f3f3f3f
#define maxn 200005
using namespace std;

int T;

void solve() {
    int n;
    cin >> n;
    int a[maxn];
    rep(i, 1, n) {
        cin >> a[i];
    }
    int sum = 1;
    int ans = 0;
    rep(i, 1, n - 1) {
        if(a[i] + 1 < a[i + 1]) {
            ans += (sum - 1) / 2 + 1;
            sum = 1;
        }else if(a[i] == a[i + 1]) {

        }else {
            sum++;
        }
    }
    if(sum) ans += (sum - 1) / 2 + 1;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    T = 1;
    cin >> T;
    while (T--) solve();
}
