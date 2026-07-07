class Solution {
public:
    long long sumAndMultiply(int n) {

        long long x=0,ttl=0;

        while(n>0){
            // digit nikalo
            int dgt=n%10;
            n/=10;

            if(dgt!=0){
                ttl+=dgt;
                x*=10;
                x+=dgt;
            }
        }

        // ek cheez hai yaha ki since apan digit extraction karre hai means digits reverse order me aayenge, string me bana kar reverse kardena
        string newx=to_string(x);

        reverse(newx.begin(),newx.end());

        // vapas integer bana dena
        x=stoll(newx);

        cout<<x<<" "<<ttl<<endl;
        return x*ttl;
        
    }
};