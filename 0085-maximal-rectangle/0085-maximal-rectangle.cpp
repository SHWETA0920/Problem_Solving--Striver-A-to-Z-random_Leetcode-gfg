class Solution {
public:
    vector<int> nsr(vector<int>& height) {
        stack<int> st;
        int n = height.size();
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && height[st.top()] >= height[i])
                st.pop();
            ans[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> nsl(vector<int>& height) {
        stack<int> st;
        int n = height.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[st.top()] > height[i])
                st.pop();
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
    int findMaxArea(vector<int>& height) {
        vector<int> NSR = nsr(height);
        vector<int> NSL = nsl(height);
        int n = height.size();
        vector<int> width(n);
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            width[i] = NSR[i] - NSL[i] - 1;
            int a = width[i] * height[i];
            maxArea = max(maxArea, a);
        }       
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> height(n);
        for (int i = 0; i < n; i++) {
            height[i] = (matrix[0][i] == '1') ? 1 : 0;
        }
        int maxArea = findMaxArea(height);

        for (int row = 1; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (matrix[row][col] == '0') {
                    height[col] = 0;
                } else {
                    height[col] += 1;
                }
            }
            maxArea = max(maxArea, findMaxArea(height));
        }

        return maxArea;
    }
};