class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        vector<int>v;
        for(int i=0;i<k;i++){
            if(v.size()==k) break;
            int max=INT_MIN;
            for(auto x: mp){
                if(x.second>max) max=x.second;
            }
            int ans=0;
            vector<int>v2;
            for(auto x1: mp){
                if(x1.second==max){
                    v.push_back(x1.first);
                    v2.push_back(x1.first);
                    if(v.size()==k) break;
                }
            }
            for(int l=0;l<v2.size();l++){
                mp.erase(v2[l]);
            }
            
        }
        return v;
    }
};