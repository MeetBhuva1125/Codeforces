#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forloop(i, a, b) for (int i=a; i<b; i++)
#define forloopR(i, a, b) for(int i=a; i>=b; i--)
#define v1d(type, name, n) vector<type> name(n)
#define v2d(type, name, m, n) vector<vector<type>> name(m, vector<type>(n))

void solve(){
    ll x,n;
    cin >> x >> n;
    bool even = !(x%2);
    
    int rem = n%4;
    if(even){
        if(rem==1)cout << x-n << "\n";
        else if(rem==2)cout << x - (n-1) + n << "\n";
        else if(rem==3)cout << x - (n-2) + (n-1) + n << "\n";
        else cout << x << "\n";
    }
    else{
        if(rem==1)cout << x+n << "\n";
        else if(rem==2)cout << x + (n-1) - n << "\n";
        else if(rem==3) cout << x + (n-2) - (n-1) - n << "\n";
        else cout << x << "\n";
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