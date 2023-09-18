int dp[1001][1001];
string s1,s2;
int m,n;

bool solve(int i,int j){
    if(i==m) return j==n;
    if(m-i<n-j) return 0;
    if(j==n and i!=m){
        for(;i<m;i++){
            if(isupper(s1[i])) return 0;
        }
        return 1;
    }
    if(isupper(s1[i]) and s1[i]!=s2[j]) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    
    bool b1=solve(i+1,j);
    if(toupper(s1[i])==s2[j]) b1=b1 or solve(i+1,j+1);
    dp[i][j]=b1?1:0;
    return b1;
}
string abbreviation(string a, string b) {
    memset(dp,-1,sizeof(dp));
    s1=a,s2=b;
    m=a.size(),n=b.size();
    return (solve(0,0))?"YES":"NO";   
    

}
