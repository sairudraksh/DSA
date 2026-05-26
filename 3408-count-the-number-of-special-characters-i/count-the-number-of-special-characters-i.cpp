class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<int,int>map;

        for(int i=0;i<word.size();i++){
            map[word[i]]++;
        }
        int count=0;
        for(auto x:map){
            int num=x.first;
            if(num>=97 && num<=123){
                int target=num-32;
                char ch=char(target);
                if(map.find(ch)!=map.end()) count++;
            }
        }

        return count;
    }
};