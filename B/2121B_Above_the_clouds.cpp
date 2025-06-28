#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forloop(i, a, b) for (int i = a; i < b; i++)

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        string s;
        cin >> s;

        unordered_set<int> S;
        S.insert(s[0]);
        S.insert(s[n-1]);
        bool possible = false;
        for(int i=1; i<n-1; i++){
            if(S.count(s[i]))possible = true;
            else S.insert(s[i]);
        }

        if(possible)cout << "Yes\n";
        else cout << "No\n";
    }
}