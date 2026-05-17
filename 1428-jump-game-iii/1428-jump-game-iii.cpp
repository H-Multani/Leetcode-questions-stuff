class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        // visited wala bakchodi hora, DFS becomes too complicated, simple rakho
        // BFS se

        // visited array maintain karke DFS chal sakte toh DP bhu use kar sakte
        

        int n = arr.size();

        // q lelo used for BFS traversal
        queue<int> q;

        // visited array lelo so that baar baar same jagah na aana pade
        vector<bool> vis(n, false);

        // first element q me daal do

        q.push(start);
        // visited mark kardo isko
        vis[start] = true;

        // me chal lo

        while (!q.empty()) {
            // current element
            int i = q.front();
            q.pop();

            // agar current element 0 hai toh return true
            if (arr[i] == 0)
                return true;

            // iss idx se kaha kaha jaa sakte pehle ye btao, we can go to
            // i+arr[i] ya i-arr[i], dekh lo dono

            if (i - arr[i] >= 0 && !vis[i - arr[i]]) {
                // agar valid and unvisited hai toh visited mark karke q me daal
                // do for fuurther exploration
                vis[i - arr[i]] = true;
                q.push(i - arr[i]);
            }

            if (i + arr[i] < n && !vis[i + arr[i]]) {
                // agar valid and unvisited hai toh visited mark karke q me daal
                // do for fuurther exploration
                vis[i + arr[i]] = true;
                q.push(i + arr[i]);
            }
        }

        // we here means kuch nai mila in such case return false;
        return false;
    }
};