class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>result1;
        vector<int>result2;
        int n=nums.size();
        result1.push_back(nums[0]);
        result2.push_back(nums[1]);

        for(int i=2;i<n;i++){
            int last1=result1[result1.size()-1];
            int last2=result2[result2.size()-1];

            if(last1>last2){
                result1.push_back(nums[i]);
            }
            else{
                result2.push_back(nums[i]);
            }
        }   
        vector<int>ans;
        for(int i=0;i<result1.size();i++){
            ans.push_back(result1[i]);
        }
        for(int i=0;i<result2.size();i++){
            ans.push_back(result2[i]);
        }
        return ans;
    }
};