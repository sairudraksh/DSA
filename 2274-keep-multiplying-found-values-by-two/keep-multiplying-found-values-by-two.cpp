class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int,int>map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }

        int ans=original;
        while(true){
            if(map.find(original)==map.end()){
                return original;
            }
            original=original*2;
        }
        return original;
    }
};