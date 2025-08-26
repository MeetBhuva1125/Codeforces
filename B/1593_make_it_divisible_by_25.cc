#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forloop(i, a, b) for (int i=a; i<b; i++)
#define forloopR(i, a, b) for(int i=a; i>=b; i--)
#define v1d(type, name, n) vector<type> name(n)
#define v2d(type, name, m, n) vector<vector<type>> name(m, vector<type>(n))

ll count_removals(string s, char c1, char c2) {
    ll len = s.length();
    ll removals = 0;
    bool found_c1 = false;
    bool found_c2 = false;

    for (ll i = len - 1; i >= 0; --i) {
        if (!found_c1) {
            if (s[i] == c1) {
                found_c1 = true;
            } else {
                removals++;
            }
        } else if (!found_c2) {
            if (s[i] == c2) {
                found_c2 = true;
                break;
            } else {
                removals++;
            }
        }
    }

    if (found_c1 && found_c2) {
        return removals;
    } else {
        return LLONG_MAX;
    }
}

void solve(){
    ll n;
    cin >> n;

    string s = to_string(n);

    ll ans = LLONG_MAX;

    ans = min(ans, count_removals(s, '0', '0'));
    ans = min(ans, count_removals(s, '5', '2'));
    ans = min(ans, count_removals(s, '0', '5'));
    ans = min(ans, count_removals(s, '5', '7'));

    cout << ans << "\n";
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