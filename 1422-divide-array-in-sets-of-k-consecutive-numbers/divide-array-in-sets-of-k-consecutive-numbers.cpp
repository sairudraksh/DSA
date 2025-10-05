class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>map;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }

        for(int i=0;i<n;i++){
            if(map.find(nums[i])!=map.end()){
                map[nums[i]]--;
                int x=nums[i]+1;
                if(map[nums[i]]==0) map.erase(nums[i]);

                for(int j=0;j<k-1;j++){
                    if(map.find(x)==map.end()) return false;
                    map[x]--;
                    if(map[x]==0) map.erase(x);
                    x++;
                }
            }
        }
        return true;
    }
};