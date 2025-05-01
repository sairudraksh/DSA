class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        unordered_map<int,int>map;
        for(int i=0;i<n;i++){
            int target=k-nums[i];
            if(map[target]>0){
                count++;
                map[target]--;
            }
            else{
                map[nums[i]]++;
            }
        }
        return count;
    }
};