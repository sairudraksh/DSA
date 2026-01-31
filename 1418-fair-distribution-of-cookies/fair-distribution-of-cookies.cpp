class Solution {
public:
    int find(vector<int>&nums,vector<int>&v,int i){
        if(i>=nums.size()){
            int maximum=0;
            for(int i=0;i<v.size();i++){
                if(v[i]==0) return INT_MAX;
                maximum=max(maximum,v[i]);
            }
            return maximum;
        }

        int minimum=INT_MAX;
        for(int j=0;j<v.size();j++){
            v[j]+=nums[i];
            minimum=min(minimum,find(nums,v,i+1));
            v[j]-=nums[i];
        }
        return minimum;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>v(k,0);
        return find(cookies,v,0);
    }
};