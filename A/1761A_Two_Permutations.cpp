#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n,a,b;
        cin >> n >> a >> b;

        if(a+b > n-2){
            if(a==b && a==n){
                cout << "YES\n";
            }
            else cout << "NO\n";
        }
        else cout << "YES\n";
    }
    return 0;
}