class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        unordered_map<int,int>map;
        int n=nums.size();

        for(int i=0;i<n;i++){
            int st=nums[i][0];
            int end=nums[i][1];

            for(int j=st;j<=end;j++){
                map[j]++;
            }
        }

        return map.size();
    }
};