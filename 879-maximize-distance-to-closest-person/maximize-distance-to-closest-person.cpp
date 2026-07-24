class Solution {
public:
    int maxDistToClosest(vector<int>& nums) {
        vector<int>v;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) v.push_back(i);
        }
        int i=0;
        int j=1;
        int ans=0;
        int n=nums.size();
        while(j<v.size()){
            int lo=v[i];
            int hi=v[j];
            int mid=lo+(hi-lo)/2;

            if(nums[mid]==0){
                ans=max(ans,min(mid-lo,hi-mid));
            }
            j++;
            i++;
        }
        if(nums[0]==0) ans=max(ans,v[0]-0);
        if(nums[nums.size()-1]==0) ans=max(ans,(n-1)-v[v.size()-1]);

        return ans;
    }
};