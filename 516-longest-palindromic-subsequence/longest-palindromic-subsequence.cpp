class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s2=s;
        reverse(s2.begin(),s2.end());
        string s1=s;
        
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> t(n+1,vector<int>(m+1));
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0 || j==0){
                    t[i][j]=0;
                }
            }
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s1[i-1]==s2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                
                else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        
        int temp=t[n][m];
        return temp;

    }
};