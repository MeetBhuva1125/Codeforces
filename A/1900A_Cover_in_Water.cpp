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

        string s;
        cin >> s;

        int count = 0;
        bool threeEmptyCells = false;
        for(int i=0; i<n; i++){
            if(s[i]=='.'){
                count++;
                if(i>=1 && s[i-1]==s[i] && s[i]==s[i+1] && i<n-1)threeEmptyCells = true;
            }
        }

        cout << (threeEmptyCells?2:count) << "\n";
    }
    return 0;
}