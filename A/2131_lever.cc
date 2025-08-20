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
    v1d(int,a,n);
    forloop(i,0,n){
        cin >> a[i];
    }
    v1d(int,b,n);
    forloop(i,0,n){
        cin >> b[i];
    }
    int iter = 0;
    forloop(i,0,n){
        if(a[i]>b[i])iter+=(a[i]-b[i]);
    }

    cout << iter+1 << "\n";
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