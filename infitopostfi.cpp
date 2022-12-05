#include<iostream>
#define MAX 10
using namespace std;

class stack{
    char arr[MAX];
    int top=-1;
    public:
    
        bool push(char datain){
            bool success;
            if(top==MAX){
                return false;
            }
            else{
                top++;
                arr[top]=datain;
                return true;
            }
        }
        bool pop(){
            char dataout;
            if(top==-1){
                return false;
            }
            else{
                dataout=arr[top];
                top--;
                return true;
            }
        }
        char gtop(){
            bool success;
            char dataout;
            if(top==-1){
                success=false;
            }
            else{
                dataout=arr[top];
                return dataout;
            }
        }
        bool empty(){
            if(top==-1){
                return true;
            }
            else{
                return false;
            }
        }

        int prec(char s){
            if(s=='^'){
                return 3;
            }
            else if(s=='*' || s=='/'){
                return 2;
            }
            else if(s=='+' || s=='-'){
                return 1;
            }
            else{
                return -1;
            }
        }
};stack st;
void itp(string s){
    string result;
    
    for(int i=0;i<s.length();i++){
        char c= s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
            result+=c;
        }
        else if(c=='('){
            st.push(c);
        }
        else if(c==')'){
            while(st.gtop()!='('){
                result+=st.gtop();
                st.pop();
            }
            st.pop();
        }
        else{
            while(st.empty()==false && st.prec(c)<=st.prec(st.gtop())){
                result+=st.gtop();
                st.pop();
            }
            st.push(c);
        }
    }
    while(st.empty()==false){
        result+=st.gtop();
        st.pop();
    }
    cout<<result;


}
int main(){
    string s;
    s="((a+b)/(c-d))+e";
    itp(s);
    return 0;
}   