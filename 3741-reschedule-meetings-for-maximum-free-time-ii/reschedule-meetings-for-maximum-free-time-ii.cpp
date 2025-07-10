class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int m=startTime.size();
        vector<int>freearray;
        freearray.push_back(startTime[0]);
        for(int i=1;i<m;i++){
            freearray.push_back(startTime[i]-endTime[i-1]);
        }
        freearray.push_back(eventTime-endTime[endTime.size()-1]);
        int n=freearray.size();
        vector<int>maxright(n);
        vector<int>maxleft(n);
        maxright[n-1]=0;
        int result=0;
        for(int i=n-2;i>=0;i--){
            maxright[i]=max(maxright[i+1],freearray[i+1]);
        }
        maxleft[0]=0;
        for(int i=1;i<n;i++){
            maxleft[i]=max(maxleft[i-1],freearray[i-1]);
        }
        for(int i=1;i<n;i++){
            int d=endTime[i-1]-startTime[i-1];
            if(d<=maxleft[i-1] || d<=maxright[i]){
                result=max(result,freearray[i-1]+freearray[i]+d);
            }
            result=max(result,freearray[i-1]+freearray[i]);
        }
        return result;
    }
};