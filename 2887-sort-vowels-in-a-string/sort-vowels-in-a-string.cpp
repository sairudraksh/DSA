class Solution {
public:
    string sortVowels(string s) {
        priority_queue<char, vector<char>, greater<char>> pq;
        for(int i=0;i<s.length();i++){
            if(s[i]=='A' || s[i]=='E' ||s[i]=='I' ||s[i]=='O' ||s[i]=='U' ||s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u') pq.push(s[i]);
        }

        for(int i=0;i<s.length();i++){
            if(s[i]=='A' || s[i]=='E' ||s[i]=='I' ||s[i]=='O' ||s[i]=='U' ||s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u'){
                char ch=pq.top();
                s[i]=ch;
                pq.pop();
            }
        }

        return s;

    }
};