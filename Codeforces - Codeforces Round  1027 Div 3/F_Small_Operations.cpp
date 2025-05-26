/**
 * Problem: F. Small Operations
 * Contest: Codeforces Round  1027 (Div. 3)
 * OnlineJudge: Codeforces 
 * @Author: Chizer
 * DateTime: 2025-05-27 2:03  
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

ll fun(ll x, ll k) {
    vector<ll> v;
    //获取因子
    for(int i = 1; i * i <= x; i++) {
        if(x % i == 0) {
            v.pb(i);
            if(x / i != i) v.pb(x / i);
        }
    }
    sort(v.begin(), v.end());
    unordered_map<ll, ll> dp;   //表示从 1 到数值 i 需要的最小操作次数(由于四则运算可逆，本来是要算x->1的最小操作次数)
    for(ll i: v) {
        dp[i] = 1e9;
    }
    dp[1] = 0;
    for(ll i: v) {
        for(ll j: v) {
            if(j <= k && i * j <= x) {
                dp[i * j] = min(dp[i * j], dp[i] + 1);  //表示从 i 到 i * j 的最少计算次数
            }
        }
    }
    return dp[x];
}

void solve() {
    ll x, y, k;
    cin >> x >> y >> k;
    ll gc = __gcd(x, y);
    // 表示x -> gc -> y, 这样的计算次数最少
    x /= gc;
    y /= gc;
    ll ans = fun(x, k) + fun(y, k);
    if(ans >= 1e9l) cout << -1 << endl;
    else cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    T = 1;
    cin >> T;
    while (T--) solve();
}
