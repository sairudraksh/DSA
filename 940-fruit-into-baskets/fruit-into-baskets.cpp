class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>map;

        int i=0;
        int j=0;
        int maxlen=0;
        while(j<n){
            map[nums[j]]++;

            while(map.size()>2){
                map[nums[i]]--;
                if(map[nums[i]]==0) map.erase(nums[i]);
                i++;
            }
            if(map.size()<=2) maxlen=max(maxlen,j-i+1);
            j++;
        }
        j--;
        while(i<n){
            if(map.size()<=2) maxlen=max(maxlen,j-i+1);
            map[nums[i]]--;
            if(map[nums[i]]==0) map.erase(nums[i]);
            i++;
        }
        return maxlen;
    }
};