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
        ll n,k,x;
        cin >> n >> k >> x;

        ll sumTilln = (n*(n+1))/2;
        ll sumTillk = (k*(k+1))/2;
        ll reverseSum = sumTilln - ((n-k)*(n-k+1))/2;
        cout << ((sumTilln>= x && sumTillk<=x && x<=reverseSum)?"yes":"no") << "\n";
    }
}