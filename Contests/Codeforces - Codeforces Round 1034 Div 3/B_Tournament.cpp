/**
 * Problem: B. Tournament
 * Contest: Codeforces Round 1034 (Div. 3)
 * OnlineJudge: Codeforces 
 * @Author: Chizer
 * DateTime: 2025-07-01 22:49  
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
int n, j, k;
int a[maxn];

void solve() {
    cin >> n >> j >> k;
    int vj;
    rep(i, 1, n) {
        cin >> a[i];
        if(i == j) vj = a[i];
    }
    sort(a + 1, a + 1 + n);
    if(k == 1) {
        if(vj == a[n]) {
            cout << "YES" << endl;
        }else cout << "NO" << endl;
    }else {
        cout << "YES" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    T = 1;
    cin >> T;
    while (T--) solve();
}
