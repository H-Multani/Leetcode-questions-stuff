class Solution {
public:
    int totalWaviness(int num1, int num2) {
        // laga lo loop and ans bana lo
        int ans=0;

        for(int val=num1;val<=num2;val++){
            if(val<100) continue;

            // string banalo for comparison
            string s=to_string(val);
            // cout<<s<<endl;
            int n=s.size();
            int wavines=0;

            for(int i=1;i<n-1;i++){
                if((s[i]>s[i-1] && s[i]>s[i+1]) || (s[i]<s[i-1] && s[i]<s[i+1])){
                    // means peak ya valley mili hai waviness count karlo
                    wavines++;
                }
            }

            // ans me add kardo wavines ko
            ans+=wavines;
        }

        return ans;
    }
};