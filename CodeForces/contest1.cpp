#include<bits/stdc++.h>
using namespace std;
string solveRec(string &s,long int op,long int n,vector<string>&dp){
    //bc
    if(op>=n){
        return s; 
    }
    if(dp[op]!=""){
        return dp[op];
    }
    string org=s;
    reverse(s.begin(),s.end());
    string afterOp1=org+s;
    string afterOp2=s;
    string ans1=solveRec(afterOp1,op+1,n,dp);
    string ans2=solveRec(afterOp2,op+1,n,dp);

    dp[op]=(ans1<ans2) ? ans1:ans2;
    cout<<dp[op]<<endl;
    return dp[op];
}


int main(){
    int t;
    cin>>t;
    while(t--){
        long int n;
        cin>>n;
        string s;
        cin>>s;
        vector<string>dp(n+1,"");
        string ans=solveRec(s,0,n,dp);
        cout<<ans<<endl;       
    }
    return 0;
}