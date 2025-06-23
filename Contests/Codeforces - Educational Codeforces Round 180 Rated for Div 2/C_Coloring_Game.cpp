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
int a[maxn];

void solve() {
    int n;
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    ll ans = 0;
    sort(a + 1, a + 1 + n);
    rep(i, 1, n) {
        rep(j, i + 1, n) {
            if(j + 1 > n) break;
            int sum = a[i] + a[j];
            // 找到第一个大于sum 的位置k，然后j + 1 -- k - 1都符合条件
            int k = lower_bound(a + j + 1, a + n + 1, sum) - a;
            int r = k - 1;
            // sum + a[h] > a[n]
            int h = upper_bound(a + j + 1, a + n + 1, a[n] - sum) - a;
            h = max(h, j + 1);
            if(r - h + 1 > 0) ans += 1ll * r - h + 1;
        }
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