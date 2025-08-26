#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forloop(i, a, b) for (int i=a; i<b; i++)
#define forloopR(i, a, b) for(int i=a; i>=b; i--)
#define v1d(type, name, n) vector<type> name(n)
#define v2d(type, name, m, n) vector<vector<type>> name(m, vector<type>(n))

void solve(){
    long long n, k;
    cin >> n;
    cin >> k;

    vector<long long> b3;
    long long cnt = 0;
    long long temp_n = n;

    if (temp_n == 0) {
        b3.push_back(0);
    } else {
        while (temp_n > 0) {
            cnt += temp_n % 3;
            b3.push_back(temp_n % 3);
            temp_n /= 3;
        }
    }
    reverse(b3.begin(), b3.end());

    if (cnt > k) {
        cout << -1 << "\n";
        return;
    } else {
        for (int i = 0; i < b3.size() - 1; i++) {
            long long jumps = min((k - cnt) / 2, b3[i]);
            b3[i] -= jumps;
            b3[i + 1] += 3 * jumps;
            cnt += 2 * jumps;
        }

        long long cost = 0;
        for (int i = 0; i < b3.size(); ++i) {
            long long val = (pow(3, i + 1)) + i * (pow(3, i - 1));
            cost += b3[b3.size() - 1 - i] * val;
        }

        cout << cost << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}