class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int>q;
        int n=status.size();
        unordered_map<int,int>boxesfound;
        unordered_map<int,int>keysEarlier;
    
        vector<int>visited;
        visited.resize(n+1,0);
        for(int i=0;i<initialBoxes.size();i++){
            if(status[initialBoxes[i]]==1){
                q.push(initialBoxes[i]);
                visited[initialBoxes[i]]=1;
            }
            else boxesfound[initialBoxes[i]]++;
        }
        int ans=0;

        while(q.size()>0){
            int box=q.front();

            q.pop();

            ans+=candies[box];

            vector<int>boxes=containedBoxes[box];

            vector<int>keysfound=keys[box];

            for(int i=0;i<keysfound.size();i++){
                int newkey=keysfound[i];
                if(boxesfound.find(newkey)!=boxesfound.end()){
                    boxesfound.erase(newkey);
                    q.push(newkey);
                    visited[newkey]++;
                }
                else keysEarlier[keysfound[i]]++;
            }

            for(int i=0;i<boxes.size();i++){
                int currbox=boxes[i];

                if(visited[currbox]==0){
                    if(status[currbox]==1 || keysEarlier.find(currbox)!=keysEarlier.end()){
                        q.push(currbox);
                        visited[currbox]=1;
                    }
                    else boxesfound[currbox]++;
                }
            }
        }
        return ans;
    }
};