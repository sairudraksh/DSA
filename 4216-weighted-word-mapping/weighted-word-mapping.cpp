class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        unordered_map<char,int>map1;
        int num=97;
        for(int i=0;i<weights.size();i++){
            char ch=char(num);
            map1[ch]=weights[i];
            num++;
        }

        unordered_map<int,char>map2;
        num=97;
        int a=26;
        for(int i=0;i<weights.size();i++){
            char ch=char(num);
            map2[a]=ch;
            num++;
            a--;
        }

        string s="";


        for(int i=0;i<words.size();i++){
            string str=words[i];

            int sum=0;
            for(int j=0;j<str.length();j++){
                sum+=map1[str[j]];
            }
            sum=sum%26;
            s+=map2[sum+1];
        }
        return s;
    }
};