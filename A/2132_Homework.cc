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
    string a;
    cin >> a;
    int m;
    cin >> m;
    string b,c;
    cin >> b;
    cin >> c;

    deque<char> dq(a.begin(),a.end());
    forloop(i,0,m){
        if(c[i] == 'V'){
            dq.push_front(b[i]);
        }
        else{
            dq.push_back(b[i]);
        }
    }

    for(char ch:dq){
        cout << ch;
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