class Solution {
public:
    int n;
    vector<vector<int>>dp;
    bool isTrue(string &s1,string &s2){
        if(s1.length()-s2.length()!=1) return false;
        int j=0;
        for(int i=0;i<s1.length();i++){
            if(j<s2.length() && s1[i]==s2[j]) j++;
        }
        return j==s2.length();
    }
    int find(vector<string>&nums,int i,int prev){
        while(i<n && prev!=-1 && nums[i].length()==nums[prev].length()){
            i++;
        }
        if(i>=n) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        if(prev==-1){
            return dp[i][prev+1]=max(1+find(nums,i+1,i),find(nums,i+1,prev));
        }
        else{
            if(isTrue(nums[i],nums[prev])){
                return dp[i][prev+1]=max(find(nums,i+1,prev),1+find(nums,i+1,i));
            }
            else{
                return dp[i][prev+1]=find(nums,i+1,prev);
            }
        }
    }
    int longestStrChain(vector<string>& words) {
        n=words.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        sort(words.begin(), words.end(), [](const string &a,const string &b){// sorting wrt to length
            return a.size() < b.size();
        });
        return find(words,0,-1);
    }
};