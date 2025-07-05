class Solution {
public:
    int possibleStringCount(string word) {
        int n=word.size();
        if(n==1) return 1;
        int count=1;
        for(int i=1;i<n;i++){
            if(word[i]==word[i-1]) count++;
        }
        return count;
    }
};