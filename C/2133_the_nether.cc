#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forloop(i, a, b) for (int i=a; i<b; i++)
#define forloopR(i, a, b) for(int i=a; i>=b; i--)
#define v1d(type, name, n) vector<type> name(n)
#define v2d(type, name, m, n) vector<vector<type>> name(m, vector<type>(n))

void solve(){
    int n;
    cin>>n;
    unordered_map<int,vector<int>> mp;

    forloop(i,0,n){
        cout << "? " << i+1 << " " << n << " ";
        forloop(j,0,n){
            cout << j+1 << " ";
        }
        cout << "\n";
        cout.flush();
        int temp;
        cin >> temp;

        if(temp==-1){
            cout << "ERROR";
            return;
        }
        mp[temp].push_back(i+1);
    }

    int max_len = INT_MIN;
    for(const auto i:mp){
        max_len = max(i.first,max_len);
        // cout << i.first << " ";
        // for(int j:mp[i.first])cout << j;
        // cout << "\n\n";
    }
    // cout << max_len << " ";  


    vector<int> path;
    path.push_back(mp[max_len][0]);
    forloopR(i,max_len-1,1){
        if(mp[i].size()==1)path.push_back(mp[i][0]);
        else{
            for(const auto j:mp[i]){
                cout << "? " << path[0] << " " << path.size()+1 << " ";
                forloop(k,0,path.size())cout << path[k] << " ";
                cout << j;
                cout << "\n";
                cout.flush();
                int temp;
                cin >> temp;

                if(temp == path.size() + 1){
                    path.push_back(j);
                    break;
                }
            }
        }
    }

    cout << "! " << path.size() << " ";
    for(int i:path)cout << i << " ";
    cout << "\n";
    cout.flush();

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