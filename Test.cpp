#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forloop(i, a, b) for (int i=a; i<b; i++)
#define forloopR(i, a, b) for(int i=a; i>=b; i--)
#define v1d(type, name, n) vector<type> name(n)
#define v2d(type, name, m, n) vector<vector<type>> name(m, vector<type>(n))

void solve(){
        cin.ignore();
        string line;
        getline(cin, line);
        stringstream ss(line);
        
        int num;
        int n=0;
        while (ss >> num) {
            cout << num << " ";
            n++;
        }
        cout <<"\n" << n ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    // cin.ignore(); // this is to ignore the newline character which is coming after pressing enter followed by t input

    while(t--){
        solve();
    }
}