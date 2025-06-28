#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--){
        int n, k;
        cin >> n >> k;
        
        vector<long long> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        
        if(k >= 2){
            cout << "YES\n";
        }
        else{
            // Check if already sorted
            bool isSorted = true;
            for(int i = 1; i < n; i++){
                if(a[i-1] > a[i]){
                    isSorted = false;
                    break;
                }
            }
            cout << (isSorted ? "YES" : "NO") << "\n";
        }
    }
    
    return 0;
}