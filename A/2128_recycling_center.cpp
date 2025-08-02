#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forloop(i, a, b) for (int i=a; i<b; i++)
#define forloopR(i, a, b) for(int i=a; i>=b; i--)
#define v1d(type, name, n) vector<type> name(n)
#define v2d(type, name, m, n) vector<vector<type>> name(m, vector<type>(n))

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        ll c;
        cin >> n >> c;
        vector<ll> a(n);
        forloop(i,0,n){
            cin >> a[i];
        }

        ll cost = 0;
        vector<ll> cheap_bags;
        for(ll val : a){
            if(val > c){
                cost++;
            } else {
                cheap_bags.push_back(val);
            }
        }

        vector<int> deadlines;
        for(ll val : cheap_bags){
            ll current_val = val;
            int k = 0;
            while(true){
                if(current_val > c) break;
                k++;
                if (c / 2 < current_val) { // Avoid overflow on current_val * 2
                    break;
                }
                current_val *= 2;
            }
            deadlines.push_back(k);
        }

        sort(deadlines.begin(), deadlines.end());
        int succeeded = 0;
        for(int d : deadlines){
            if(d >= succeeded + 1){
                succeeded++;
            }
        }

        cout << (cheap_bags.size() - succeeded) + cost << "\n";
    }
}
