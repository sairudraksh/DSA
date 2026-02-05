class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int>result;

        int n=nums.size();
        for(int i=0;i<nums.size();i++){


            int k=nums[i];
            int j=i;
            if(nums[i]>=0){
                while(k>0){
                    if(j+1>=n) j=0;
                    else j++;
                    k--;
                }
            }
            else{
                k=k*-1;
                while(k>0){
                    if(j-1<0) j=n-1;
                    else j--;
                    k--;
                }
            }
            result.push_back(nums[j]);
        }
        return result;
    }
};