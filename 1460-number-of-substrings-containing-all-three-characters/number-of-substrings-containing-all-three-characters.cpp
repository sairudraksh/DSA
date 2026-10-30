class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();

        unordered_map<char,int>map;
        int i=0;
        int j=0;
        int count=0;
        while(j<n){
            map[s[j]]++;
            while(map.size()==3){
                count+=(n-j);
                map[s[i]]--;
                if(map[s[i]]==0) map.erase(s[i]);
                i++;
            }
            j++;
        }
        j--;

        map[s[i]]--;
        if(map[s[i]]==0) map.erase(s[i]);
        i++;

        while(i<=j){
            if(map.size()==3){
                count++;
                map[s[i]]--;
                if(map[s[i]]==0) map.erase(s[i]);
                i++;
            }
            else break;
        }
        return count;
    }
};