#include<bits/stdc++.h>
using namespace std ;
#define int int64_t
 
 
 
//--------------------------------------------------Debuggger-----------------------------------------------------//
void dbg_out(){cerr << endl;}
    template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
    #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
//----------------------------------------------------------------------------------------------------------------//
 
 
 
// void solve()
// {
//                 /*PART     1*/
//     vector<string> grid;
//     string line;
//     while(getline(cin,line)){
//         if(line.empty()) break;
//         grid.push_back(line);
//     }


//     int rows=grid.size(); int cols=grid[0].size();
//     int ans=0;
//     // need start and end for down processing 
//     for(int c=0;c<cols;){ //col sweep

//         bool emptycol=true;
//         for(int r=0;r<rows;r++){
//             if(grid[r][c]!=' '){ emptycol=false; break;}
//         }
//         if(emptycol) {c++; continue;}
    
//     // start is set 
//         int start=c;
//         while(c<cols){
//             bool sep=true;
//             for(int r=0;r<rows;r++){
//                 if(grid[r][c]!=' '){ sep=false; break;}
//             }
//             if(sep) break;
//             c++;
//         }
//         int end=c-1; //need non empty 

//         vector<int> nums;
//         char op; 
//         for(int r=0;r<rows;r++){
//             string num;
//             for(int i=start;i<=end;i++){
//                 if(isdigit(grid[r][i])) num+=grid[r][i];
//                 else if(grid[r][i]=='+' || grid[r][i]=='*') op=grid[r][i];
//             }
//             if(!num.empty()) nums.push_back(stoll(num));
//         }

//         int problemans=(op=='+')?0:1; //start of mult chain or plus chain 
//         for(auto &v:nums){
//             if(op=='+') problemans+=v;
//             else problemans*=v;
//         }
//         ans+=problemans; //summing up ans of all the problems 
//     }
//     cout<<ans<<endl;
 
// }
 





void solve()
{
          /*PART     2*/
    vector<string> grid;
    string line;
    while(getline(cin,line)){
        if(line.empty()) break;
        grid.push_back(line);
    }

    int rows = grid.size();
    int cols = grid[0].size();

    int ans = 0;
    for(int c = 0; c < cols; ){

        bool emptycol = true;
        for(int r = 0; r < rows; r++){
            if(grid[r][c] != ' '){
                emptycol = false;
                break;
            }
        }
        if(emptycol){
            c++;
            continue;
        }

        // start of problem
        int start = c;
        while(c < cols){
            bool sep = true;
            for(int r = 0; r < rows; r++){
                if(grid[r][c] != ' '){
                    sep = false;
                    break;
                }
            }
            if(sep) break;
            c++;
        }
        int end = c - 1;

        vector<int> nums;
        char op = '?';
        // operator is on the last row // change 1
        for(int i=start;i<=end;i++){
            if(grid[rows-1][i] == '+' || grid[rows-1][i] == '*')
                op = grid[rows-1][i];
        }

        //right to left top to bottom reading now // change 2 
        for(int i = end; i >= start; i--){
            string num;
            for(int r = 0; r < rows - 1; r++){
                if(isdigit(grid[r][i]))
                    num += grid[r][i];
            }
            if(!num.empty())
                nums.push_back(stoll(num));
        }

        int problemans = (op == '+') ? 0 : 1;
        for(auto &v : nums){
            if(op == '+') problemans += v;
            else problemans *= v;
        }

        ans += problemans;
    }

    cout << ans << endl;
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