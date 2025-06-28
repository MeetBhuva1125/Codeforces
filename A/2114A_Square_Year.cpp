#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        string year;
        cin >> year;

        int y = stoi(year);
        int sqt = sqrt(y);

        if((sqt * sqt) == y){
            cout << 0<< " " << sqt << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
}