class Solution {
public:
    long long maxArrayValue(vector<int>& v) {
        vector<long long>nums;
        int n=v.size();
        for(int i=0;i<n;i++){
            nums.push_back(v[i]);
        }
        int idx=-1;
        long long maximum=nums[0];
        for(int i=n-1;i>0;i--){
            if(nums[i]>=nums[i-1]){
                nums[i-1]=nums[i]+nums[i-1];
            }
        }
        for(int i=0;i<n;i++){
            maximum=max(maximum,nums[i]);
        }
        return maximum;
    }
};