class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int m=startTime.size();
        vector<int>freearray;

        freearray.push_back(startTime[0]);
        for(int i=1;i<m;i++){
            freearray.push_back(startTime[i]-endTime[i-1]);
        }
        freearray.push_back(eventTime-endTime[m-1]);

        int n=freearray.size();
        vector<int>maxright(n,0);
        vector<int>maxleft(n,0);

        
        maxleft[0]=0;
        for(int i=1;i<n;i++){
            maxleft[i]=max(maxleft[i-1],freearray[i-1]);
        }

        maxright[n-1]=0;
        for(int i=n-2;i>=0;i--){
            maxright[i]=max(maxright[i+1],freearray[i+1]);
        }
        int result=INT_MIN;
        for(int i=1;i<n;i++){
            int d=endTime[i-1]-startTime[i-1];
            if(d<=maxright[i]  || d<=maxleft[i-1]){
                result=max(result,freearray[i]+freearray[i-1]+d);
            }
            else{
                result=max(result,freearray[i]+freearray[i-1]);
            }
        }
        return result;
    }
};