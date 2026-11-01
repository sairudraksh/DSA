class Solution {
public:
    bool checkValid(vector<vector<int>>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            unordered_map<int,int>map;
            for(int j=0;j<n;j++){
                map[nums[i][j]]++;
            }
            if(map.size()!=n) return false;
        }
        for(int i=0;i<n;i++){
            unordered_map<int,int>map;
            for(int j=0;j<n;j++){
                map[nums[j][i]]++;
            }
            if(map.size()!=n) return false;
        }
        return true;
    }
};