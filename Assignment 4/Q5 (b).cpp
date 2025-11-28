#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class stacker{
queue <int> st;
static int last;
public:
void push(int x){
    st.push(x);
    last=x;
}
void pop(){
    if(st.size()==0) {cout<<"underflow"; return;}
    else if(st.size()==1){
        st.pop();
        return;
    }
    else{
        int n=st.size();
        for(int i=0;i<n-1;i++){
            st.push(st.front());
            st.pop();
        }
        st.pop();
        return;
    }
}
bool isempty(){
    if (st.size()==0){return true;}
    return false;
}
int top(){
    if(st.size()==0) {cout<<"underflow";  return -1;}
    else if(st.size()==1){
        return st.front();
        
    }
    else{
        return last;
    }

}

};
int stacker::last=0;
int main() {
    stacker st1;
    st1.push(5);
    cout<<st1.top()<<endl;
    st1.push(7);
    cout<<st1.top()<<endl;
    st1.pop();
    cout<<st1.top()<<endl;
    st1.pop();
    st1.pop();



    return 0;
}