#include<bits/stdc++.h>
using namespace std ;
#define int int64_t
 
 
 
//--------------------------------------------------Debuggger-----------------------------------------------------//
void dbg_out(){cerr << endl;}
    template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
    #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
//----------------------------------------------------------------------------------------------------------------//
 
 
 
void solve()
{
 
    vector<string> grid;
    string s;
    while(cin>>s) grid.push_back(s);
    int n=grid.size();
    int m=grid[0].size();


    /* PART 1      */
    // vector<pair<int,int>> dirs={{1,1},{1,-1},{0,1},{0,-1},{-1,0},{1,0},{-1,-1},{-1,1}};
    // int ans=0;
    // for (int r = 0; r < n; ++r) {
    //     for (int c = 0; c < m; ++c) {
    //         if(grid[r][c]=='.') continue;
    //         //else roll so check if <4 adjacent rolls
    //         int adj=0;
    //         for (auto &d : dirs) {
    //             int nr = r + d.first;
    //             int nc = c + d.second;
    //             if (nr >= 0 && nr < n && nc >= 0 && nc < m) { //oob check
    //                 if (grid[nr][nc] == '@') adj++;
    //             }
    //         }
    //         if(adj<4) ans++;
    //     }
    // }
    // cout<<ans<<endl;


    vector<pair<int,int>> dirs={{1,1},{1,-1},{0,1},{0,-1},{-1,0},{1,0},{-1,-1},{-1,1}};
    int ans=0;
    while(true){
        vector<pair<int,int>> remround;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if(grid[r][c]=='.') continue;
                int adj=0;
                for (auto &d : dirs) {
                    int nr = r + d.first;
                    int nc = c + d.second;
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m) { 
                        if (grid[nr][nc] == '@' ||grid[nr][nc]=='x') adj++;
                    }
                }
                if(adj<4) {
                    grid[r][c]='x';
                    remround.emplace_back(r,c);
                }
            }
        }
        if (remround.empty()) break;
        ans += remround.size();
        for (auto &[r,c] : remround) grid[r][c] = '.';
    }
    cout<<ans<<endl;
 
}
 
 
 
signed main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int tc=1;
    // cin>>tc;
 
    while(tc--)
    {
        solve();
    }
    return 0;
}