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
        cin >> n;
        int cnt = 0;
        int prev_val = 0; // Represents the value of the element before the current one
        forloop(i,0,n) {
            int current_val;
            cin >> current_val;
            // If the current value is non-zero and the previous value was zero,
            // it signifies the start of a new block of non-zeros.
            if (current_val != 0 && prev_val == 0) {
                cnt++;
            }
            prev_val = current_val; // Update prev_val for the next iteration
        }

        // Output the minimum number of operations based on the derived logic
        // If cnt is 0, 0 operations.
        // If cnt is 1, 1 operation.
        // If cnt is 2 or more, 2 operations.
        cout << min(2, cnt) << "\n";
    }
}

