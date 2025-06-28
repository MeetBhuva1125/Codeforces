#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n,x;
        cin >> n >> x;

        int a[n];
        int sum = 0;
        for(int i=0; i<n; i++){
            cin >> a[i];
            sum+=a[i];
        }
        if(n*x == sum)cout << "YES\n";
        else cout << "NO\n";

    }
}