class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int k=0;
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=k;j<n;j++){
                if(nums[j]>nums[i]){
                    k=j+1;
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};