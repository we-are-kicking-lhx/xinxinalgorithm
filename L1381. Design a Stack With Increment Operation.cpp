class CustomStack {
public:
    CustomStack(int maxSize) {
        p=new int[maxSize];
        num_max=maxSize;
    }
    
    void push(int x) {
        cout<<"push"<<num_top<<endl;
        if(num_top<num_max) p[num_top++]=x;
    }
    
    int pop() {
        cout<<"pop"<<num_top<<endl;
        return num_top==0?-1:p[--num_top];
        
    }
    
    void increment(int k, int val) {
        for(int i=0;i<k && i<num_top;i++)
            p[i]+=val;
    }
    ~CustomStack(){
        delete[] p;
    }
private:
    int *p=nullptr;
    int num_top=0,num_max=0;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

// class CustomStack {
// public:
//     CustomStack(int maxSize) {
//         p=new int[maxSize]();
//         inc=new int[maxSize]();
//         // memset(inc,0,maxSize);
//         num_max=maxSize;
//     }
    
//     void push(int x) {
//         cout<<"push"<<num_top<<endl;
//         if(num_top<num_max) p[num_top++]=x;
//     }
    
//     int pop() {
//         cout<<"pop"<<num_top<<endl;
//         if(num_top<=0) return -1;
//         int val=p[--num_top]+inc[num_top];
//         cout<<inc[0]<<endl;
//         if(num_top>=1) inc[num_top-1]+=inc[num_top];
//         inc[num_top]=0;
//                 cout<<"pop"<<num_top<<endl;
//         return val;        
//     }
    
//     void increment(int k, int val) {
//         int n=min(k,num_top);
//         if(n>0) inc[n-1]+=val;
//     }
//     ~CustomStack(){
//         delete[] p;
//     }
// private:
//     int *p=nullptr;
//     int num_top=0,num_max=0;
//     int *inc=nullptr;
// };

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */