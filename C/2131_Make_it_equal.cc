#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forloop(i, a, b) for (int i=a; i<b; i++)
#define forloopR(i, a, b) for(int i=a; i>=b; i--)
#define v1d(type, name, n) vector<type> name(n)
#define v2d(type, name, m, n) vector<vector<type>> name(m, vector<type>(n))

void solve(){
    int n;
    ll k;
    cin >> n >> k;
    
    map<pair<ll, ll>, int> s_counts;
    forloop(i, 0, n) {
        ll val;
        cin >> val;

        ll r = val % k;
        ll partner_r = (k - r) % k;

        if (r > partner_r) {
            swap(r, partner_r);
        }
        s_counts[{r, partner_r}]++;
    }

    map<pair<ll, ll>, int> t_counts;
    forloop(i, 0, n) {
        ll val;
        cin >> val;

        ll r = val % k;
        ll partner_r = (k - r) % k;

        if (r > partner_r) {
            swap(r, partner_r);
        }
        t_counts[{r, partner_r}]++;
    }

    if (s_counts == t_counts) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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