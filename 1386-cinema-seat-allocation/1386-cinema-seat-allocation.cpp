class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        // Store reserved seats for each row
        unordered_map<int, int> mp;

        // Only seats 2 to 9 matter
        // We represent them using bits
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            if (col >= 2 && col <= 9) {
                mp[row] |= (1 << col);
            }
        }

        int ans = (n - mp.size()) * 2;

        for (auto &[row, mask] : mp) {

            bool left = true;    // seats 2,3,4,5
            bool middle = true;  // seats 4,5,6,7
            bool right = true;   // seats 6,7,8,9

            // Check left block
            for (int seat = 2; seat <= 5; seat++) {
                if (mask & (1 << seat)) {
                    left = false;
                    break;
                }
            }

            // Check middle block
            for (int seat = 4; seat <= 7; seat++) {
                if (mask & (1 << seat)) {
                    middle = false;
                    break;
                }
            }

            // Check right block
            for (int seat = 6; seat <= 9; seat++) {
                if (mask & (1 << seat)) {
                    right = false;
                    break;
                }
            }

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};