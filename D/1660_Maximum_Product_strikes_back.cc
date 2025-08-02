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
        v1d(int, a, n);
        forloop(i,0,n){
            cin >> a[i];
        }

        vector<vector<pair<int,int>>> partitions;
        int i=0;
        while(i<n){
            vector<pair<int,int>> partition;
            int j=i;
            while(j<n){
                if(a[j]!=0)partition.push_back({a[j],j});
                else {
                    partitions.push_back(partition);
                    i=j+1;
                    break;
                }
                j++;
            }
        }

        tuple<int,int> ind;
        for(auto part : partitions){
            
        }

        
    }
}