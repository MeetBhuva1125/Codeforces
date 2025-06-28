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
        int x,k;
        cin >> x >> k;
        
        if(x%k!=0){
            cout << 1 << "\n" << x << "\n";
        }
        else cout<<2<<"\n"<<x-1<<" "<<1<<"\n";
    }
}