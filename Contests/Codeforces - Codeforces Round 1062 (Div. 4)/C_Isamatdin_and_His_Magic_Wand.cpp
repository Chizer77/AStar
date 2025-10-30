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
#define maxn 200005
using namespace std;

int T;
ll a[maxn];

void solve() {
    int n;
    cin >> n;
    int f1 = 0, f2 = 0;
    rep(i, 1, n) {
        cin >> a[i];
        if(a[i] % 2 == 0) f1 = 1;
        else f2 = 1;
    }
    if(f1 && f2) {
        sort(a + 1, a + 1 + n);
    }
    rep(i, 1, n) {
        cout << a[i] << " ";
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    T = 1;
    cin >> T;
    while(T--) solve();
}