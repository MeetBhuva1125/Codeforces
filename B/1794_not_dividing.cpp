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
        v1d(int,a,n);
        forloop(i,0,n){
            cin >> a[i];
            if(a[i]==1)a[i]++;
        }
        forloop(i,0,n-1){
            if(a[i+1]%a[i]==0)a[i+1]++;
        }

        for(int &i:a){
            cout << i << " ";
        }
        cout << "\n";
    }
}