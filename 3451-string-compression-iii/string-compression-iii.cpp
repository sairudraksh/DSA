class Solution {
public:
    string compressedString(string word) {
        int i=0;
        int j=1;
        int n=word.length();
        int count=1;
        string s="";
        while(j<n){
            if(word[i]!=word[j] || count==9){
                char c='0'+count;
                s+=c;
                s+=word[i];
                count=1;
                i=j;
                j++;
            }
            else{
                count++;
                j++;
            }
        }
        char c='0'+count;
        s+=c;
        s+=word[i];
        
        return s;
    }
};    