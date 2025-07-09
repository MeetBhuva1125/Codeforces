#include <bits/stdc++.h>
using namespace std;

// DFS function to find the size of a connected component
void dfs(int u, vector<bool>& visited, const vector<vector<int>>& adj, int& current_size) {
    visited[u] = true;
    current_size++;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, visited, adj, current_size);
        }
    }
}

// Helper function to check if a given threshold is valid
bool isValidThreshold(int threshold, int num_cities, const vector<pair<int, int>>& flights, const vector<int>& air_indices, int k) {
    // 1. Build the graph only with nodes meeting the threshold
    vector<vector<int>> adj(num_cities);
    vector<int> valid_nodes;
    for (int i = 0; i < num_cities; ++i) {
        if (air_indices[i] >= threshold) {
            valid_nodes.push_back(i);
        }
    }

    // Optimization: not enough nodes to form a component of size k
    if (valid_nodes.size() < k) {
        return false;
    }

    for (const auto& flight : flights) {
        // Check if both cities in a flight meet the air index criteria
        if (air_indices[flight.first] >= threshold && air_indices[flight.second] >= threshold) {
            adj[flight.first].push_back(flight.second);
            adj[flight.second].push_back(flight.first);
        }
    }

    // 2. Find the largest connected component in the filtered graph
    vector<bool> visited(num_cities, false);
    int max_component_size = 0;

    for (int node : valid_nodes) {
        if (!visited[node]) {
            int current_size = 0;
            dfs(node, visited, adj, current_size);
            max_component_size = max(max_component_size, current_size);
        }
    }

    return max_component_size >= k;
}

// Main function to find the maximum threshold
int findMaxThreshold(int num_cities, const vector<pair<int, int>>& flights, const vector<int>& air_indices, int k) {
    // Get unique, sorted air index values for binary search
    set<int> unique_indices_set(air_indices.begin(), air_indices.end());
    vector<int> unique_indices(unique_indices_set.begin(), unique_indices_set.end());
    
    if (unique_indices.empty()) {
        return -1;
    }

    int low = 0;
    int high = unique_indices.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid_idx = low + (high - low) / 2;
        int potential_threshold = unique_indices[mid_idx];

        if (isValidThreshold(potential_threshold, num_cities, flights, air_indices, k)) {
            // This threshold works, try for a higher one
            ans = potential_threshold;
            low = mid_idx + 1;
        } else {
            // This threshold is too high, try a lower one
            high = mid_idx - 1;
        }
    }

    return ans;
}

// --- Example Usage ---
int main() {
    // 8 cities, numbered 0 to 7
    int num_cities = 8;
    
    // Air index for each city
    vector<int> air_indices = {10, 20, 30, 80, 90, 100, 5, 110};
    
    // Flights between cities
    vector<pair<int, int>> flights = {
        {0, 1}, {1, 2}, {0, 2},  // Component 1 (low air index)
        {3, 4}, {4, 5}, {3, 5},  // Component 2 (high air index)
        {6, 7}                   // Component 3
    };
    
    // We need a component of at least size 3
    int k = 3;

    int max_threshold = findMaxThreshold(num_cities, flights, air_indices, k);

    if (max_threshold != -1) {
        cout << "The maximum threshold to get a component of size at least " << k << " is: " << max_threshold << endl;
        // Expected output: 80
        // At threshold 80, cities 3, 4, 5 (air indices 80, 90, 100) are connected and form a component of size 3.
        // At threshold 90, only cities 4, 5, 7 would remain, and the largest component {4, 5} is size 2, which is < k.
    } else {
        cout << "No threshold allows for a component of size " << k << "." << endl;
    }

    return 0;
}