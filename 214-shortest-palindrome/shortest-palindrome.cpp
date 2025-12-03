class Solution {
public:
    string shortestPalindrome(string str) { 
        string st=str;
        string s=str;
        reverse(st.begin(),st.end());
        s+='#';
        s+=st;
        int n=s.length();
        int i=1;
        vector<int>LPS(n,0);
        int length=0;
        while(i<n){
            if(s[i]==s[length]){
                length++;
                LPS[i]=length;
                i++;
            }
            else{
                if(length!=0) length=LPS[length-1];
                else{
                    LPS[i]=0;
                    i++;
                }
            }
        }
        int x=str.length()-LPS[n-1];
        string ans="";
        for(int i=0;i<x;i++){
            ans+=st[i];
        }
        ans+=str;
        return ans;
    }
};