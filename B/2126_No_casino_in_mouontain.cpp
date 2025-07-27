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
        int n,k;
        cin >> n >> k;

        int count = 0;
        bool brk = false;
        int j = 0;
        forloop(i,0,n){
            int a;
            cin >> a;
            if(brk){
                brk = false;
                continue;
            }
            if(!a)j++;
            if(j==k){
                count++;
                brk = true;
                j=0;
            }
            if(a)j=0;
            // cout << j;
        }
        cout << count << "\n";
    }
}