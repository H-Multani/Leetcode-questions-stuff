class Solution {
public:
    typedef pair<long long, long long> pii;
    int mostBooked(int n, vector<vector<int>>& m) {
        // har jagah long long use karo just to be safe

        // sort kardo meeting pehle toh
        sort(m.begin(), m.end());

        for (auto it : m) {
            cout << it[0] << " " << it[1] << endl;
        }

        // ab n size ka vector lelo, which will store how many meetings this
        // room has done
        vector<long long> room(n, 0);

        // ab pq lelo, which will store 2 things,{ending time, i}, ie i th room
        // ka meeting ka ending time kab hai, since we need earliest finishing
        // room first

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        // this will store ki earliest konsa room free hora hai, and agar common
        // free hore hai toh usme se smaller idx wala top par need

        // ab first saari meetings ko pq me dal do
        for (auto i = 0; i < n; i++) {
            pq.push({0, i});
        }

        // ab meetings par iterate karo and add kardo rooms me meeting ko
        for (auto curr : m) {
            // current meeting ka starting kya hai
            long long starting = curr[0];
            // current meeting ka ending kya hai
            long long ending = curr[1];
            // current meeting ka length kya hai
            long long len = curr[1] - curr[0];

            // ab current meeting start hone se pehle konse wale rooms free ho
            // jaenge pq se nikal kar daal do
            // since agar room 4 initially empty hai maan lo, lekin current
            // meeting ke chalu hone tak room 2 free jo jayega, toh apan room 2
            // me daal denge

            // toh vahi khali room update karra hu
            while (!pq.empty() && pq.top().first <= starting) {
                // we here means current wala room will be empty by the time
                // meeting starts, toh iss room me daal sakte hai, toh best case
                // yaha banega agar apan current room ka ending time==starting+1
                // kar de, isse ye hoga ki all available bande with smallest idx
                // will be at the top

                // basically current meet ke start hone se pehle jitne rooms
                // free ho jayenge vo pq ke top par rahenge, with smallest idx
                // room in top

                // toh current top wala banda nikalo and uske new ending time
                // ko=starting kar do with same idx
                auto temp = pq.top();
                pq.pop();

                // ab pq me firse push kardo with new time and same old idx
                pq.push({starting + 1, temp.second});

                // used starting+1, since =starting rakh lenge toh loop never
                // ends, infinite loop chal jayega, toh usse bachne ke liye
                // starting +1, so that current meet ke liye nearest availabe at
                // top,

                // and since meetings are sorted accd to starting time+ uique
                // starting time, so iske pehle start hone wali koi meeting nai
                // hai, ie current meeting ke baad jitni metings hai baad me hi
                // chalu hongi current meeting ke
            }

            // pq ke top wale bande ko nikalo pehle toh, since that will be
            // ending first
            pii finished = pq.top();
            pq.pop();

            // current room ka meeting kb khatam hoga
            long long finish = finished.first;

            // ab ye wala konsa room h idx nikalo
            long long idx = finished.second;

            // ab 2 case hai, ya delaty hoga ya seedha meeting hogi,
            if (finish < starting) {
                // means current room ka meeting khatam hote hi apan next
                // meeting laga denge yaha means no delay

                // ab iss room ka meeting will end at ending time, toh vahi daal
                // do pq me, but before that

                // current wale room me ek meeting hogi, meeting cnt+1
                room[idx]++;

                // current wale room me new wali ending daal do idx ke saath
                pq.push({ending, idx});
            } else {
                // we here means ki meeting will be delayed,

                // in such case jab free hoga room, tabhi new meet schedule kar
                // denge of same length

                // toh abhi wali meeting ends at finish(variable name), and new
                // meeting is delayed and of size len

                // toh current meeting will start at finish(variable name), and
                // go until finish+len

                // like if current room was getting vacant at time=10, and
                // meeting was frm (9,14), toh meeting delayed of size 14-9=5

                // new meeting will start frm 10 and go onn until 10+5=15 time

                // toh yehi final time(15) par mera current room free hoga, daal
                // do pq me

                // current room me 1 meeting hua, +1 kardo cnt
                room[idx]++;

                // current wale room ka new ending daal do pq me
                pq.push({finish + len, idx});
            }
        }

        // ab iterate karke dhundo ki maxm konse room me meeting hui hai
        long long maxm = -1, maxidx = -1;

        for (auto it : room) {
            cout << it << " ";
        }
        cout << endl;

        for (long long i = 0; i < n; i++) {
            if (room[i] > maxm) {
                maxm = room[i];
                maxidx = i;
            }
        }

        return maxidx;
    }
};