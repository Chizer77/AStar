/**
 * Problem: A. Blackboard Game
 * Contest: Codeforces Round 1034 (Div. 3)
 * OnlineJudge: Codeforces 
 * @Author: Chizer
 * DateTime: 2025-07-01 22:35  
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
int n;

void solve() {
    cin >> n;
    int t = n % 4;
    if(t == 1) {
        cout << "Alice\n";
    }else if(t == 2) {
        if((n - 1 + n - 2) % 4 == 3) {
            cout << "Bob\n";
        }else {
            cout << "Alice\n";
        }
    }else if(t == 3) {
        if((n - 1 + n - 2) % 4 == 3 || (n - 1 + n - 3) % 4 == 3 || (n - 2 | n - 3) % 4 == 3) {
            cout << "Alice\n";
        }else {
            cout << "Bob\n";
        }
    }else cout << "Bob\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    T = 1;
    cin >> T;
    while (T--) solve();
}
