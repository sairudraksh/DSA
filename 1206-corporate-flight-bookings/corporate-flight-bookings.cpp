class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>v1(n,0);

        for(int p=0;p<bookings.size();p++){
            auto v=bookings[p];

            int i=v[0]-1;
            int j=v[1]-1;
            int k=v[2];

            for(int l=i;l<=j;l++){
                v1[l]+=k;
            }
        }
        return v1;
    }
};