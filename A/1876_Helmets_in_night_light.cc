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
vector<T> v1d_t(int n) { return vector<T>(n); }
template<typename T>
vector<vector<T>> v2d_t(int m, int n) { return vector<vector<T>>(m, vector<T>(n)); }

#define forloop(i, a, b) for(int i=a; i<b; i++)
#define forloopR(i, a, b) for(int i=a; i>=b; i--)
// #define v1d(type, name, n) vector<type> name(n,0)
// #define v2d(type, name, m, n) vector<vector<type>> name(m, vector<type>(n,0))

void solve(){
    int n,p;
    cin >> n >> p;
    //{residents, cost};
    auto v = v1d_t<pii>(n+1);
    v[n] = {n-1,p};
    forloop(i,0,n){
        cin >> v[i].first;
    }
    forloop(i,0,n){
        cin >> v[i].second;
    }

    sort(v.begin(),v.end(),[](pii& a, pii& b){
        return a.second < b.second;
    });

    ll cost = p;
    n--;
    for (auto& i : v) {
        if (n == 0) break;
        int cnt = min(n, i.first);
        cost += 1LL * cnt * i.second;
        n -= cnt;
    }

    cout << cost << "\n";
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
