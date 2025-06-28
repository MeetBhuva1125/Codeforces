#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forloop(i, a, b) for (int i = a; i < b; i++)

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int mini = INT_MAX;
    int num;
    forloop(i,0,n){
        cin >> num;
        mini = min(mini, abs(0-num));
    }
    cout << mini << "\n";
}