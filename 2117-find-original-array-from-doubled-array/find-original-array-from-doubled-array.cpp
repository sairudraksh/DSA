class Solution {
public:
    vector<int> findOriginalArray(vector<int>& nums) {
        int n=nums.size();
        if(n%2!=0) return {};
        sort(nums.begin(),nums.end());
        unordered_map<int,int>map;
        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(map[nums[i]]>0){
                int num=nums[i]*2;
                if(num==0  && map[num]<2) continue;
                if(map[num]>0){
                    ans.push_back(nums[i]);
                    map[nums[i]]--;
                    map[num]--;
                }
            }
        }
        if(n%2==0 && ans.size()<nums.size()/2) return {};
        return ans;
    }
};