class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>diff(n,0);

        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];

            diff[l]++;
            if(r+1<n){
                diff[r+1]--;
            }
        }
        int extra=0;
        for(int i=0;i<nums.size();i++){
            extra+=diff[i];
            if(nums[i]-extra>0) return false;
        }
        return true;
        

    }
};