class Solution {
public:
    int find(unordered_map<string,int>&map,string target){
        vector<int>visited(10000,0);
        visited[0]++;
        if(target=="0000")  return 0;
        queue<string>q;
        q.push("0000");
        
        int count=0;
        while(q.size()>0){
            int size=q.size();
            for(int l=0;l<size;l++){
                string s=q.front();
                q.pop();
                if(s==target) return count;

                for(int i=0;i<s.length();i++){
                    int num=s[i]-'0';
                    char ch=s[i];
                    char ch1;

                    if(num+1>9) ch1='0';
                    else ch1=(num+1)+'0';

                    s[i]=ch1;

                    if(s==target) return count+1;
                    int num1=stoi(s);
                    if(visited[num1]==0 && map.find(s)==map.end()){
                        q.push(s);
                        visited[num1]++;
                    }

                    s[i]=ch;


                    if(num-1<0) ch1='9';
                    else ch1=(num-1)+'0';

                    s[i]=ch1;

                    if(s==target) return count+1;
                    num1=stoi(s);
                    if(visited[num1]==0 && map.find(s)==map.end()){
                        q.push(s);
                        visited[num1]++;
                    }

                    s[i]=ch;
                }
            }

            count++;

        }
        return -1;
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string,int>map;
        for(int i=0;i<deadends.size();i++){
            map[deadends[i]]++;
            if(deadends[i]=="0000") return -1;
        }

        return find(map,target);
    }
};