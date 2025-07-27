#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forloop(i, a, b) for (int i=a; i<b; i++)
#define forloopR(i, a, b) for(int i=a; i>=b; i--)
#define vI vector<int>
#define VII vector<vector<int>> 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        ll n,k;
        cin >> n >> k;

        
        if(n%2){
            if(k%2)cout << "Yes\n";
            else cout << "No\n";
        }
        else cout << "Yes\n";
    }
}