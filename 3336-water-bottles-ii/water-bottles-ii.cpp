class Solution {
public:
    int maxBottlesDrunk(int nums, int x) {
        unordered_map<int,int>mp;
        int count=0;
        for(int i=0;i<nums;i++){
            mp[1]++;
            count++;
        }


        while(mp[1]>=x){
            mp[1]-=x;
            count+=1;
            mp[1]++;
            x++;
        }
        return count;
    }
};