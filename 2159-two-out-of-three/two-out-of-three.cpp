class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int,int>map1;
        unordered_map<int,int>map2;
        unordered_map<int,int>map3;

        unordered_set<int>st;

        for(int i=0;i<nums1.size();i++){
            map1[nums1[i]]++;
            st.insert(nums1[i]);
        }

        for(int i=0;i<nums2.size();i++){
            map2[nums2[i]]++;
            st.insert(nums2[i]);
        }

        for(int i=0;i<nums3.size();i++){
            map3[nums3[i]]++;
            st.insert(nums3[i]);
        }

        vector<int>ans;

        for(auto &x:st){
            if((map1.find(x)!=map1.end() && map2.find(x)!=map2.end()) ||  (map2.find(x)!=map2.end() && map3.find(x)!=map3.end()) ||  (map1.find(x)!=map1.end() && map3.find(x)!=map3.end())){ 
                ans.push_back(x);
            }
        }
        return ans;
    }
};