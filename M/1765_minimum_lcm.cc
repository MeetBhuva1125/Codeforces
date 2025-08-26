#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forloop(i, a, b) for (int i=a; i<b; i++)
#define forloopR(i, a, b) for(int i=a; i>=b; i--)
#define v1d(type, name, n) vector<type> name(n)
#define v2d(type, name, m, n) vector<vector<type>> name(m, vector<type>(n))

void solve(){
    int n;
    cin >> n;

    auto smallestDivisor = [](int n){
        if(n%2 == 0) return 2;
        if(n%3 == 0) return 3;
        for(int i=5; i*i<=n; i++){
            if(n%i == 0)return i;
            if(n%(i+2) == 0)return i+2;
        }
        return n;
    };

    int ans = n/smallestDivisor(n);
    cout << ans << " " << n-ans << "\n";

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