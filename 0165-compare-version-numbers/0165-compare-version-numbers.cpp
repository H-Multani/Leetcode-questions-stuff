class Solution {
public:
    int compareVersion(string v1, string v2) {
        // 2 pointers leke chk karte jao
        int n1 = v1.size();
        int n2 = v2.size();
        int i = 0, j = 0;

        while (i < n1 || j < n2) {
            // i se chalu karke . tak jo number hai nikalo v1 se
            string t1 = "";
            while (i < n1 && v1[i] != '.') {
                t1 += v1[i];
                i++;
            }

            // j se chalu karke . tak jo number hai nikalo v2 se
            string t2 = "";
            while (j < n2 && v2[j] != '.') {
                t2 += v2[j];
                j++;
            }

            // value nikalo
            int val1;
            int val2;

            // agar t1 is empty then val1=0, same with val2, since questn bola agar fewer revisions hai toh 0 maan lo
            if(t1=="") val1=0;
            else{
                // value nikal lo
                val1=stoi(t1);
            }
            if(t2=="") val2=0;
            else{
                // value nikal lo
                val2=stoi(t2);

            }

            // 

            if (val1 > val2)
                return 1;
            if (val1 < val2)
                return -1;

            // we here means same hai dono val, go to next string
            i++;
            j++;
        }

        return 0;
    }
};