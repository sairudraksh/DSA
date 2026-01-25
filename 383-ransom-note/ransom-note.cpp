class Solution {
public:
    bool canConstruct(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        unordered_map<char,int>map;
        for(int i=0;i<m;i++){
            map[s2[i]]++;
        }
        for(int i=0;i<n;i++){
            if(map.find(s1[i])!=map.end()){
                map[s1[i]]--;
                if(map[s1[i]]==0) map.erase(s1[i]);
            }
            else return false;
        }
        return true;
    }
};