class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefix(n,nums[0]);

        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }

        int t=0;
        int p=k-1;

        vector<int>dp(n,0);

        vector<int>dp2(n,-1);
        dp[p]=prefix[p];
        t++;
        p++;

        for(int l=p;l<n;l++){
            dp[l]=prefix[l]-prefix[t-1];
            t++;
        }
        dp2[n-k]=n-k;
        for(int q=n-k-1;q>=0;q--){
            if(dp[q+k-1]>=dp[dp2[q+1]+k-1]){
                dp2[q]=q;
            }
            else dp2[q]=dp2[q+1];
        }

        int maximum=0;
        int idx1=-1;
        int idx2=-1;
        int idx3=-1;
        for(int i=0;i<=n-3*k;i++){
            for(int j=i+k;j<=n-2*k;j++){
                int l=dp2[j+k];

                int sum=dp[i+k-1]+dp[j+k-1]+dp[l+k-1];

                if(sum>maximum){

                    maximum=sum;
                    idx1=i;
                    idx2=j;
                    idx3=l;
                }
                
            }

        }

        return {idx1,idx2,idx3};
    }
};