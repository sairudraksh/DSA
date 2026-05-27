class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int>map;

        for(int i=0;i<word.size();i++){
            if(int(word[i])>=65 && int(word[i])<=92){
                if(map.find(word[i])==map.end()) map[word[i]]=i;
            }
            else map[word[i]]=i;
        }
        int count=0;
        for(auto x:map){
            int num=int(x.first);
            if(num>=97 && num<=123){
                int target=num-32;
                char ch=char(target);
                if(map.find(ch)!=map.end() && map[ch]>map[x.first]) count++;
            }
        }
        return count;
    }
};