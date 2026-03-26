

class Solution {
public:
typedef long long ll;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        // part 1 wala logic likhenge but with some changes to accomodate
        // discounted wala item

        // prefix array ki jagah prev leke chalenge, prev will store ki prev row
        // tak agar include kare bass toh saare elements ka sum kya hai

        // toh for horizontal cut, and at i th row, prev will have the sum of
        // all elements from 0th row to i th row, then i+1 th row to end sum
        // rakh lenge apan(total- 0toisum)

        // aur iss difference ko dhundenge ki bade sum wale side me hai kya,
        // agar ye difference wala ek element hua means uss element ko alag kar
        // ke valid bana sakte hai in such case return true

        // toh element dhudne ke liye we will need map

        // pehle ek prev lelo and 2 maps lelo
        // map1-> stores elements of 0th row to ith row
        // map2-> stores elements of i+1 th row to nth row
        // ek prev lelo which stores sum of all elements frm 0 th row to i th
        // row ek ttl lelo which will store sum of all elements

        long long prev = -1;
        long long ttl = 0;
        ll m = grid.size();
        ll n = grid[0].size();

        unordered_map<long long, ll> mpp1;
        unordered_map<ll, ll> mpp2;

        // mpp2 ko bhar do saare elements se, since isme i+1th row to n th row
        // ke elements store honge toh rows par iterate karte time remove karte
        // jaenge
        for (auto it : grid) {
            for (auto it2 : it) {
                mpp2[it2]++;
                ttl += it2;
            }
        }

        // iterate karo grid par
        for (int row = 0; row < m; row++) {
            // edge case, agar ek hi row hai toh ye loop chalao hi mat since
            // aage m-2 idx ka kaam hai, dikkat akrega
            if (m == 1)
                break;

            // cout << " lloo1 " << endl;

            // agar first row me hai toh prev ko 0 se start karke current row
            // include karo

            // nai toh in general current row ko include karp prev me

            // why?, since aim is to slice after this current row, toh row par
            // chal lene ke baad slice karenge

            // current row ko apan lower wale side se upper wale side me bhejre
            // hai
            if (row == 0)
                prev = 0;
            // include elements of this row in mpp1, and exclude from mpp2, toh
            // prev me add kar dena
            for (int col = 0; col < n; col++) {
                int curr = grid[row][col];
                prev += curr;

                // mpp1 me include karo
                mpp1[curr]++;

                // mpp2 se exclude karo

                mpp2[curr]--;
                if (mpp2[curr] == 0) {
                    // element ko map se alag kardo
                    mpp2.erase(curr);
                }
            }

            // ab 0th row to i th row ka sum is in prev, i+1 th row to end will
            // be
            long long remaining = ttl - prev;
            // cout << "rem " << remaining << endl;

            // ab agar ye dono sides ke sum already same hai toh true bhejdo
            // yehi se, no need to remove element
            if (remaining == prev)
                return true;

            // we here means differnce aa raha kuch, kitna difference hai
            long long diff = abs(remaining - prev);
            // cout << "diff " << diff << endl;

            if (prev > remaining) {
                // agar upper wala side ka sum bada hai toh upper wale side se
                // alag karna padega element, diff ko upper wale map me dhundo,
                // mil jaaye toh means iss element ko alag karke valid bana
                // sakte hai partition, in such case return true also

                // edge case yaha ki first row hai agar, toh elements beech se
                // nai nikal sakte, since then connected nai rahega(note padho
                // question ka)
                if (mpp1.find(diff) != mpp1.end()) {
                    // means element nikal kar valid bana sakte partion ko,
                    // return true
                    // cout << "her1 " << endl;

                    // agar first row par apan hai current toh elements beech se
                    // nai nikal sakte since upar side bass 1 row hai
                    if (row == 0) {
                        // means element beech se nai nikal sakte, means sirf
                        // left ya right se nikal sakte hai

                        // toh upar wali row me se dekho agar diff edges par hai
                        // toh nikal sakte hai valid no worries

                        if (grid[row][0] == diff || grid[row][n - 1] == diff) {
                            // means diff wala element right ya left edge se
                            // nikal sakte hai, in such case nikal lo
                        } else {
                            // we here means nai nikal sakte beech se hi nikalna
                            // padega, which is not possible since not connected
                            // ho jayega, in such case true nai bhej sakte, aage
                            // search karo
                            continue;
                        }
                    }
                    // edge case, agar apne paas column hi ek hai , toh ye upar
                    // row wali checking iss column ke liye bhi karni padegi,
                    // since maan lo 1 column is like [4,1,5,5,5], and we are at
                    // row=2(split like [4,5,1][5,5]), toh yaha bhale diff=1 can
                    // be removed lekin its not valid since 1 remove karne se
                    // connected nai rahega, toh yaha sirf [0][0] wala
                    // element(0th row wala 4) alag kar sakte ya fir [row][0]
                    // wala(row wala 5), inke alava kuch bhi nai kar sakte
                    else if (n == 1) {

                        // we here means 1 hi column hai, toh [row+1][0] wala
                        // remove kar sakte ya fir [m-1][0] wala only, toh agar
                        // ye dono elements me se koi diff hai toh kardo alag
                        // and reutrn true
                        if (grid[0][0] == diff || grid[row][0] == diff) {
                        } else {
                            continue;
                        }
                        // means row hi ek hai
                    }
                    return true;
                }
            } else {
                // agar lower wala side ka sum bada hai toh lower wale side se
                // alag karna padega element, diff ko lower wale map me dhundo,
                // mil jaaye toh means iss element ko alag karke valid bana
                // sakte hai partition, in such case return true also

                // edge case yaha ki first column hai agar, toh elements beech
                // se nai nikal sakte, since then connected nai rahega(note
                // padho question ka)
                if (mpp2.find(diff) != mpp2.end()) {
                    // cout << "here " << endl;
                    // means element nikal kar valid bana sakte partion ko,
                    // return true

                    // agar neeche se 2nd row par apan hai current toh elements
                    // beech se nai nikal sakte since neeche side bass 1 row hai
                    if (row == m - 2) {
                        // means element beech se nai nikal sakte, means sirf
                        // left ya right se nikal sakte hai

                        // toh neeche wali row me edges par diff ko dhundo, agar
                        // mil gaya means nikal sakte hai and bana sakte hai
                        // valid ans
                        if (grid[row + 1][0] == diff ||
                            grid[row + 1][n - 1] == diff) {
                            // means diff wala element right ya left edge se
                            // nikal sakte hai, in such case nikal lo
                        } else {
                            // we here means nai nikal sakte beech se hi nikalna
                            // padega, which is not possible since not connected
                            // ho jayega, in such case true nai bhej sakte, aage
                            // search karo
                            continue;
                        }
                    }
                    // edge case, agar apne paas column hi ek hai , toh ye last
                    // row wali checking iss column ke liye bhi karni padegi,
                    // since maan lo 1 column is like [10,5,4,5], and we are at
                    // row=0(split like [10][5,4,5]), toh yaha bhale diff=4 can
                    // be removed lekin its not valid since 4 remove karne se
                    // connected nai rahega, toh yaha sirf [row+1][0] wala
                    // element(row+1 wala 5) alag kar sakte ya fir [m-1][0]
                    // wala(m-1th row wala 5), inke alava kuch bhi nai kar sakte
                    else if (n == 1) {

                        // we here means 1 hi column hai, toh [row+1][0] wala
                        // remove kar sakte ya fir [m-1][0] wala only, toh agar
                        // ye dono elements me se koi diff hai toh kardo alag
                        // and reutrn true
                        if (grid[row + 1][0] == diff ||
                            grid[m - 1][0] == diff) {
                        } else {
                            continue;
                        }
                        // means row hi ek hai
                    }

                    return true;
                }
            }
            // we here means kuch nai ho sakta yaha, aage badho
        }

        // ab ye apan ka pura kaam ho gaya horizontal cuts ke liye,

        // same kaam karo vertical cuts ke liye,

        // maps ko clear kardo, prev ko clear kardo, and start kar lo
        mpp1.clear();
        mpp2.clear();
        prev = -1;
        // refill mpp2
        for (auto it : grid) {
            for (auto it2 : it) {
                mpp2[it2]++;
            }
        }
        // ab dono ke liye dhund liya hai, ab nai mil sakta toh return false

        for (int col = 0; col < n; col++) {
            if (n == 1)
                break;

            if (col == 0)
                prev = 0;

            for (int row = 0; row < m; row++) {
                int curr = grid[row][col];
                prev += curr;
                mpp1[curr]++;
                mpp2[curr]--;
                if (mpp2[curr] == 0) {
                    mpp2.erase(curr);
                }
            }
            long long remaining = ttl - prev;
            // cout << "prev " << prev << endl;
            // cout << "rem " << remaining << endl;
            if (remaining == prev)
                return true;

            long long diff = abs(remaining - prev);
            // cout << "diff is " << diff << endl;

            if (prev > remaining) {
                if (mpp1.find(diff) != mpp1.end()) {
                    if (col == 0) {
                        if (grid[0][col] == diff || grid[m - 1][col] == diff) {
                        } else {
                            continue;
                        }
                    } else if (m == 1) {
                        if (grid[0][0] == diff || grid[0][col] == diff) {

                        } else {
                            continue;
                        }
                    }
                    return true;
                }
            } else {
                if (mpp2.find(diff) != mpp2.end()) {
                    // cout << "here2 " << endl;
                    if (col == n - 2) {
                        if (grid[0][col + 1] == diff ||
                            grid[m - 1][col + 1] == diff) {
                        } else {
                            continue;
                        }
                    } else if (m == 1) {
                        // cout << "here3" << endl;
                        if (grid[0][col + 1] == diff ||
                            grid[0][n - 1] == diff) {

                        } else {
                            continue;
                        }
                        // means row hi ek hai
                    }

                    return true;
                }
            }
        }
        return false;
    }
};