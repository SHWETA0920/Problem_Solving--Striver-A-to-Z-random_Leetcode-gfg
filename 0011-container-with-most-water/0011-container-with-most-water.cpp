class Solution {
public:
    int maxArea(vector<int>& he) {
        int left = 0;
        int right = he.size() - 1;
        int max_water = 0;
        
        while (left < right) {
            int width = right - left;
            
            // The height of the water is limited by the shorter line
            int current_height = min(he[left], he[right]);
            
            // Calculate the area and update the maximum
            int current_water = width * current_height;
            max_water = max(max_water, current_water);
            
            
            if (he[left] < he[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_water;
    }
};
