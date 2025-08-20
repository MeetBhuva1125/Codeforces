#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forloop(i, a, b) for (int i=a; i<b; i++)
#define forloopR(i, a, b) for(int i=a; i>=b; i--)
#define v1d(type, name, n) vector<type> name(n)
#define v2d(type, name, m, n) vector<vector<type>> name(m, vector<type>(n))

void solve(){
    int n;
    cin >> n;
    v1d(int, a, n);
    vector<int> existing_nums;
    forloop(i, 0, n) {
        cin >> a[i];
        if (a[i] != -1) {
            existing_nums.push_back(a[i]);
        }
    }

    if (existing_nums.empty()) {
        cout << "yes\n";
        return;
    }

    int required_val = existing_nums[0];
    for (int num : existing_nums) {
        if (num == 0) {
            cout << "no\n";
            return;
        }
        if (num != required_val) {
            cout << "no\n";
            return;
        }
    }

    cout << "yes\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}