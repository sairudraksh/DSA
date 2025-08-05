class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>map;

        int len=0;

        int i=0;
        int j=0;

        while(j<n){
            map[nums[j]]++;

            while(map.size()>2){
                map[nums[i]]--;
                if(map[nums[i]]==0) map.erase(nums[i]);
                i++;
            }

            len=max(len,(j-i)+1);
            j++;
        }

        return len;
    }
};