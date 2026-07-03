class Solution {
public:
    bool istrue(vector<int>&freq1,vector<int>&freq2){
        for(int i=0;i<26;i++){
            if(freq1[i]>freq2[i]) return false;
        }
        return true;
    }
    long long validSubstringCount(string word1, string word2) {
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        for(int i=0;i<word2.length();i++){
            freq1[word2[i]-'a']++;
        }
        int i=0;
        int j=0;
        int n=word1.length();
        long long count=0;
        while(j<n && i<n){
            freq2[word1[j]-'a']++;

            while(istrue(freq1,freq2)){
                count+=(n-j);
                freq2[word1[i]-'a']--;
                i++;
            }
            j++;
        }
        return count;
    }
};