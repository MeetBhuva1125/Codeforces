#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double dd;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_map<int,int> umpii;
typedef unordered_map<long long, long long> umpll;
typedef vector<int> v1i;
typedef vector<long long> v1l;
typedef vector<vector<int>> v2i;
typedef vector<vector<long>> v2l;

// Functions as alternatives to macros (more type-safe)
template<typename T>
vector<T> v1d_t(int n) { return vector<T>(n,0); }
template<typename T>
vector<vector<T>> v2d_t(int m, int n) { return vector<vector<T>>(m, vector<T>(n,0)); }

#define forloop(i, a, b) for(int i=a; i<b; i++)
#define forloopR(i, a, b) for(int i=a; i>=b; i--)
// #define v1d(type, name, n) vector<type> name(n,0)
// #define v2d(type, name, m, n) vector<vector<type>> name(m, vector<type>(n,0))

void solve(){
    int n,c,d;
    cin >> n >> c >> d;
    int mini = INT_MAX;
    v1i b(n*n);
    forloop(i,0,n*n){
            cin >> b[i];
            mini = min(mini,b[i]);
    }

    sort(b.begin(),b.end());

    v2i a(n,v1i(n));
    a[0][0] = mini;
    forloop(i,1,n){
        a[0][i] = a[0][i-1] + d;
    }
    forloop(i,1,n){
        forloop(j,0,n){
            a[i][j]=a[i-1][j] + c;
        }
    }
    v1i temp;
    forloop(i,0,n){
        forloop(j,0,n){
            temp.push_back(a[i][j]);
        }
    }
    sort(temp.begin(),temp.end());
    forloop(i,0,n*n){
        if(b[i]!=temp[i]){
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