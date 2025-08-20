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
    int total_xor_sum = 0;
    forloop(i,0,n){
        int a;
        cin >> a;
        total_xor_sum = total_xor_sum^a;
    }

    if (n % 2 == 1) {
        cout << total_xor_sum << "\n";
    } else {
        if (total_xor_sum == 0) {
            cout << 0 << "\n";
        } else {
            cout << -1 << "\n";
        }
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