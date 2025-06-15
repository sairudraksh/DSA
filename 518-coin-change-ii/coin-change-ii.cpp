class Solution {
public:
    vector<vector<int>> dp;
    int find(vector<int>&coins,int amount,int idx){
        if(amount==0) return 1;
        if(idx==coins.size()) return 0;
        if(dp[idx][amount]!=-2) return dp[idx][amount];
        int sum=0;
        for(int i=idx;i<coins.size();i++){
            if(amount-coins[i]<0) continue;
            sum=sum+(find(coins,amount-coins[i],i));// 1 with 2 will be counted so why count 2 with 1 backword again so directly start from  currect index as it starts counting from current index ans also we can use current index multiple times but not previous is permutation would have given then older solutions would have been right but in combinationa repetition is not allower 1,2  and 2,1 is same and counted as 1 
        }
        return dp[idx][amount]=sum;
    }
    int change(int amount, vector<int>& coins) {
        dp = vector<vector<int>>(coins.size() + 1, vector<int>(amount + 1, -2));
        int idx=0;
        int a=find(coins,amount,idx);
        return a;
    }
};