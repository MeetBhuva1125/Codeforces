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
        int n,k;
        cin >> n >> k;

        v1d(int, a, n);
        forloop(i,0,n){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int ans = 0;
        int cnt = 0;
        forloop(i,1,n){
            if(a[i]-a[i-1]<=k){
                cnt++;
            }else{
                ans = max(ans, cnt);
                cnt = 0;
            }
        }
        ans = max(ans, cnt);
        cout << n-(ans+1) << "\n";
    }
}