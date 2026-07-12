class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score=0;
        int count=0;

        for(int i=0;i<events.size();i++){
            if(events[i]=="0" || events[i]=="1" || events[i]=="2" || events[i]=="3" || events[i]=="4" || events[i]=="5" || events[i]=="6"){
                int num=stoi(events[i]);
                score+=num;
            }
            else if(events[i]=="W"){
                count+=1;
            }
            else score+=1;
            if(count==10) break;
        }
        return {score,count};
    }
};