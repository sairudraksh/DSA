class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>map;
        int count=0;

        for(int i=0;i<n;i++){
            int target=k-nums[i];

            if(map.find(target)!=map.end()){
                count++;
                map[target]--;
                if(map[target]==0) map.erase(target);
            }

            else map[nums[i]]++;
        }
        return count;
    }
};