class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s2.length();
        unordered_map<char,int>map1;
        unordered_map<char,int>map2;

        for(int i=0;i<s1.length();i++){
            map1[s1[i]]++;
            
        }

        int i=0;
        int j=0;

        while(j<n){
            map2[s2[j]]++;
            if(map1==map2) return true;
            if((j-i)+1==s1.length()){
                map2[s2[i]]--;
                if(map2[s2[i]]==0) map2.erase(s2[i]);
                i++;
            }
            j++;
        }
        return false;
    }
};