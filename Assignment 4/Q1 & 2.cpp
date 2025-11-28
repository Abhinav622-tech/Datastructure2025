#include <iostream>
using namespace std;
class q{
    int size=7;
    int q[7];
    int cursize=0;
    int start=-1;
    int end=-1;
    public:
    void push(int x){//push==enqueue
        if(cursize==size){cout<<"overflow";return;}
        if (cursize==0){
            start=0;
            end=0;
        }else end=(end+1)%size;
        q[end]=x;
        cursize++;
    }
    int pop(){
        if(cursize==0){
            cout<<"underflow";return -1;
        }
        int el=q[start];
        if(cursize==1){start=-1;end=-1;}
        else{start=(start+1)%size;}
        cursize--;
        return el;
    }
    int top(){
        if(cursize==0){cout<<"underflow";return -1;}
        return q[start];
    }
    int sizer(){
        return cursize;
    }
    bool isfull(){
        if(cursize==size) return true;
        return false;
    }
    bool isempty(){
        if(cursize==0) return true;
        return false;
    }
    void display(){
        cout<<endl;
        int i = start;
    for(int count=0; count<cursize; count++) {
        cout << q[i] << "\t";
        i = (i+1) % size;
    }
    cout << endl;
        return;
    }

};
int main()
{
    q que;
    for(int k=1;k<=7;k++){
        que.push(k);
    }
    for(int k=1;k<=4;k++){
        que.push(que.pop());
        que.pop();
    }
    
    que.display();
    
    return 0; 
}