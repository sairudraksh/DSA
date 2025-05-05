class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int max, int useLimit) {
        unordered_map<int,vector<int>>mp;
        int n=labels.size();
        for(int i=0;i<n;i++){
            if(mp.find(labels[i])!=mp.end()){
                mp[labels[i]].push_back(values[i]);
            }
            else mp[labels[i]] = {values[i]};
        }
        vector<int>v;
        for(auto x: mp){
            vector<int>v1=x.second;
            sort(v1.begin(),v1.end());
            reverse(v1.begin(),v1.end());
            int k=0;
            if(v1.size()<useLimit) k=v1.size();
            else k=useLimit;
            for(int i=0;i<k;i++){
                v.push_back(v1[i]);       
            }
        }
        int sum=0;
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        int k;
        if(max>v.size()) k=v.size();
        else k=max;
        for(int i=0;i<k;i++){
            sum=sum+v[i];
        }
        return sum;
    }
};