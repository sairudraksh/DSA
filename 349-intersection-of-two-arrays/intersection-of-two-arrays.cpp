class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>map1;
        unordered_map<int,int>map2;
        for(int i=0;i<nums1.size();i++){
            map1[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            map2[nums2[i]]++;
        }
        vector<int>v;
        for(auto &x1: map1){
            if(map2.find(x1.first)!=map2.end()){
                v.push_back(x1.first);
            }
        }
        return v;
    }
};