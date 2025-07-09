#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forloop(i, a, b) for (int i=a; i<b; i++)
#define forloopR(i, a, b) for(int i=a; i>=b; i--)

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int a,a1,a2;
        forloop(i,0,n){
            cin >> a;
            if(i==0){
                a1=a;
            }
            else if(i==1){
                a2=a;
            }
        }
        if(a1<a2){
            cout << 2*a1 << "\n";
        }
        else{
            cout << a1+a2 << "\n";
        }
    }
}