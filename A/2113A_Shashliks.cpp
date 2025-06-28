#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forloop(i, a, b) for (int i = a; i < b; i++)

ll cook(ll k, ll a, ll b, ll x, ll y) {
    ll cnt1 = (k >= a) ? (k - a) / x + 1 : 0;
    ll rem = k - cnt1 * x;
    ll cnt2 = (rem >= b) ? (rem - b) / y + 1 : 0;
    return cnt1 + cnt2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll k, a, b, x, y;
        cin >> k >> a >> b >> x >> y;
        // Try both orders
        ll ans1 = cook(k, a, b, x, y);
        ll ans2 = cook(k, b, a, y, x);
        cout << max(ans1, ans2) << endl;
    }
    return 0;
}