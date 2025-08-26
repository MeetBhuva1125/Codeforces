#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forloop(i, a, b) for (int i=a; i<b; i++)
#define forloopR(i, a, b) for(int i=a; i>=b; i--)
#define v1d(type, name, n) vector<type> name(n)
#define v2d(type, name, m, n) vector<vector<type>> name(m, vector<type>(n))

void solve(){
    long long n;
    cin >> n;
    vector<long long> res;
    long long num = 10;
    while(num < n){
        if(n%(num+1)==0){
            res.push_back(n/(num+1));
        }
        num = num*10;
    }
    cout << res.size() << "\n";
    if(res.size()==0)return;
    else {
        reverse(res.begin(), res.end());
        for(long long i:res){
            cout << i << " ";
        }
    }
    cout << "\n";
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