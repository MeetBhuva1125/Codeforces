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
        v1d(int,heights,n);

        forloop(i,0,n){
            cin >> heights[i];
        }
        int diff = heights[k-1];
        sort(heights.begin(), heights.end(), greater<int>());
        
        bool ans = true;
        forloop(i,1,n){
            if(heights[i-1]-heights[i] > diff){
                ans = false;
                break;
            }
        }
        cout << (ans?"yes\n":"no\n");
    }
}