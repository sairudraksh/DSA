class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string>v;
        string s=words[0];
        int n=s.length();
        vector<int>freq1(26,0);

        for(int i=0;i<s.length();i++){
            char ch=s[i];
            freq1[ch-'a']++;
        }

        for(int i=1;i<words.size();i++){
            string str=words[i];
            vector<int>freq2(26,0);
            for(int i=0;i<str.length();i++){
                freq2[str[i]-'a']++;
            }

            for(int i=0;i<26;i++){
                freq1[i]=min(freq1[i],freq2[i]);
            }
        }
        for(int i=0;i<26;i++){
            while(freq1[i]>0){
                v.push_back(string(1, char(i + 'a')));// this is coverting index to character and then to vector
                freq1[i]--;
            }
        }
        return v;
    }
};