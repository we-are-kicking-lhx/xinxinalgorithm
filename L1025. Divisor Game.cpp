class Solution {
public:
    bool divisorGame(int N) {
        vector<int> target(N+1);
        target[1]=0;
        if(N<=1) return false;
        else{
            target[2]=1;
            for(int i=3;i<N+1;i++){
                for(int j=1;j<i/2;j++){
                    if(i%j==0 && target[i-1]==0){
                        target[i]=1;
                        break;
                    }
                }
            }
            return target[N]==1;
        }

    }
};

// class Solution {
// public:
//     bool divisorGame(int N) {
//         return N%2==0? true : false;
//     }
// };