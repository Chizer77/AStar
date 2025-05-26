/**
 * Problem: D. Come a Little Closer
 * Contest: Codeforces Round  1027 (Div. 3)
 * OnlineJudge: Codeforces 
 * @Author: Chizer
 * DateTime: 2025-05-26 23:35  
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

void solve() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> pos;
    ll minx = mod, maxx = 0, miny = mod, maxy = 0;
    ll sminx = mod, smaxx = 0, sminy = mod, smaxy = 0;
    rep(i, 1, n) {
        int x, y;
        cin >> x >> y;
        pos.pb({x, y});
        if(minx > x) {
            sminx = minx;
            minx = x;
        }else if(minx <= x && sminx > x) {
            sminx = x;
        }
        if(maxx < x) {
            smaxx = maxx;
            maxx = x;
        }else if(maxx >= x && smaxx < x) {
            smaxx = x;
        }
        if(miny > y) {
            sminy = miny;
            miny = y;
        }else if(miny <= y && sminy > y) {
            sminy = y;
        }
        if(maxy < y) {
            smaxy = maxy;
            maxy = y;
        }else if(maxy >= y && smaxy < y) {
            smaxy = y;
        }
    }
    ll sq = (maxy - miny + 1ll) * (maxx - minx + 1ll);
    ll ans = sq;
    if(sq == n) {
        cout << sq << endl;
        return;
    }
    //增长左侧x
    if(sminx != mod) {
        int ct = 0;
        rep(i, 0, n - 1) {
            ll x = pos[i].first;
            ll y = pos[i].second;
            if(x < sminx) ct++;
        }
        sq = (maxy - miny + 1ll) * (maxx - sminx + 1);
        if(ct == 1) {
            if(sq < n) {
                sq = min((maxy - miny + 1 + 1) * (maxx - sminx + 1), (maxy - miny + 1) * (maxx - sminx + 1 + 1));
            }
            ans = min(ans, sq);
        }
    }
    if(smaxx != 0) {
        int ct = 0;
        rep(i, 0, n - 1) {
            ll x = pos[i].first;
            ll y = pos[i].second;
            if(x > smaxx) ct++;
        }
        sq = (maxy - miny + 1) * (smaxx - minx + 1);
        if(ct == 1) {
            if(sq < n) {
                sq = min((maxy - miny + 1 + 1) * (smaxx - minx + 1), (maxy - miny + 1) * (smaxx - minx + 1 + 1));
            }
            ans = min(ans, sq);
        }
    }
    if(sminy != mod) {
        int ct = 0;
        rep(i, 0, n - 1) {
            ll x = pos[i].first;
            ll y = pos[i].second;
            if(y < sminy) ct++;
        }
        sq = (maxy - sminy + 1) * (maxx - minx + 1);
        if(ct == 1) {
            if(sq < n) {
                sq = min((maxy - sminy + 1 + 1) * (maxx - minx + 1), (maxy - sminy + 1) * (maxx - minx + 1 + 1));
            }
            ans = min(ans, sq);
        }
    }
    if(smaxy != 0) {
        int ct = 0;
        rep(i, 0, n - 1) {
            ll x = pos[i].first;
            ll y = pos[i].second;
            if(y > smaxy) ct++;
        }
        sq = (smaxy - miny + 1) * (maxx - minx + 1);
        if(ct == 1) {
            if(sq < n) {
                sq = min((smaxy - miny + 1 + 1) * (maxx - minx + 1), (smaxy - miny + 1) * (maxx - minx + 1 + 1));
            }
            ans = min(ans, sq);
        }
    }
    if(sminx != mod && smaxy != 0) {
        int ct = 0;
        rep(i, 0, n - 1) {
            ll x = pos[i].first;
            ll y = pos[i].second;
            if(y > smaxy || x < sminx) ct++;
        }
        sq = (smaxy - miny + 1) * (maxx - sminx + 1);
        if(ct == 1) {
            if(sq < n) {
                sq = min((smaxy - miny + 1 + 1) * (maxx - sminx + 1), (smaxy - miny + 1) * (maxx - sminx + 1 + 1));
            }
            ans = min(ans, sq);
        }
    }
    if(smaxx != 0 && smaxy != 0) {
        int ct = 0;
        rep(i, 0, n - 1) {
            ll x = pos[i].first;
            ll y = pos[i].second;
            if(y > smaxy || x > smaxx) ct++;
        }
        sq = (smaxy - miny + 1) * (smaxx - minx + 1);
        if(ct == 1) {
            if(sq < n) {
                sq = min((smaxy - miny + 1 + 1) * (smaxx - minx + 1), (smaxy - miny + 1) * (smaxx - minx + 1 + 1));
            }
            ans = min(ans, sq);
        }
    }
    if(sminx != mod && sminy != mod) {
        int ct = 0;
        rep(i, 0, n - 1) {
            ll x = pos[i].first;
            ll y = pos[i].second;
            if(y < sminy || x < sminx) ct++;
        }
        sq = (maxy - sminy + 1) * (maxx - sminx + 1);
        if(ct == 1) {
            if(sq < n) {
                sq = min((maxy - sminy + 1 + 1) * (maxx - sminx + 1), (maxy - sminy + 1) * (maxx - sminx + 1 + 1));
            }
            ans = min(ans, sq);
        }
    }
    if(smaxx != 0 && sminy != mod) {
        int ct = 0;
        rep(i, 0, n - 1) {
            ll x = pos[i].first;
            ll y = pos[i].second;
            if(y < sminy || x > smaxx) ct++;
        }
        sq = (maxy - sminy + 1) * (smaxx - minx + 1);
        if(ct == 1) {
            if(sq < n) {
                sq = min((maxy - sminy + 1 + 1) * (smaxx - minx + 1), (maxy - sminy + 1) * (smaxx - minx + 1 + 1));
            }
            ans = min(ans, sq);
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    T = 1;
    cin >> T;
    while (T--) solve();
}
