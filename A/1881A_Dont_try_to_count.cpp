#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n,m;
        cin >> n >> m;
        
        string x;
        cin >> x;
        string s;
        cin >> s;

        int count=0;
        bool found=false;
        int res;
        while(x.size() < 50){
            res = x.find(s);
            if(res != string::npos){
                found=true;
                break;
            }
            x += x;
            count++;
        }
        if(found)cout << count <<"\n";
        else cout << -1 << "\n";
        
    }
    return 0;
}