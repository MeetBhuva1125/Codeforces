#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forloop(i, a, b) for (int i=a; i<b; i++)
#define forloopR(i, a, b) for(int i=a; i>=b; i--)
#define vI(type, name, n) vector<type> name(n)
#define vII(type, name, m, n) vector<vector<type>> name(m, vector<type>(n))

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int countOdd=0;
        forloop(i,0,n){
            int a;
            cin >> a;
            if(a%2)countOdd++;
        }
        cout << ((countOdd%2)?"No\n":"Yes\n");
    }
}