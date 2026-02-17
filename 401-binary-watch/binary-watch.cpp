class Solution {
public:
    vector<int>visited1;
    vector<int>visited2;
    vector<string>ans;
    set<string>st;
    void makeString(int hour,int minutes){
        string str1=to_string(hour);
        string str2=to_string(minutes);
        if(str2.length()==1){
            str2='0'+str2;
        }
        string ans1=str1+':'+str2;
        if(st.find(ans1)==st.end()){
            ans.push_back(ans1);
            st.insert(ans1);
        }
    }
    void find(int &hour,int &minutes,int &turnedOn){
        if(turnedOn==0){
            makeString(hour,minutes);
            return;
        }  
        for(int i=1;i<=8;i=i*2){
            if(visited1[i]==0 && hour+i<12){
                visited1[i]=1;
                turnedOn--;
                hour+=i;
                find(hour,minutes,turnedOn);
                hour-=i;
                turnedOn++;
                visited1[i]=0;
            }
        }

        for(int i=1;i<=32;i=i*2){
            if(visited2[i]==0 && minutes+i<60){
                visited2[i]=1;
                turnedOn--;
                minutes+=i;
                find(hour,minutes,turnedOn);
                minutes-=i;
                turnedOn++;
                visited2[i]=0;
            }
        }
    }
    vector<string> readBinaryWatch(int turnedOn) {
        visited1.resize(33,0);
        visited2.resize(33,0);
        int hour=0;
        int minutes=0;
        find(hour,minutes,turnedOn);
        return ans;
    }
};