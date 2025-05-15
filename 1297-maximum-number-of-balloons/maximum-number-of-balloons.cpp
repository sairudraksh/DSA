class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>map;
        for(int i=0;i<text.length();i++){
            map[text[i]]++;//o(n)
        }
        int count=0;
        while(!map.empty()){//o(n) worst case
            string s="balloon";
            for(int i=0;i<s.length();i++){//n/7 worst case that every element forms ballon
                int flagg=0;
                for(auto x:map){
                    if(x.first==s[i]){
                        flagg=1;
                        break;
                    }
                }
                if(flagg==1) map[s[i]]--;
                if(map[s[i]]==0) map.erase(s[i]);
                if(flagg==0) return count;
            }
            count++;
        }
        return count;
    }
};