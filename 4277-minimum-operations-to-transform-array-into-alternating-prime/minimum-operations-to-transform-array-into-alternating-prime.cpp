class Solution {
public:
    bool chk_prime(int n){
        if(n==1)return false;

        if(n==2)return true;
        
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
        }

        return true;
    }

    int make_prime(int n){
        int temp=n;
        int cnt2=0;
        

        temp=n;
       //forward checking 
        while(true){
            temp++;
            cnt2++;
            if(chk_prime(temp))break;
        }

        return cnt2;
    }

    int make_non_prime(int n){
        int cnt=0;
        int temp=n;
        while(true){
            temp++;
            cnt++;
            if(!chk_prime(temp))break;
        }

        return cnt;
    }
    int minOperations(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int n=nums[i];

            //even index ->> prime no.
            if(i%2==0){
                if(chk_prime(n)){
                continue;
            }

                else{
               cnt+= make_prime(n);
            }
                
            }


         //odd index ->> has to be no-Prime no. 
            else{
                if(chk_prime(n)){
                  cnt+=  make_non_prime(n);
                }

                else{
                    continue;
                }
            }
            
        }

        return cnt;
    }
};