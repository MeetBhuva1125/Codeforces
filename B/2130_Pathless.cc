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
        ll tar;
        cin >> n >> tar;
        
        v1d(int, arr, n);
        map<int, int> freq;
        ll ts = 0;

        forloop(i, 0, n){
            cin >> arr[i];
            freq[arr[i]]++;
            ts += arr[i];
        }

        if (tar < ts || tar == ts + 1){
            vector<int> res;

            forloop(i, 0, freq[0]){
                res.push_back(0);
            }
            forloop(i, 0, freq[2]){
                res.push_back(2);
            }
            forloop(i, 0, freq[1]){
                res.push_back(1);
            }

            forloop(i, 0, res.size()){
                cout << res[i] << (i == res.size() - 1 ? "" : " ");
            }
            cout << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}
