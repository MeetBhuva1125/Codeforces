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
        int n;
        cin >> n;
        
        int a[n];
        forloop(i,0,n){
            cin >> a[i];
        }

        bool beautiful = false;
        forloop(i,0,n){
            forloop(j,i+1,n){
                if(gcd(a[i],a[j])<=2){
                    beautiful = true;
                    break;
                }
            }
        }
        cout << (beautiful?"yes\n":"no\n");
    }
}