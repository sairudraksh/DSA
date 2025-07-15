class Solution {
public:
    bool isValid(string word) {
        if(word.length()<3) return false;
        bool hasconsonent=false;
        bool hasvowel=false;

        for(char ch : word){
            if(isalpha(ch)){
                ch=tolower(ch);
                if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                    hasvowel=true;
                }
                else hasconsonent=true;
            }
            else if(!isdigit(ch)) return false;
        }
        return hasconsonent && hasvowel;
    }
};