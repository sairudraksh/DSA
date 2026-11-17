class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        int n=nums.size();

        unordered_map<int,int>map;

        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }

        int m=moveFrom.size();
        for(int i=0;i<m;i++){
            int num=map[moveFrom[i]];
            map.erase(moveFrom[i]);
            map[moveTo[i]]+=num;
        }
        vector<int>v;
        for(auto x:map){
            v.push_back(x.first);
        }
        sort(v.begin(),v.end());
        return v;
    }
};