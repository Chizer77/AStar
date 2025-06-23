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
#define ull unsigned long long
#define mod 1000000007
#define inf 0x3f3f3f3f
#define maxn 100005
using namespace std;

int T;
int minimizeMax(vector<int>& nums, int p) {
    if(p == 0) return 0;
    int n = nums.size();
    int l = 0;
    sort(nums.begin(), nums.end());
    int ans = inf;
    vector<pair<int, int>> diff;
    for(int i = 0; i < n - 1; i++) {
        diff.push_back({nums[i + 1] - nums[i], i});
    }
    sort(diff.begin(), diff.end());
    int m = diff.size();
    int minn = diff[0].first;
    for(int j = 0; j < m; j++) {
        if(diff[j].first > minn) break;
        map<int, int> mp;
        int num = 0;
        int tmp = 0;
        for(int i = j; i < m; i++) {
            int k = diff[i].first;
            int v = diff[i].second;
            if(mp[v - 1] == 1 || mp[v + 1] == 1) continue;
            mp[v] = 1;
            num++;
            tmp = k;
            if(num == p) {
                ans = min(ans, tmp);
                break;
            };
        }
    }

    return ans;
}

void solve() {
    vector<int> v = {1,1,0,3};
    minimizeMax(v, 2);
}

int main () {
    ios:: sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    T = 1;
//    cin >> T;
    while(T--) solve();
}