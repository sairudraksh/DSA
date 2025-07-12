class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        long long total=0;
        long long ans=LLONG_MIN;
        unordered_map<long long,long long>mp;
        for(int i=0;i<wall.size();i++){
            total=0;
            for(int j=0;j<wall[i].size()-1;j++){
                total+=(long long)wall[i][j];
                mp[total]++;
                ans=max(ans,(long long)mp[total]);
            }
        }
        if(ans==LLONG_MIN) return wall.size();
        return (int)wall.size()-ans;
    }
};