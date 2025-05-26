/**
 * Problem: B. Not Quite a Palindromic String
 * Contest: Codeforces Round  1027 (Div. 3)
 * OnlineJudge: Codeforces 
 * @Author: Chizer
 * DateTime: 2025-05-26 22:42  
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
#define maxn 100005
using namespace std;

int T;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int zero = 0, one = 0;
    rep(i, 0, n - 1) {
        if(s[i] == '0') {
            zero++;
        }else if(s[i] == '1') {
            one++;
        }
    }
    int xx = min(one, zero);
    rep(i, 0, xx) {
        int tz = zero - i;
        int to = one - i;
        if(tz % 2 || to % 2) continue;
        if(tz / 2 + to / 2 == k) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    T = 1;
    cin >> T;
    while (T--) solve();
}
