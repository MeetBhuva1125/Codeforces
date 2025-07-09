#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forloop(i, a, b) for (int i=a; i<b; i++)
#define forloopR(i, a, b) for(int i=a; i>=b; i--)

ll calc_lcm(const set<ll>& s) {
    if (s.empty()) return 1;
    ll res = 1;
    for (ll x : s) {
        res = lcm(res, x);
    }
    return res;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    forloop(i, 0, n) {
        cin >> a[i];
    }
    
    set<ll> s;
    forloopR(i, n-2, 0) {
        ll g = gcd(a[i+1], a[i]);
        if (g != a[i]) {
            s.insert(a[i] / g);
        }
    }
    
    cout << calc_lcm(s) << "\n";
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