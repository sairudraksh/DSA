class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        map<int,int>mp;
        for(int i=0;i<bulbs.size();i++){
            mp[bulbs[i]]++;
        }
        vector<int>v;
        for(auto x:mp){
            if(x.second%2!=0){
                v.push_back(x.first);
            }
        }
        return v;
    }
};