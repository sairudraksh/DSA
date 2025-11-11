class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>map;
        int n=s.length();
        int j=0;
        int i=0;
        int count=0;
        while(j<n){
            map[s[j]]++;
            while(map.size()==3){
                count+=(s.length()-j);
                map[s[i]]--;
                if(map[s[i]]==0) map.erase(s[i]);
                i++;
            }
            j++;
            
        }
        return count;
    }
};