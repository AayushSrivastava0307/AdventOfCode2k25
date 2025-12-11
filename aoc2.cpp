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
 
    string line;
    getline(cin,line);
    stringstream ss(line);
    string token;
    vector<pair<int,int>> rng;
    while(getline(ss,token,',')){
        int a,b;
        char dash;
        stringstream tt(token);
        tt>>a>>dash>>b;
        rng.emplace_back(a,b);
    }
    int ans=0;
    /*
                    PART 1 
    */
    // for(auto &[a,b]:rng){
    //     for(int i=a;i<=b;i++){
    //         string check=to_string(i);
    //         if(check.size()&1) continue;
    //         int mid=check.size()/2;
    //         if(stoll(check.substr(0,mid))==stoll(check.substr(mid))){
    //             ans+=i;
    //         }
    //     }
    // }
    // cout<<ans<<endl;

    for(auto &[a,b]:rng){
        for(int i=a;i<=b;i++){
        string s = to_string(i);
        int n = (int)s.size();
        bool rpt = false;
        for (int d=1; d<=n/2;d++) {
            if (n%d!=0) continue;
            bool ok = true;
            for (int pos=d; pos<n; pos+=d) {
                if (s.compare(pos, d, s, 0, d) != 0) { ok = false; break; } // not equal so break
            }
            if (ok) { rpt = true; break; } //set as true and break as one valid d is enough VIMP!
        }

        if (rpt) ans += i;
        }
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