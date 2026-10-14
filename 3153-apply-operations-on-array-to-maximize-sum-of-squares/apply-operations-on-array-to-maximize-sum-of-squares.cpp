class Solution {
public:
    long long mod=1e9+7;
    int maxSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>count(32,0);
        for(int i=0;i<n;i++){
            for(int b=0;b<32;b++){
                if(nums[i] & (1<<b)){
                    count[b]++;
                }
            }
        }
        long long result=0;

        while(k--){
            long long curr=0;

            for(int b=0;b<32;b++){
                if(count[b]>0){
                    count[b]--;

                    curr=(curr|(1<<b));
                }
            }
            result=(result+(curr*curr))%mod;
        }
        return result;
    }
};