class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> st;

    int curr = 1;

    SmallestInfiniteSet() {}

    int popSmallest() {
        if (!pq.empty()) {
            int x = pq.top();
            pq.pop();
            st.erase(x);
            return x;
        }

        return curr++;
    }

    void addBack(int x) {
        // Only add numbers that have already been popped
        if (x < curr && st.find(x) == st.end()) {
            pq.push(x);
            st.insert(x);
        }
    }
};