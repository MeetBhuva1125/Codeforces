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

    string base3 = "";
    while (n > 0) {
        base3 = to_string(n % 3) + base3;
        n /= 3;
    }
    
    auto coins_calc = [](int power){
        return pow(3,power+1) + (power*pow(3,power-1));
    };

    long long ans = 0;
    forloop(i,0,base3.size()){
        ans+=coins_calc(base3.size()-i-1)*(base3[i]-'0');
    }

    cout << ans << "\n";
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