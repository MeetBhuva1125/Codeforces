#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double dd;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

// Functions as alternatives to macros (more type-safe)
template<typename T>
vector<T> v1d_t(int n) { return vector<T>(n,0); }
template<typename T>
vector<vector<T>> v2d_t(int m, int n) { return vector<vector<T>>(m, vector<T>(n,0)); }

#define forloop(i, a, b) for (int i=a; i<b; i++)
#define forloopR(i, a, b) for(int i=a; i>=b; i--)
#define v1d(type, name, n) vector<type> name(n,0)
#define v2d(type, name, m, n) vector<vector<type>> name(m, vector<type>(n,0))

struct cmpr{
    bool operator()(pii& a,pii& b){
        if(a.first == b.first)return a.second > b.second;
        return a.first < b.first;
    }
};

void solve(){
    int n,k;
    cin >> n >> k;
    priority_queue<pii, vector<pii>, cmpr> pq;
    forloop(i,0,n){
        int a;
        cin >> a;
        int tmp = ((a%k)?a%k:k);
        if(tmp==k){
            pq.push({k,i+1});
        }
        else pq.push({tmp,i+1});
    }

    while(!pq.empty()){
        cout << pq.top().second << " ";
        pq.pop();
    }
    cout << "\n";
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