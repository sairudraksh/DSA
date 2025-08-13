class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n=courses.size();
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        int days=0;
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            int duration=courses[i][0];
            int lastdate=courses[i][1];

            days+=duration;
            pq.push(duration);

            if(days>lastdate){
                days-=pq.top();// remove which was takingg the largest duration
                pq.pop();
            }
        }
        return pq.size();
    }
};