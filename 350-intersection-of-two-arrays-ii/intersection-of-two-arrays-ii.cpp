class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        unordered_map<int,int>map1;
        unordered_map<int,int>map2;
        for(int i=0;i<n;i++){
            map1[nums1[i]]++;
        }

        for(int i=0;i<m;i++){
            map2[nums2[i]]++;
        }
        vector<int>ans;
        for(auto &x:map1){
            if(map2.find(x.first)!=map2.end()){
                int a=min(map2[x.first],x.second);
                for(int i=0;i<a;i++){
                    ans.push_back(x.first);
                }
            }
        }
        return ans;
    }
};