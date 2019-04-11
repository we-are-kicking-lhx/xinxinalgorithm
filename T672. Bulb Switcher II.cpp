class Solution {
public:
    int flipLights(int n, int m) {
        if (!n) return 0;
        if (!m) return 1;
        if (n == 1) return 2;
        if (n == 2){
            if(m == 1) return 3;
            return 4;
        }
        if (m == 2) return 7;
        if (m == 1) return 4;
        return 8;
    }
};