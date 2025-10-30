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
#define maxn 100005
using namespace std;

int T;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    rep(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int> depth(n, 0);
    ll ans = 0;
    auto dfs = [&](auto&& dfs, int x, int p) -> void {
        depth[x] = 1;
        for(auto ne : g[x]) {
            if(ne == p) continue;
            dfs(dfs, ne, x);
            depth[x] += depth[ne];
        }
        if(depth[x] >= k) {
            ans += n - depth[x];
        }
        if(n - depth[x] >= k) {
            ans += depth[x];
        }
        ans++;
    };
    dfs(dfs, 0, -1);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    T = 1;
    cin >> T;
    while(T--) solve();
}