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
        int x;
        cin >> x;

        int mini = INT_MAX;
        while(x>0){
            mini = min(mini,x%10);
            // cout << mini;
            x/=10;
        }
        cout << mini << "\n";
    }
}