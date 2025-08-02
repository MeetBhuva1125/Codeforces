#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forloop(i, a, b) for (int i=a; i<b; i++)
#define forloopR(i, a, b) for(int i=a; i>=b; i--)
#define v1d(type, name, n) vector<type> name(n)
#define v2d(type, name, m, n) vector<vector<type>> name(m, vector<type>(n))

// DSU functions. The 'p' map is passed by reference to ensure it's
// correctly managed for each test case within the solve() function.
int find_set(int v, map<int, int>& p) {
    // If 'v' is its own parent, it's the root of its set
    if (v == p[v])
        return v;
    // Path compression: set parent[v] directly to the root
    return p[v] = find_set(p[v], p);
}

bool union_sets(int a, int b, map<int, int>& p) {
    a = find_set(a, p);
    b = find_set(b, p);
    if (a != b) {
        // Union by setting one root's parent to the other root
        p[b] = a;
        return true;
    }
    return false; // Already in the same set
}

// The core logic, analogous to your Python solve() function
void solve() {
    int n;
    cin >> n;

    // Use v1d macro for edges, as 'n' is the number of edges
    vector<pair<int,int>> edges(n);

    set<int> nodes; // To collect all unique node IDs
    forloop(i, 0, n) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v}; // Store the edge
        nodes.insert(u);   // Add nodes to the set
        nodes.insert(v);
    }

    // Initialize DSU parent map 'p' for all unique nodes found.
    // This map is local to solve() so it's fresh for each test case.
    map<int, int> p;
    for (int node : nodes) {
        p[node] = node; // Each node is initially its own parent
    }

    vector<int> ans; // To store the 1-based indices of edges that form new connections
    forloop(i, 0, n) {
        int u = edges[i].first;
        int v = edges[i].second;
        // If union_sets returns true, it means u and v were in different
        // components and have now been connected by this edge.
        if (union_sets(u, v, p)) {
            ans.push_back(i + 1); // Store 1-based index
        }
    }

    // Print results
    cout << ans.size() << "\n";
    forloop(i, 0, ans.size()) {
        cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        solve(); // Call solve() for each test case
    }
    return 0;
}

