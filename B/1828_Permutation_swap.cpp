#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forloop(i, a, b) for (int i=a; i<b; i++)
#define forloopR(i, a, b) for(int i=a; i>=b; i--)
#define v1d(type, name, n) vector<type> name(n)
#define v2d(type, name, m, n) vector<vector<type>> name(m, vector<type>(n))

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int max_k = 0;
        forloop(i,0,n){
            int a;
            cin >> a;
            int diff = abs(a-i-1);
            if(diff != 0){
                max_k = gcd(max_k, diff);
            }
        }
        cout << max_k << "\n";
    }
}