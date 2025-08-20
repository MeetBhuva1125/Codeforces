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
        forloop(i,0,n){
            cin >> a[i];
        }

        vector<vector<pair<int,int>>> partitions;
        int i=0;
        while(i<n){
        if (a[i] == 0) {
            i++;
            continue;
            }
        vector<pair<int,int>> partition;
        int j=i;
        while(j<n && a[j] != 0){
            partition.push_back({a[j],j});
            j++;
        }
        partitions.push_back(partition);
        i=j;
    }
    pair<int,int> ans = {n, 0};
        int max_twos = 0;

        for(auto& part : partitions){
            int m = part.size();
            vector<int> negatives;
            int cur_twos = 0;

            forloop(i,0,m){
                if(abs(part[i].first)==2)cur_twos++;
                if(part[i].first<0)negatives.push_back(i);
            }

            if(negatives.size() % 2 == 0){
                if(cur_twos > max_twos){
                    max_twos = cur_twos;
                ans = {part[0].second, n - 1 - part[m-1].second};
                }
            }
            else{
            int first_neg = negatives.front();
                int twos_after = 0;
                forloop(k,first_neg+1,m){
                    if(abs(part[k].first) == 2) twos_after++;
                }
                if(twos_after > max_twos){
                    max_twos = twos_after;
                    ans = {part[first_neg+1].second, n - 1 - part[m-1].second};
                }

                int last_neg = negatives.back();
                int twos_before = 0;
            forloop(k,0,last_neg){
                    if(abs(part[k].first)==2)twos_before++;
                }
            if(twos_before > max_twos){
                    max_twos = twos_before;
                ans = {part[0].second, n - 1 - part[last_neg-1].second};
                }
            }
        }
        cout << ans.first << " " << ans.second << "\n";
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
