#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin >> n;
    
    // Store queues for each person
    vector<queue<int>> queues(n);
    
    // Read input
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            int x;
            cin >> x;
            queues[i].push(x-1); // Convert to 0-indexed
        }
    }
    
    int time = 0;
    
    // Continue until all queues are empty
    while(true){
        // Check if all queues are empty first
        bool all_empty = true;
        for(int i = 0; i < n; i++){
            if(!queues[i].empty()){
                all_empty = false;
                break;
            }
        }
        if(all_empty) break;
        
        // Try to find matches in this round
        bool found_match = false;
        vector<bool> used(n, false);
        
        for(int i = 0; i < n; i++){
            if(used[i] || queues[i].empty()) continue;
            
            int target = queues[i].front();
            
            // Check if target wants to shake hands with i
            if(target < n && !used[target] && !queues[target].empty() && queues[target].front() == i){
                // Match found!
                queues[i].pop();
                queues[target].pop();
                used[i] = used[target] = true;
                found_match = true;
            }
        }
        
        // If no matches found, deadlock
        if(!found_match){
            cout << -1 << endl;
            return 0;
        }
        
        time++;
    }
    
    cout << time << endl;
    return 0;
}