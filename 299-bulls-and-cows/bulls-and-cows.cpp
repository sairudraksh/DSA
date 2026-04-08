class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int>map1;
        unordered_map<char,int>map2;

        int bulls=0;



        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                bulls++;
            }
            else{
                map1[secret[i]]++;
                map2[guess[i]]++;
            }
        }

        int cows=0;

        for(int i=0;i<secret.size();i++){
            char ch=secret[i];

            if(secret[i]==guess[i]) continue;
            else{
                if(map2.find(ch)!=map2.end()){
                    map2[ch]--;
                    if(map2[ch]==0) map2.erase(ch);
                    cows++;
                }
            }
        }

        string s="";

        string s1=to_string(bulls);
        string s2=to_string(cows);

        s+=s1;
        s+="A";
        s+=s2;
        s+="B";
        return s;
    }
};