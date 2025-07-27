#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define forloop(i, a, b) for (int i=a; i<b; i++)
#define forloopR(i, a, b) for(int i=a; i>=b; i--)

#define vI(type, name, n) vector<type> name(n)
#define vII(type, name, m, n) vector<vector<type>> name(m, vector<type>(n))

/**
 * @brief Solves the frog jumping problem using dynamic programming.
 *
 * The problem asks for the minimum cost to reach the last stone, given that the frog
 * can jump at most 'k' steps from its current stone. The cost of a jump is the
 * absolute difference in height between the current stone and the target stone.
 *
 * @param n The total number of stones.
 * @param k The maximum jump distance the frog can make.
 * @param height A vector containing the heights of each stone.
 * @return The minimum cost to reach the last stone.
 */
int solve(int n, int k, vector<int>& height){
    // dp[i] will store the minimum cost to reach stone 'i'.
    // Initialize with INT_MAX, except for dp[0] which is 0 (cost to reach first stone is 0).
    vector<int> dp(n, INT_MAX);

    dp[0] = 0; // Base case: Cost to reach the first stone (index 0) is 0.

    // Debugging output: Initial state of the DP table
    cout << "--- DP Calculation Steps ---" << endl;
    cout << "Initial DP table: ";
    for(int val : dp) {
        if (val == INT_MAX) cout << "INF ";
        else cout << val << " ";
    }
    cout << endl << endl;

    // Iterate through each stone from the second stone (index 1) up to the last stone.
    for(int i=1; i<n; i++){
        cout << "Calculating minimum cost to reach stone " << i << " (height: " << height[i] << ")" << endl;

        // For each stone 'i', consider all possible previous stones 'i-j' from which the frog could have jumped.
        // 'j' represents the jump distance, ranging from 1 to 'k'.
        for(int j=1; j<=k; j++){
            // Check if the previous stone 'i-j' is a valid index (non-negative).
            if(i - j >= 0){
                // Calculate the cost of the current jump from stone 'i-j' to stone 'i'.
                int current_jump_cost = abs(height[i] - height[i-j]);
                // Calculate the total candidate cost to reach stone 'i' via stone 'i-j'.
                int candidate_total_cost = dp[i-j] + current_jump_cost;

                // Debugging output for current jump consideration
                cout << "  Considering jump from stone " << i-j << " (height: " << height[i-j] << ") to stone " << i << endl;
                cout << "    Cost to reach stone " << i-j << " (dp[" << i-j << "]): " << dp[i-j] << endl;
                cout << "    Cost of jump from " << i-j << " to " << i << ": |" << height[i] << " - " << height[i-j] << "| = " << current_jump_cost << endl;
                cout << "    Total candidate cost via stone " << i-j << ": " << candidate_total_cost << endl;

                // If the candidate total cost is less than the current minimum cost to reach stone 'i', update dp[i].
                if (candidate_total_cost < dp[i]) {
                    cout << "    Updating dp[" << i << "] from " << (dp[i] == INT_MAX ? string("INF") : to_string(dp[i])) << " to " << candidate_total_cost << endl;
                } else {
                    cout << "    Current dp[" << i << "] (" << (dp[i] == INT_MAX ? string("INF") : to_string(dp[i])) << ") is already better or equal. No update." << endl;
                }
                dp[i] = min(dp[i], candidate_total_cost); // Update dp[i] with the minimum cost found so far.
            } else {
                // If 'i-j' is out of bounds, this jump is not possible.
                cout << "  Cannot jump from stone " << i-j << " as it's out of bounds (index < 0)." << endl;
            }
        }
        cout << "  Finished considering all possible jumps to stone " << i << "." << endl;
        cout << "  Current state of dp[" << i << "]: " << dp[i] << endl;
        // Debugging output: State of DP table after processing stone 'i'
        cout << "  DP table after processing stone " << i << ": ";
        for(int val : dp) {
            if (val == INT_MAX) cout << "INF ";
            else cout << val << " ";
        }
        cout << endl << endl;
    }

    // Debugging output: Final state of the DP table and the result
    cout << "--- DP Calculation Complete ---" << endl;
    cout << "Final DP table: ";
    for(int val : dp) {
        if (val == INT_MAX) cout << "INF ";
        else cout << val << " ";
    }
    cout << endl;

    cout << "Minimum cost to reach the last stone (index " << n-1 << ") is: " << dp[n-1] << endl;
    return dp[n-1]; // Return the minimum cost to reach the last stone.
}

/**
 * @brief Main function to handle input, call the solve function, and output results.
 * @return 0 if the program executes successfully.
 */
int main(){
    // Optimize C++ standard streams for faster input/output operations.
    ios_base::sync_with_stdio(false); // Unties C++ streams from C standard streams.
    cin.tie(nullptr); // Unties cin from cout, preventing flushing of cout before cin operations.
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t; // Read the number of test cases.

    // Loop through each test case.
    while(t--){
        int n, k;
        cout << "--- New Test Case ---" << endl;
        cout << "Enter number of stones (n) and max jump distance (k): ";
        cin >> n >> k; // Read the number of stones and maximum jump distance.

        vI(int, height, n); // Declare a vector to store stone heights.
        cout << "Enter " << n << " stone heights: ";
        // Read the heights of the stones.
        forloop(i, 0, n){
            cin >> height[i];
        }

        // Output the input parameters for the current test case.
        cout << "Input: n=" << n << ", k=" << k << ", heights=[";
        forloop(i, 0, n){
            cout << height[i] << (i == n-1 ? "" : ", ");
        }
        cout << "]" << endl;

        cout << "Calling solve function..." << endl;
        // Call the solve function with the current test case parameters.
        int result = solve(n, k, height);
        // Output the final result for the current test case.
        cout << "Final result for this test case: " << result << endl;
    }

    return 0; // Indicate successful program execution.
}

