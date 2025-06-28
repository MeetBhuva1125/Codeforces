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
        ll w,h,a,b;
        cin >> w >> h >> a >> b;

        ll x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if(y1>y2){
            ll top, bottom, left, right;
            top = y2+b;
            bottom = y1;
            right = x1+a;
            left = x2;
            if(bottom - top < 0 && right - left == 1)
        }
    }
}