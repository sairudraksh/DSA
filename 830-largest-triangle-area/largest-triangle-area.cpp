class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& nums) {
        int n=nums.size();
        double MaxArea=0;
        for(int i=0;i<n;i++){

            for(int j=i+1;j<n;j++){
                auto point1=nums[i];
                auto point2=nums[j];

                double x1=point1[0];
                double y1=point1[1];

                double x2=point2[0];
                double y2=point2[1];

                double distance1 = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));


                for(int k=j+1;k<n;k++){
                    auto point3=nums[k];

                    double x3=point3[0];
                    double y3=point3[1];

                    double distance2 = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
                    double distance3 = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));

                    if(distance1+distance2>distance3 && distance2+distance3>distance1 && distance1+distance3>distance2){
                        double s = (distance1 + distance2 +distance3) / 2;
                        double Area = sqrt(s * (s - distance1) * (s - distance2) * (s - distance3));
                        MaxArea=max(MaxArea,Area);
                    }
                }
            }
        }
        return MaxArea;
    }
};