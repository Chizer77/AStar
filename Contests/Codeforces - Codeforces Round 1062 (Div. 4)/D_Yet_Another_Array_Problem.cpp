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
#define MAXN 10000007
using namespace std;

int T;
ll a[maxn];
int vis[MAXN];
ll pri[MAXN];
int cnt;

// C++ Version
void init() {
    for(int i = 2; i < MAXN; ++i) {
        if(!vis[i]) {
            pri[cnt++] = i;
        }
        for(int j = 0; j < cnt; ++j) {
            if(1ll * i * pri[j] >= MAXN) break;
            vis[i * pri[j]] = 1;
            if(i % pri[j] == 0) {
                // i % pri[j] == 0
                // 换言之，i 之前被 pri[j] 筛过了
                // 由于 pri 里面质数是从小到大的，所以 i 乘上其他的质数的结果一定也是
                // pri[j] 的倍数 它们都被筛过了，就不需要再筛了，所以这里直接 break
                // 掉就好了
                break;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    ll g = a[1];
    rep(i, 2, n) {
        g = gcd(g, a[i]);
    }
    if(g >= 10e18) {
        cout << -1 << '\n';
        return;
    }
    rep(i, 0, cnt - 1) {
        if(g % pri[i] == 0) {
            while(g % pri[i] == 0) {
                g /= pri[i];
            }
        } else {
            cout << pri[i] << '\n';
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    init();
    T = 1;
    cin >> T;
    while(T--) solve();
}