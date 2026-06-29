class Solution {
public:
    bool find(string &word,string &s,int idx1,int idx2){
        int n=word.length();
        int m=s.length();
        while(idx1<n && idx2<m){
            if(word[idx1]!=s[idx2]) break;
            idx1++;
            idx2++;
        }
        return idx2==m;
    }
    int numOfStrings(vector<string>& patterns, string word) {
        int count=0;
        for(int i=0;i<patterns.size();i++){
            string s=patterns[i];
            for(int j=0;j<word.size();j++){
                if(word[j]==s[0]){
                    bool check=find(word,s,j,0);
                    if(check){
                        count++;
                        break;
                    }
                }
            }
        }
        return count;
    }
};