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
 /*
 PART 1  
 */
    // int ans=0;
    // string s;
    // while(cin>>s){
    //     vector<int> suffmax(s.size());
    //     suffmax[s.size()-1]=s.back()-'0';
    //     for(int i=s.size()-2;i>=0;i--){
    //         suffmax[i]=max((int)(s[i]-'0'),suffmax[i+1]);
    //     }
    //     int currmax=0;
    //     for(int i=0;i<s.size()-1;i++){
    //         int val=10*(s[i]-'0')+suffmax[i+1];
    //         currmax=max(currmax,val);
    //     }
    //     ans+=currmax;
    // }
    // cout<<ans<<endl;

    int ans=0;
    string s;
    while(cin>>s){
        int n=s.size();
        int rem=n-12;
        string st;
        for(auto &c:s){
            while(!st.empty() && rem>0 && st.back()<c){
                st.pop_back(); rem--;
            }
            st.push_back(c);
        }
        while(rem>0 && !st.empty()){
            st.pop_back(); rem--;
        }
        ans+=stoll(st.substr(0,12));
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