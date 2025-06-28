#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        string s(n, '0');
        if(k == 0 || k == n){
            // All 0s or all 1s
            if(k == n) s = string(n, '1');
            cout << s << '\n';
        }
        else{
            s[0] = '1';
            k--;
            for(int i = n - 2; i >= 1 && k > 0; i--){
                s[i] = '1';
                k--;
            }
            cout << s << "\n";
        }
    }
    return 0;
}