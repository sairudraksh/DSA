class Solution {
public:
    const int M=1e9+7;
   vector<vector<vector<int>>> dp; 
    int find(vector<int>& nums,int i,int prev,int Sprev){
        if(i>=nums.size()){
            if(prev==-1 && Sprev==-1) return 0;
            return 1;
        }
        int p1=2;
        int p2=2;
        if(prev!=-1){
            if(nums[prev]%2==0) p1=0;
            else p1=1;// we did memoisation like this as memo0isation was only depending on whether prev and Sprev is even or odd so for odd keep 1 and for even keep 0 and for -1 keep 2 we dont have to keep whole value in dp array
        }
        if(Sprev!=-1){
            if(nums[Sprev]%2==0) p2=0;
            else p2=1;
        }
        if(dp[i][p1][p2]!=-1) return dp[i][p1][p2];
        if(prev==-1 || Sprev==-1){
            return dp[i][p1][p2]=(find(nums,i+1,i,prev)+find(nums,i+1,prev,Sprev))%M;
        }

        else{
            if(nums[prev]%2==0 && nums[Sprev]%2==0 && nums[i]%2==0){
                return dp[i][p1][p2]=find(nums,i+1,prev,Sprev)%M;
            }
            else if(nums[prev]%2!=0 && nums[Sprev]%2!=0 && nums[i]%2!=0){
                return dp[i][p1][p2]=find(nums,i+1,prev,Sprev)%M;
            }
            else{
                return dp[i][p1][p2]=(find(nums,i+1,i,prev)+find(nums,i+1,prev,Sprev))%M;
            }
        }
    }
    int countStableSubsequences(vector<int>& nums) {
        int n=nums.size();
        dp.assign(n, vector<vector<int>>(3, vector<int>(3, -1)));
        return find(nums,0,-1,-1)%M;
    }
};