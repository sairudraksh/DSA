class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<int,int>map;
        int count=0;
        for(int i=0;i<jewels.length();i++){
            map[jewels[i]]++;
        }
        for(int i=0;i<stones.length();i++){
            if(map.find(stones[i])!=map.end()) count++;
        }
        return count;
    }
};