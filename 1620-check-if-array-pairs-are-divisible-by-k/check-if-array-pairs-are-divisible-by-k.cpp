class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> map;
        // Step 1: Count frequency of remainders using a full for loop
        for (int i = 0; i < arr.size(); i++) {
            int rem = ((arr[i] % k) + k) % k; // Handle negative numbers
            map[rem]++;
        }
        // Step 2: Check pairing conditions using range-based loop as you like
        for (auto x : map) {
            if(x.first == 0) {
                if(x.second%2!=0) return false;
            } 
            else if(2*x.first == k) {
                if(x.second%2!=0) return false;
            } 
            else {
                int complement = k - x.first;
                if (map.find(complement) == map.end()) return false;
                if (map[x.first] != map[complement]) return false;
            }

        }
        return true;
    }
};

