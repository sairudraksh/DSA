class Solution {
public:
    int maxFreqSum(string s) {
        int n=s.length();
        unordered_map<int,int>map;
        int maxvowel=0;
        int consonentCount=0;

        for(int i=0;i<n;i++){
            map[s[i]]++;
            if(s[i]=='a' || s[i]=='e'||  s[i]=='i' || s[i]=='o' || s[i]=='u'){
                if(map[s[i]]>maxvowel) maxvowel=map[s[i]];
            }
            else{
                if(map[s[i]]>consonentCount) consonentCount=map[s[i]];
            }
        }
        return maxvowel+consonentCount;
    }
};