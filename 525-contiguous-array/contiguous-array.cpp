class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();

        int currSum=0;
        unordered_map<int,int>map;
        map[0]=-1;
        int maximum=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1) currSum++;
            else currSum--;
            
            if(map.find(currSum)!=map.end()){
                int diff=(i-map[currSum])+1;

                maximum=max(maximum,diff);
            }

            else map[currSum]=i;
        }
        if(maximum==0) return 0;
        return maximum-1;
    }
};