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
int n;

void solve() {
    cin >> n;
    rep(i, 1, n) {
        cin >> a[i];
    }
    if(n < 2) {
        cout << -1 << endl;
        return;
    }
    rep(i, 2, n) {
        if(abs(a[i] - a[i - 1]) <= 1) {
            cout << 0 << endl;
            return;
        }
    }
    int f = 0;
    if(a[2] - a[1] > 1) f = 1;
    else if(a[2] - a[1] < -1) f = -1;
    rep(i, 2, n) {
        if(f == 1) {
            if(a[i] - a[i - 1] <= 1) {
                cout << 1 << endl;
                return;
            }
        } else if(f == -1) {
            if(a[i] - a[i - 1] >= 1) {
                cout << 1 << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    T = 1;
    cin >> T;
    while(T--) solve();
}