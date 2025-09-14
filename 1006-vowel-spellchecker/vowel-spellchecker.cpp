class Solution {
public:
    unordered_set<string>exact;
    unordered_map<string,string>Lower;
    unordered_map<string,string>Vowel;
    string toLower(string s){
        string result=s;
        for(int i=0;i<s.length();i++){
            result[i]=tolower(result[i]);
        }
        return result;
    }
    string toVowel(string s){
        string result=s;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a' || s[i]=='e' ||  s[i]=='i' || s[i]=='o'|| s[i]=='u'){
                result[i]='*';
            }
        }
        return result;
    }
    string find(string s){
        if(exact.find(s)!=exact.end()){
            return s;
        }
        string lower=toLower(s);
        if(Lower.find(lower)!=Lower.end()){
            return Lower[lower];
        }

        string vowel=toVowel(lower);
        if(Vowel.find(vowel)!=Vowel.end()){
            return Vowel[vowel];
        }
        return "";
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        exact.clear();
        Lower.clear();
        Vowel.clear();

        for(auto word:wordlist){

            exact.insert(word);

            string lower=toLower(word);

            if(Lower.find(lower)==Lower.end()){
                Lower[lower]=word;
            }

            string vowel=toVowel(lower);
            if(Vowel.find(vowel)==Vowel.end()){
                Vowel[vowel]=word;
            }
        }
        vector<string>ans;
        for(auto query:queries){
            string answord=find(query);
            ans.push_back(answord);
        }
        return ans;
    }
};