class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int n2=arr2.size();
        int x=n-n2;
        unordered_map<int,int>mp;
        vector<int>v;
        for(int i=0;i<n;i++){
            mp[arr1[i]]++;
        }
        for(int i=0;i<n2;i++){
            while(mp[arr2[i]]!=0){
                v.push_back(arr2[i]);
                mp[arr2[i]]--;
            }
            if(mp[arr2[i]]==0) mp.erase(arr2[i]);
        }
        vector<int>v2;
        for(int i=0;i<n;i++){
            while(mp[arr1[i]]>0){
                v2.push_back(arr1[i]);
                mp[arr1[i]]--;
            }
            if(mp[arr1[i]]==0) mp.erase(arr1[i]);
        }
        sort(v2.begin(),v2.end());
        for(int i=0;i<v2.size();i++){
            v.push_back(v2[i]);
        }
        return v;
    }
};