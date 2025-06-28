#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forloop(i, a, b) for (int i = a; i < b; i++)

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n,s;
        cin >> n >> s;

        int x[n];
        forloop(i,0,n){
            cin >> x[i];
        }

        if(s<=x[0])cout << x[n-1]-s << "\n";
        else if(s>=x[n-1])cout << s-x[0] << "\n";
        else {
            int mid = (x[0]+x[n-1])/2;
            if(s<=mid)cout << s-x[0]+x[n-1]-x[0] << "\n";
            else cout << x[n-1]-s+x[n-1]-x[0] << "\n";
        }

    }
}