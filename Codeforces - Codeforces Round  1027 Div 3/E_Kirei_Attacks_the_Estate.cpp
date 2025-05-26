/**
 * Problem: E. Kirei Attacks the Estate
 * Contest: Codeforces Round  1027 (Div. 3)
 * OnlineJudge: Codeforces 
 * @Author: Chizer
 * DateTime: 2025-05-27 0:46  
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
ll d[maxn];
vector<int> v[maxn];
ll a[maxn];
// 负号的妙用：使用符号来进行全局的数值反转，更新反转后可以去掉的前半段路径和
void dfs(int now, int fa, ll sum, ll maxpresum, ll minpresum) {
    for(int next: v[now]) {
        if(next != fa) {
            dfs(next, now, -sum + a[next], max(-minpresum, -sum), min(-maxpresum, -sum));
        }
    }
    d[now] = sum - min(0ll, minpresum);
}

void solve() {
    memset(d, 0, sizeof d);
    memset(a, 0, sizeof a);
    int n;
    cin >> n;
    rep(i, 1, n) {
        v[i].clear();
    }
    rep(i, 1, n) {
        cin >> a[i];
    }
    rep(i, 1, n - 1) {
        int u, vv;
        cin >> u >> vv;
        v[u].pb(vv);
        v[vv].pb(u);
    }
    dfs(1, -1, a[1], a[1], 0);
    rep(i, 1, n) {
        cout << d[i] << ' ';
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
