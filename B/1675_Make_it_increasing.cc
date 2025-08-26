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
    int count=0;
    forloopR(i,n-1,1){
        if(a[i]<=a[i-1]){
            while(a[i-1]>=a[i]){
                if(a[i-1]==0){
                    cout << -1 << "\n";
                    return;
                }
                a[i-1]/=2;
                count++;
            }
        }
    }
    cout << count << "\n";
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