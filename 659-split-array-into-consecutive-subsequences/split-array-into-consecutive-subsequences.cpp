class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>map;

        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }

        for(int i=0;i<n;i++){
            int maxfreq=map[nums[i]];
            int count=0;
            if(map[nums[i]]==0) continue;
            int curr=nums[i];
            while(map.count(curr) && maxfreq<=map[curr]){//  for example this is array [1,2,3,3,4,5] so at 4 loop breaks as freq of prev(3) is is greater which is not possiible as 2 three's means there should be matching 4's so its direcly false but only way possible iit can be true by ending subsequence at 3 only and start new from 3  thats why we use this check  currfreq<=map[curr]
                maxfreq=max(maxfreq,map[curr]);
                map[curr]--;
                curr++;
                count++;
            }
            if(count<3) return false;
        }
        return true;
    }
};