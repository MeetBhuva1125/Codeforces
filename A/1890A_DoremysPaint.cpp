#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int a[n];

        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            cin >> a[i];
            mp[a[i]]++;
        }
        if(mp.size()>2)cout << "NO\n";
        else if(mp.size()==1)cout << "Yes\n";
        else{
            int diff;
            diff = n-mp[a[0]];
            if (abs(diff-mp[a[0]])>1)cout << "NO\n";
            else cout << "YES\n";
        }
    }
    return 0;
}