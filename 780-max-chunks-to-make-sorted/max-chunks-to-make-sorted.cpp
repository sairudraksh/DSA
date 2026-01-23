class Solution {
public:
    int maxChunksToSorted(vector<int>& nums) {
        int n=nums.size();
        int maxnum=0;

        int count=0;
        for(int i=0;i<n;i++){
            maxnum=max(maxnum,nums[i]);
            if(maxnum==i){
                count++;
            }
        }
        return count;
    }
};
