class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int>map;
        for(int i=0;i<s.length();i++){
            map[s[i]]++;
        }
        int count=0;
        while(!map.empty()){
            for(int i=0;i<target.length();i++){
                int flagg=0;
                for(auto x:map){
                    if(x.first==target[i]){
                        flagg=1;
                        break;
                    }
                }
                if(flagg==1) map[target[i]]--;
                if(map[target[i]]==0) map.erase(target[i]);
                if(flagg==0) return count;
            }
            count++;
        }
        return count;
    }
};