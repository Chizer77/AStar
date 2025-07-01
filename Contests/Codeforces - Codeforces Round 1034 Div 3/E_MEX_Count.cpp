/**
 * Problem: E. MEX Count
 * Contest: Codeforces Round 1034 (Div. 3)
 * OnlineJudge: Codeforces 
 * @Author: Chizer
 * DateTime: 2025-07-01 23:25  
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
int n;
int a[maxn];

void solve() {
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    int frq[maxn];
    memset(frq, 0, sizeof frq);
    rep(i, 1, n) {
        frq[a[i]]++;
    }
    int tar = 0;
    rep(i, 0, n) {
        if(frq[i] == 0) {
            tar = i;
            break;
        }
    }
    int b[maxn];
    memset(b, 0, sizeof b);
    rep(i, 0, n) {
        if(i <= tar) {
            int minn = min(n - i, frq[i]);
            int mxx = max(n - i, frq[i]);
            b[minn]++;
            b[mxx + 1]--;
        }
    }
    rep(i, 0, n) {
        if(i > 0) {
            b[i] += b[i - 1];
        }
        cout << b[i] << ' ';
    }
    cout << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    T = 1;
    cin >> T;
    while (T--) solve();
}
