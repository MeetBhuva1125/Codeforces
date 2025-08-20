#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forloop(i, a, b) for (int i=a; i<b; i++)
#define forloopR(i, a, b) for(int i=a; i>=b; i--)
#define v1d(type, name, n) vector<type> name(n)
#define v2d(type, name, m, n) vector<vector<type>> name(m, vector<type>(n))

map<pair<int, int>, double> memo;

double calculate(int A, int B){
    if (A <= 0 && B <= 0) return 0.5;
    if (A <= 0) return 1.0;
    if (B <= 0) return 0.0;
    if (memo.count({A, B})) return memo[{A, B}];

    double res = calculate(A - 100, B) + calculate(A - 75, B - 25) + calculate(A - 50, B - 50) + calculate(A - 25, B - 75);

    return memo[{A, B}] = 0.25 * res;
}

void solve(){
        int n;
        cin >> n;

        if (n > 4800) {
            cout << fixed << setprecision(5) << 1.0 << "\n";
            return;
        }
        memo.clear();
        double ans = calculate(n,n);
        cout << fixed << setprecision(5) << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    // cin.ignore(); // this is to ignore the newline character which is coming after pressing enter followed by t input

    while(t--){
        solve();
    }
}