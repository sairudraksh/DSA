class Solution {
public:
    int n;
    vector<int>dp;
    int find(vector<int>&nums,int &d,int i){
        if(i>=n || i<0) return 0;

        int maximum=0;
        if(dp[i]!=-1) return dp[i];
        for(int k=i+1;k<=i+d;k++){
            if(k>=n) break;

            if(nums[k]>=nums[i]) break;

            else{
                maximum=max(maximum,1+find(nums,d,k));
            }
        }

        for(int k=i-1;k>=i-d;k--){
            if(k<0) break;
            if(nums[k]>=nums[i]) break;

            else{
                maximum=max(maximum,1+find(nums,d,k));
            }
        }

        return dp[i]=maximum;
    }
    int maxJumps(vector<int>& arr, int d) {
        n=arr.size();
        dp.resize(n+1,-1);
        int maximum=0;

        for(int i=0;i<n;i++){
            maximum=max(maximum,find(arr,d,i));
        }
        return maximum+1;

    }
};