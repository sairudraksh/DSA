class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int n=chars.length();
        vector<int>freq1(26,0);
        for(int i=0;i<chars.length();i++){
            freq1[chars[i]-'a']++;
        }
        int count=0;
        for(int i=0;i<words.size();i++){
            string s=words[i];
            vector<int>freq2(26,0);
            for(int k=0;k<s.length();k++){
                freq2[s[k]-'a']++;
            }
            bool isTrue=true;
            for(int l=0;l<26;l++){
                if(freq2[l]==0 || freq1[l]==freq2[l] || freq1[l]>=freq2[l]) continue;
                else{
                    isTrue=false;
                    break;
                }
            }
            if(isTrue){
                count+=s.length();
            }
        }
        return count;
    }
};