#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forloop(i, a, b) for (int i = a; i < b; i++)
#define forloopR(i, a, b) for(int i=a; i>=b; i--)

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int eff;
        int ans = 0;
        forloop(i,0,n-1){
            cin >> eff;
            ans += eff;
        }
        cout << 0-ans << "\n";
    }
}