#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forloop(i, a, b) for (int i=a; i<b; i++)
#define forloopR(i, a, b) for(int i=a; i>=b; i--)
#define v1d(type, name, n) vector<type> name(n)
#define v2d(type, name, m, n) vector<vector<type>> name(m, vector<type>(n))


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<tuple<int, int, int>> casino(n);
        for (int i = 0; i < n; i++) {
            int l, r, x;
            cin >> l >> r >> x;
            casino[i] = {l, r, x};
        }
        sort(casino.begin(), casino.end());
        int maxx = k;
        for (auto [l, r, x] : casino) {
            if (l <= maxx && maxx <= r && x > maxx) {
                maxx = x;
            }
        }
        cout << maxx << "\n";
    }
    return 0;
}