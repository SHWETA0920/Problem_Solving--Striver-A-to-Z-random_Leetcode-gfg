class Solution {
public:
    int largestRectangleArea(vector<int>& he) {
        int n=he.size();
        vector<int>nse(n);
        vector<int>pse(n);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && he[st.top()] >= he[i]) st.pop();

            pse[i]=st.empty()?-1:st.top();

            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && he[st.top()] > he[i]) st.pop();
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }

        int maxi=0;
        int a=0;

        for(int i=0;i<n;i++){
            int width=nse[i]-pse[i]-1;
            int area=he[i]*width;
            maxi=max(maxi,area);
        }

        return maxi;
    }
};