class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();

        // sort kardo events ko, since apan day par iterate karre hai order me,
        // toh current day par jitne events huye saare ek saath pata chal
        // jayenge
        sort(events.begin(), events.end());

        // starting day pehle bande ka starting hoga
        int day = events[0][0];

        int i = 0;
        // to iterate over pointers

        int ans = 0;

        priority_queue<int, vector<int>, greater<int>> pq;

        // loop chala do

        while (!pq.empty() || i < n) {

            // jitne elements current day par start aa jaaye pq me daaal do
            // endings
            while (i < n && events[i][0] == day) {
                // ye event current day par start hora h, ending daal do pq me
                pq.push(events[i][1]);
                i++;
            }

            // ab pq ensure karega ki jaldi khatam hone wala event top par
            // rahega

            // toh sabse jaldi khtm hone wala element nikal lo pq se and count
            // krlo usko agar pq khali nai h toh alag karna
            if (!pq.empty()) {
                pq.pop();

                // 1 event attended on this day
                ans++;
            }

            // iss din ka event attempt kar liya hai, agle din par jao
            day++;

            // skip those days whose endday<day
            // since vo days paar kar chuke hai ab, toh vo events nai jaa
            // payenge anyway, toh why keep in pq

            while(!pq.empty() && pq.top()<day){
                pq.pop();
            }
        }

        return ans;
    }
};