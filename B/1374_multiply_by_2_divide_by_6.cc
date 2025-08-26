#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double dd;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

// Functions as alternatives to macros (more type-safe)
template<typename T>
vector<T> v1d_t(int n) { return vector<T>(n,0); }
template<typename T>
vector<vector<T>> v2d_t(int m, int n) { return vector<vector<T>>(m, vector<T>(n,0)); }

#define forloop(i, a, b) for (int i=a; i<b; i++)
#define forloopR(i, a, b) for(int i=a; i>=b; i--)
#define v1d(type, name, n) vector<type> name(n)
#define v2d(type, name, m, n) vector<vector<type>> name(m, vector<type>(n))

void solve(){
    ll n;
    cin >> n;

    int cnt_2_fct = 0;
    int cnt_3_fct = 0;

    int temp = n;
    while(temp%2==0){
        cnt_2_fct++;
        temp/=2;
    }
    while(temp%3==0){
        cnt_3_fct++;
        temp/=3;
    }
    // cout << cnt_2_fct << " " << cnt_3_fct << "\n";
    if(cnt_2_fct>cnt_3_fct || temp>1){
        cout << -1 << "\n";
        return;
    }
    int mul_2 = cnt_3_fct-cnt_2_fct;
    int ans = log(n*pow(2,mul_2))/log(6);
    cout << mul_2+ans << "\n";


    // cout << ans + mul_2 << "\n";
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