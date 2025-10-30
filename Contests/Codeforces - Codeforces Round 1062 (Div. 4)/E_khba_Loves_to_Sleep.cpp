#include<bits/stdc++.h>
#include<array>
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
#define maxn 200005
using namespace std;

int T;
ll n, k, x;
ll a[maxn];

void solve() {
    cin >> n >> k >> x;
    rep(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    priority_queue<array<ll, 4>> pq;
    rep(i, 2, n) {
        ll l = a[i - 1], r = a[i];
        if(l == r) continue;
        ll mid = (l + r) / 2;
        pq.push({ mid - l, mid, -1, l }); // 可位移长度，起点，方向，终点
        if(mid + 1 <= r - 1) {
            pq.push({ r - mid - 1, mid + 1, 1, r - 1 });
        }
    }
    if(a[1] > 0) {
        pq.push({ a[1], 0, 1, a[1] - 1 });
    }
    pq.push({ x - a[n], x, -1, a[n] });
    rep(i, 1, k) {
        auto [d, x, v, g] = pq.top();
        pq.pop();
        cout << x << " \n"[i == k];
        if(x != g) {
            pq.push({ d - 1, x + v, v, g });
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    T = 1;
    cin >> T;
    while(T--) solve();
}