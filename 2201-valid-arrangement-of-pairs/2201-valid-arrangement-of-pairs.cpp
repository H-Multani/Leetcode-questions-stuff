class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        // adj list banao
        unordered_map<int, vector<int>> adj;
        // indegree and ourdegree ka bhi count banao
        unordered_map<int, int> indegree, outdegree;
        // key is node, and value is the indegree/outdegree
        for (auto it : pairs) {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
            outdegree[it[0]]++;
        }

        // find startnode of euler path
        int startnode=pairs[0][0];
        // initially koi bhi value dedo

        for (auto it : adj) {
            int node = it.first;
            if (outdegree[node] - indegree[node] == 1) {
                startnode = node;
            }
        }

        // simply DFS chala do

        // stack se DFS chala rahe hai bcoz mik ne usse karvaya hai
        vector<int> eulerpath;
        // to store euler path
        stack<int> st;
        // to perform DFS

        // starting node push kardo
        st.push(startnode);

        while (!st.empty()) {
            // current node is
            int curr = st.top();

            // agar iss node ke abhi bhi neighbours hai
            if (!adj[curr].empty()) {
                // means neighbours hai iss node ke abhi
                // back se neighbour nikalo
                int neibr = adj[curr].back();
                // yaha pop nai karenge since ho sakta hai iss node ke aage aur
                // path present ho

                // neighbor nikalne ke baad pop kardo, basically uss edge ko
                // remove kardo, so that uss edge par vapas naa jaaye
                adj[curr].pop_back();
                // current neighbr ko puch kardo stack me ab, adding to path
                st.push(neibr);
            } else {
                // means current node ka koi neighbour nai bacha hai abhi
                // ie its ready to go to the path vector
                // push kardo path vector me
                eulerpath.push_back(curr);

                // ab ye node path me add ho chuka hai, iska aur koi kaam nai
                // bacha hai abhi,pop frm stack
                st.pop();
            }
        }

        // ab apne paas eulerpath vector me apna reqd path aa chuka hai, but
        // opposite direction me aaya hai path since stack se hamesha ulta aata
        // hai elements vapas

        // hence we first need to reverse the eulerpath to get correct path
        reverse(eulerpath.begin(), eulerpath.end());

        // ab path aa chuka hai, bas seedhe 2-2 element leke ans vector banao
        // and return kardo
        vector<vector<int>> ans;
        for(auto i=0;i<eulerpath.size()-1;i++){
            ans.push_back({eulerpath[i],eulerpath[i+1]});
        }

        return ans;
    }
};