#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forloop(i, a, b) for (int i=a; i<b; i++)
#define forloopR(i, a, b) for(int i=a; i>=b; i--)
#define v1d(type, name, n) vector<type> name(n)
#define v2d(type, name, m, n) vector<vector<type>> name(m, vector<type>(n))

void solve(){
    int n,x;
    cin >> n >> x;

    ll max_btfl = 0;
    ll min_btfl = 0;

    forloop(i,0,n){
        int a;
        cin >> a;
        min_btfl+=a;
        // cout << ceil(a/(x*1.0)) << " ";
        max_btfl += (a+x-1)/x;
    }
    // cout << "\n";
    cout << (min_btfl+x-1)/x << " " << max_btfl << "\n";
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