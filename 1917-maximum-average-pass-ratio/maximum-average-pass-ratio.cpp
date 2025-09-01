class Solution {
public:
    #define P pair<double,int>
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();
        priority_queue<P>pq;
        for(int i=0;i<n;i++){
            double a=double(classes[i][0])/(classes[i][1]);
            double b=double(classes[i][0]+1)/(classes[i][1]+1);
            double delta=b-a;
            pq.push({delta,i});
        }

        while(extraStudents--){
            auto a=pq.top();
            pq.pop();

            double ans=a.first;
            double idx=a.second;

            classes[idx][0]++;
            classes[idx][1]++;

            double l=double(classes[idx][0])/(classes[idx][1]);
            double m=double(classes[idx][0]+1)/(classes[idx][1]+1);
            double delta=m-l;
            pq.push({delta,idx});
        }

        double result=0.0;

        for(int i=0;i<n;i++){
            result+=double(classes[i][0])/(classes[i][1]);
        }
        return result/n;
    }
};