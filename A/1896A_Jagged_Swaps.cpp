#include<bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> &permutation, int n){
    for(int i=1; i<n; i++){
        if(permutation[i-1]>permutation[i])return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> permutation(n);
        for(int i=0; i<n; i++){
            cin >> permutation[i];
        }

        if(permutation[0]==1){
            cout << (isSorted?"YES\n":"NO\n"); 
        }
        else cout << "NO\n";
    }
    return 0;
}