class Solution {
public:
    vector<int> NSE(vector<int>& ht) {
        stack<int> st;
        int n = ht.size();

        vector<int> nse(n);

        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                // means stack empty means right me koi smaller nai hai, last
                // element dedo
                nse[i] = n;
            } else {
                // means stack not empty
                // jab tak smaller na mile nikalte jao elements
                while (!st.empty() && ht[st.top()] >= ht[i]) {
                    st.pop();
                }

                // agar stack khali ho jaaye means iss element ke right me koi
                // smaller nai hai in such case give last index

                if (st.empty()) {
                    nse[i] = n;
                } else {
                    // we here means top idx wala element is smaller, nse me
                    // daal do
                    nse[i] = st.top();
                }
            }

            // current element ko stack me daal do
            st.push(i);
        }

        return nse;
    }
    vector<int> PSE(vector<int>& ht) {
                stack<int> st;
        int n = ht.size();

        vector<int> pse(n);

        for (int i = 0; i <n; i++) {
            if (st.empty()) {
                // means stack empty means right me koi smaller nai hai, last
                // element dedo
                pse[i] = -1;
            } else {
                // means stack not empty
                // jab tak smaller na mile nikalte jao elements
                while (!st.empty() && ht[st.top()] >= ht[i]) {
                    st.pop();
                }

                // agar stack khali ho jaaye means iss element ke right me koi
                // smaller nai hai in such case give last index

                if (st.empty()) {
                    pse[i] = -1;
                } else {
                    // we here means top idx wala element is smaller, nse me
                    // daal do
                    pse[i] = st.top();
                }
            }

            // current element ko stack me daal do
            st.push(i);
        }

        return pse;
    }
    int solve(vector<int>& ht) {
        // area ka liye width and height chahiye
        // height toh diya hua hai ht[i], bass width nikal lo

        // width ke liye we do NSE and PSE, since we need indexes of next
        // smaller element and previous smaller element
        vector<int> nse = NSE(ht);
        vector<int> pse = PSE(ht);

        int n=ht.size();

        // ab bass width nikal lo
        vector<int> width(n);

        // yaha par vahi largest histogram area wala logic lagega

        for(int i=0;i<n;i++){
            width[i]=nse[i]-pse[i]-1;
        }

        // ab widths nikal li hai, ab height diya hai ht[i] me, toh area nikal lo max
        int ans=0;

        for(int i=0;i<n;i++){
            // area will be width[i]*ht[i];

            ans=max(ans,width[i]*ht[i]);
        }

        return ans;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // 2d array ko 1d banane ka try karenge apan
        vector<int> height(n);

        // add the first row in the height
        for (int i = 0; i < n; i++) {
            // first row ko as it is height me daal do
            height[i] = (mat[0][i] == '1') ? (1) : 0;
        }

        // initial ans lelo fir baaki rows me add karte chalna
        // initial ans ke liye first row ka ans nikal lo
        int ans = solve(height);

        // baaki 2 nd row onwards chalu kardo
        for (int row = 1; row < m; row++) {
            // new wali row par chal kar height array banao
            for (int col = 0; col < n; col++) {
                if (mat[row][col] == '0') {
                    height[col] = 0;
                } else {
                    // means 1 hai, in such case height[row][col] par jo bhi
                    // value hai +1 kardo
                    height[col]++;
                }
            }

            // new wala heights area ban chuka hai, basically histogram ban
            // chuka hai ab isme biggest rectangle ka area nikal lo
            ans = max(ans, solve(height));
        }

        return ans;
    }
};