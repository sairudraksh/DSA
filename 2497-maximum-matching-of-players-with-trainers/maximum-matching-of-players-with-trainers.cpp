class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int count=0;
        int k=0;
        for(int i=0;i<players.size();i++){
            for(int j=k;j<trainers.size();j++){
                if(players[i]<=trainers[j]){
                    count++;
                    k=j+1;
                    break;
                }
            }
        }
        return count;
    }
};