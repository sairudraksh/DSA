class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;

        unordered_map<int,int>map;

        int sum=0;

        int minimum=INT_MAX;

        while(j<n){
            map[nums[j]]++;

            if(map[nums[j]]==1) sum+=nums[j];


            while(sum>=k){
                minimum=min(minimum,j-i+1);
                map[nums[i]]--;
                if(map[nums[i]]==0) sum-=nums[i];
                i++;
            }
            j++;
        }
        if(minimum==INT_MAX) return -1;
        return minimum;

    }
};