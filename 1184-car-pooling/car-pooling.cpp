class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<vector<int>>v;

        for(int i=0;i<trips.size();i++){
            v.push_back({trips[i][1],trips[i][0]});
            v.push_back({trips[i][2],-trips[i][0]});
        }

        sort(v.begin(),v.end());

        int curr=0;

        for(int i=0;i<v.size();i++){
            curr+=v[i][1];

            if(curr>capacity) return false;
        }

        return true;
    }
};