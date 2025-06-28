#include<bits/stdc++.h>
using namespace std;

//Very easy logic but I was not able to spot it , took me time. The logic is putting largest element at first, which will make the array always beautiful(except one case: when all elements are same)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        
        bool allSame = true;
        for(int i = 1; i < n; i++) {
            if(a[i] != a[0]) {
                allSame = false;
                break;
            }
        }

        if(allSame) {
            cout << "NO\n";
        } else {
            // Find max element and put it first
            int maxIdx = 0;
            for(int i = 1; i < n; i++) {
                if(a[i] > a[maxIdx]) {
                    maxIdx = i;
                }
            }
            swap(a[0], a[maxIdx]);
            
            cout << "YES\n";
            for(int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << "\n";
        }
        
    }
    return 0;
}