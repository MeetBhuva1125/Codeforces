#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forloop(i, a, b) for (int i=a; i<b; i++)
#define forloopR(i, a, b) for(int i=a; i>=b; i--)

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int a,b;
        cin >> a >> b;

        pair<int,int> K;
        cin >> K.first >> K.second;
        pair<int,int> Q;
        cin >> Q.first >> Q.second;

        int dir[4][2] = {{1,1},{1,-1},{-1,1},{-1,-1}};

        //checking all possible moves of knight from kings position
        set<pair<int,int>> kings, queens;
        forloop(i,0,4){
            kings.insert({K.first+a*dir[i][0], K.second+b*dir[i][1]});
        }
        //reversing the moves of knight moves
        swap(a,b);
        forloop(i,0,4){
            kings.insert({K.first+a*dir[i][0], K.second+b*dir[i][1]});
        }

        forloop(i,0,4){
            queens.insert({Q.first+a*dir[i][0], Q.second+b*dir[i][1]});
        }
        //reversing the moves of knight moves
        swap(a,b);
        forloop(i,0,4){
            queens.insert({Q.first+a*dir[i][0], Q.second+b*dir[i][1]});
        }

        // Count the number of same pairs in kings and queens
        int count = 0;
        for (const auto& pos : kings) {
            if (queens.count(pos)) count++;
        }
        cout << count << '\n';
    }
}