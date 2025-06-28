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
        int n;
        cin >> n;
        ll maxi = INT_MIN;
        ll a[n];
        int sum = 0;
        forloop(i,0,n){
            cin >> a[i];
            maxi = max(maxi,a[i]);
            sum+=a[i];
        }

        if(sum/n == maxi) cout << -1 <<"\n";
        else{
            int countMax = 0;
            forloop(i,0,n){
                if(a[i]==maxi){
                    countMax++;
                    a[i]=-1;
                }
            }
            cout << n-countMax << " " << countMax << "\n";
            forloop(i,0,n){
                if(a[i]!=-1){
                    cout << a[i] << " ";
                }
            }
            cout << "\n";
            forloop(i,0,countMax){
                cout << maxi << " ";
            }
            cout << "\n";
        }
    }
}