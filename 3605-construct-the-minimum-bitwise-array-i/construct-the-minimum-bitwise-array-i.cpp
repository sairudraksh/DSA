class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>result;
        int n=nums.size();
        for(int i=0;i<n;i++){
            bool found=false;
            for(int j=0;j<nums[i];j++){
                if((j|j+1)==nums[i]){
                    found=true;
                    result.push_back(j);
                    break;
                }
            }
            if(found==false) result.push_back(-1);
        }
        return result;
    }
};