class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
   
        int l=0;
        int r=0;
       for(char it : moves){
        if(it=='L')l++;

        else if(it=='R')r++;
       }
    

    int mini=min(l,r);
    return (moves.length()-(2*mini));
}
};