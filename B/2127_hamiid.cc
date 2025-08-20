#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forloop(i, a, b) for (int i=a; i<b; i++)
#define forloopR(i, a, b) for(int i=a; i>=b; i--)
#define v1d(type, name, n) vector<type> name(n)
#define v2d(type, name, m, n) vector<vector<type>> name(m, vector<type>(n))

void solve(){
    int n,x;
    cin >> n >> x;

    string s;
    cin >> s;
    // int farthest_left=0;
    // int farthest_right=n;
    int closest_left=0;
    int closest_right=n;
    forloop(i,0,x){
        if(s[i]=='#')closest_left=i+1;
    }
    // cout << closest_left << " ";
    forloopR(i,n-1,x-1){
        if(s[i]=='#')closest_right=i+1;
    }
    // cout << closest_right << "\n";
    if(x==1 || x==n){
        cout << 1 << "\n";
        return;
    }
    if(closest_left==0 && closest_right==n){
        cout << 1 << "\n";
        return;
    }
    int left_moves = closest_left - 1 + 2;
    int right_moves = n - closest_right + 2;
    if (x > 1 && s[x-2] == '.') {
        right_moves = n - closest_right + 2;
        left_moves = x - 1 + 2;
    }

    if (x < n && s[x] == '.') {
        left_moves = closest_left - 1 + 2;
        right_moves = n - x+1 + 2;
    }

    cout << min(left_moves, right_moves) << "\n";
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