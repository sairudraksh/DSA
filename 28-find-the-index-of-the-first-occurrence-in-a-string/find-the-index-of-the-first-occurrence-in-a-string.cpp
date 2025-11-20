class Solution {
public:
    bool isTrue(string s1,string s2,int i){
        int m=s2.length();
        for(int j=0;j<m;j++){
            if(s1[i]!=s2[j]) return false;
            i++;
        }
        return true;
    }
    int strStr(string nums1, string nums2) {
        int n=nums1.length();
        int m=nums2.length();
        for(int i=0;i<n;i++){
            if(nums1[i]==nums2[0]){
                if(isTrue(nums1,nums2,i)){
                    return i;
                }
            }
        }
        return -1;
    }
};