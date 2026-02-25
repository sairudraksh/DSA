class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v=nums1;

        for(int i=0;i<nums2.size();i++){
            v.push_back(nums2[i]);
        }

        sort(v.begin(),v.end());

        if(v.size()%2!=0){
            double a=v[v.size()/2];
            return a;

        }
        else{
            double a=v[v.size()/2];
            double b=v[(v.size()/2)-1];
            double x=(a+b)/2;
            return x;
        }
        return 0;
    }
};