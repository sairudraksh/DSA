class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        unordered_map<int,int>map;
        for(int i=0;i<n2;i++){
            map[nums2[i]]=i;
        }
        vector<int>ans;
        for(int i=0;i<n1;i++){
            int x=map[nums1[i]];
            bool found=false;
            for(int l=x+1;l<n2;l++){
                if(nums2[l]>nums1[i]){
                    found=true;
                    ans.push_back(nums2[l]);
                    break;
                }
            }
            if(!found)ans.push_back(-1);
        }
        return ans;
    }
};