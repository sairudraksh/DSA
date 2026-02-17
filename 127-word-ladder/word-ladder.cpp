class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList){
        queue<pair<string,int>>q;

        set<string>st(wordList.begin(),wordList.end());

        q.push({beginWord,1});
    
        while(q.size()>0){
            auto p=q.front();
            q.pop();
            string word=p.first;
            int x=p.second;

            if(word==endWord){
                return x;
            }

            for(int i=0;i<word.length();i++){
                char ch=word[i];
                for(char j='a';j<='z';j++){
                    word[i]=j;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,x+1});
                    }
                }
                word[i]=ch;
            }
        }
        return 0;
    }
};