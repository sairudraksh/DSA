class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char>set;

        for(int i=0;i<s.length();i++){
            set.insert(s[i]);
        }
        int total=0;
        for(auto &x:set){
            char ch=x;

            int firstoccur=-1;
            int lastoccur=-1;

            unordered_set<char>st;
            for(int i=0;i<s.length();i++){
                if(s[i]==ch){
                    if(firstoccur==-1){
                        firstoccur=i;
                    }
                    lastoccur=i;
                }
            }

            for(int k=firstoccur+1;k<lastoccur;k++){
                st.insert(s[k]);
            }
            total+=st.size();
        }
        return total;
    }
};