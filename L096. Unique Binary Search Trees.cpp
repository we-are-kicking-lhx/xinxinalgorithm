class Solution {
public:
    int numTrees(int n) {
        long g=1;
        for(int i=0;i<n;i++){
            g=2*g*(2*i+1)/(i+2);
        }
        return (int)g;
    }
};