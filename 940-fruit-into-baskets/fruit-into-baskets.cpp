class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n=nums.size();

        int i=0;
        int j=0;

        unordered_map<int,int>map;
        int maximum=0;
        while(j<n){
            map[nums[j]]++;

            while(map.size()>2){
                map[nums[i]]--;
                if(map[nums[i]]==0) map.erase(nums[i]);
                i++;
            }

            maximum=max(maximum,(j-i)+1);
            j++;
        }
        return maximum;
    }
};