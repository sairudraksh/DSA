class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>v=nums;
        int l=k;
        for(int i=0;i<n-1;i++){
            if(nums[i]<0){
                nums[i]=nums[i]*-1;
                nums[i+1]=nums[i+1]*-1;
                l--;
            }
            if(l<=0) break;
        }
        for(int i=0;i<n-1;i++){
            if(v[i]>0){
                v[i]=v[i]*-1;
                v[i+1]=v[i+1]*-1;
                k--;
            }
            if(k<=0) break;
        }
        bool found1=false;
        bool found2=false;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]!=nums[i+1]){
                found1=true;
                break;
            }
        }
        for(int i=0;i<v.size()-1;i++){
            if(v[i]!=v[i+1]){
                found2=true;
                break;
            }
        }
        if(found1==false || found2==false) return true;
        return false;
    }
};