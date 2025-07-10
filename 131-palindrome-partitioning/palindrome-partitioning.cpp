class Solution {
public:
    vector<vector<string>>v;
    bool ispalindrome(string &ans){
        if(ans.length()==1) return true;
        int i=0;
        int j=ans.length()-1;
        while(i<=j){
            if(ans[i]!=ans[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void find(string &s,int &n,vector<string>&ans,int i){
        if(i>=n){
            v.push_back(ans);
            return;
        }
        string ans1="";
        for(int k=i;k<n;k++){
            ans1+=s[k];
            if(ispalindrome(ans1)==true){
                ans.push_back(ans1);
                find(s,n,ans,k+1);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.length();
        vector<string>ans;
        find(s,n,ans,0);
        return v;
    }
};