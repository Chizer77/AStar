/**
 * Problem: D. Binary String Battle
 * Contest: Codeforces Round 1034 (Div. 3)
 * OnlineJudge: Codeforces 
 * @Author: Chizer
 * DateTime: 2025-07-01 23:07  
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
int n, k;
string s;

void solve() {
    cin >> n >> k;
    cin >> s;
    int ct = 0;
    rep(i, 0, n - 1) {
        if(s[i] == '1') ct++;
    }
//    cout << ct << endl;
    if(ct <= k || k > n / 2) {
        cout << "Alice" << endl;
    } else cout << "Bob" << endl;
    // 1 个数小于等于 k 或者 k > n / 2  Alice win
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    T = 1;
    cin >> T;
    while (T--) solve();
}
