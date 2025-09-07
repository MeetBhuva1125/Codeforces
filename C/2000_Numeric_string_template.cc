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
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    
    int m;
    cin>>m;
    
    while(m--){
        string s;
        cin>>s;
        
        if(s.size()!=n){
            cout<<"NO\n";
            continue;
        }
        
        bool ok=true;
        unordered_map<int,char> numToChar;
        unordered_map<char,int> charToNum;
        
        for(int i=0;i<n;i++){
            int num = a[i];
            char c = s[i];
            
            if(numToChar.count(num)){
                if(numToChar[num]!=c){
                    ok=false;
                    break;
                }
            } else {
                if(charToNum.count(c)){
                    if(charToNum[c]!=num){
                        ok=false;
                        break;
                    }
                } else {
                    numToChar[num]=c;
                    charToNum[c]=num;
                }
            }
        }
        
        cout<<(ok?"YES":"NO")<<"\n";
    }
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