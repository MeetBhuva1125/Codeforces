#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double dd;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_map<int,int> umpii;
typedef unordered_map<long long, long long> umpll;
typedef vector<int> v1i;
typedef vector<long long> v1l;
typedef vector<vector<int>> v2i;
typedef vector<vector<long>> v2l;

// Functions as alternatives to macros (more type-safe)
template<typename T>
vector<T> v1d_t(int n) { return vector<T>(n,0); }
template<typename T>
vector<vector<T>> v2d_t(int m, int n) { return vector<vector<T>>(m, vector<T>(n,0)); }

#define forloop(i, a, b) for(int i=a; i<b; i++)
#define forloopR(i, a, b) for(int i=a; i>=b; i--)
// #define v1d(type, name, n) vector<type> name(n,0)
// #define v2d(type, name, m, n) vector<vector<type>> name(m, vector<type>(n,0))

void solve(){
    int n;
    cin >> n;
    ll k;
    cin >> k;

    vector<ll> a(n); // Use long long for durability
    forloop(i,0,n){
        cin >> a[i];
    }

    int i=0;
    int j=n-1;
    int sunk = 0;
    while(i < j && k > 0){ // Loop while there are at least two ships
        ll m = min(a[i], a[j]);
        if (k >= 2 * m) {
            k -= 2 * m;
            a[i] -= m;
            a[j] -= m;
            if(a[i] == 0) {
                sunk++;
                i++;
            }
            if(a[j] == 0) {
                sunk++;
                j--;
            }
        } else {
            // Not enough k to sink the weaker ship completely.
            // Distribute remaining k and finish.
            a[i] -= (k + 1) / 2;
            a[j] -= k / 2;
            if (a[i] <= 0) {
                sunk++;
            }
            if (a[j] <= 0) {
                sunk++;
            }
            k = 0;
        }
    }

    if(i == j && k > 0 && a[i] <= k){ // Check for the last remaining ship
        sunk++;
    }

    cout << sunk << "\n";
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