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
        cout << 2 * n - 1 << endl;
        for (int i = 1, x = 1; i < n; i++, x++) {
            cout << i << " 1 " << x << endl;
            cout << i << ' ' << x + 1 << ' ' << n << endl;
        }
        cout << n << " 1 " << n << endl;
    }
}