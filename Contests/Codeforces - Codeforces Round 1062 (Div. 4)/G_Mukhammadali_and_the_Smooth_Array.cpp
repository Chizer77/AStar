#include<bits/stdc++.h>
#define rep(i, j ,k) for(int i = (j); i <= (k); ++i)
#define dep(i, j, k) for(int i = (j); i >= (k); --i)
using i64 = int64_t;
using f64 = double_t;
#define pb push_back
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define mod 1000000007
#define inf 0x3f3f3f3f
#define maxn 8001
using namespace std;

int T;
int n;
struct xx {
    int idx;
    ll val, cost;
    ll newval;
}arr[maxn];
ll a[maxn];
ll c[maxn];
ll dp[maxn];

void solve() {
    cin >> n;
    rep(i, 1, n) {
        cin >> arr[i].val;
        arr[i].idx = i;
    }
    rep(i, 1, n) cin >> arr[i].cost;
    sort(arr + 1, arr + n + 1, [](xx a, xx b) {
        return a.val < b.val;
        });
    int cnt = 1;
    rep(i, 1, n) {
        if(i > 1 && arr[i].val != arr[i - 1].val) cnt++;
        arr[i].newval = cnt;
    }
    int maxv = 0;
    rep(i, 1, n) {
        a[arr[i].idx] = arr[i].newval;
        c[arr[i].idx] = arr[i].cost;
        if(maxv < arr[i].newval) maxv = arr[i].newval;
    }
    // rep(i, 1, n) cout << a[i] << ' ';
    // cout << '\n';
    // rep(i, 1, n) cout << c[i] << ' ';
    // cout << '\n';
    me(dp, 10e18);
    rep(i, 1, maxv) {
        if(i == a[1]) dp[i] = 0;
        else dp[i] = c[1];
    }
    vector<ll> pre(maxv + 1, 0);
    rep(i, 2, maxv) {
        pre[i] = min(pre[i - 1], dp[i]);
    }
    rep(i, 1, n) {
        rep(j, 1, maxv) {
            if(j == a[i]) dp[j] = pre[j];
            else dp[j] = pre[j] + c[i];
            if(j == 1) {
                pre[j] = dp[j];
            } else pre[j] = min(pre[j - 1], dp[j]);
        }
    }
    ll ans = 10e18;
    rep(i, 1, maxv) {
        ans = min(ans, dp[i]);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    T = 1;
    cin >> T;
    while(T--) solve();
}