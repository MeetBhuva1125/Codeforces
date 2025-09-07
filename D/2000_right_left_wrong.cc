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
    v1i a(n);
    ll total_sum = 0;
    forloop(i,0,n){cin >> a[i]; total_sum+=a[i];}
    string s;
    cin >> s;

    // prefix sums
    v1l pref(n + 1);
    forloop(i, 0, n) pref[i + 1] = pref[i] + a[i];

    ll ans = 0;
    int i = 0, j = n - 1;

    while (i < j) {
        // move i to nearest L
        while (i < j && s[i] != 'L') i++;
        // move j to nearest R
        while (i < j && s[j] != 'R') j--;

        if (i < j) {
            ans += pref[j + 1] - pref[i];
            i++;
            j--;
        } else {
            break;
        }
    }

    cout << ans << '\n';
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