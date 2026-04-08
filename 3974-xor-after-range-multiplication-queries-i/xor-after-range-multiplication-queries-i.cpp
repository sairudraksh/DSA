class Solution {
public:
    int mod=1e9+7;
    int xorAfterQueries(vector<int>& nums1, vector<vector<int>>& queries) {
        vector<long long>nums;
        for(int i=0;i<nums1.size();i++){
            nums.push_back(nums1[i]);
        }
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int k=queries[i][2];
            int v=queries[i][3];

            while(l<=r){
                nums[l]=(nums[l]*v)%mod;
                l+=k;
            }
        }
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum^=nums[i];
        }
        return sum;
    }
};