#include <stdio.h>

int arr[20];
int top=-1;

void push(int item){
    top++;
    arr[top]=item;
}

int pop(){
    top--;
    return arr[top+1];
}

void prints(){
    for(int i=0;i<=top;i++){
        printf("%d \t",arr[i]);
    }
    printf("\n"); //  
}
int main() {
   char exp[]="231*+9-";
   int size=sizeof(exp)-1;
   
   
   for(int i=0;i<size;i++){
       if( exp[i]!='+' && exp[i]!='-' && exp[i]!='*' && exp[i]!='/' ){
           int number = exp[i] - '0';
           push(number);
       }
       else{
           int num1=pop();
           int num2=pop();
           int res=0;
           
           if(exp[i]=='+'){
               res=num2+num1;
           }
           else if(exp[i]=='-'){
               res=num2-num1;
           }
           else if(exp[i]=='*'){
               res=num2*num1;
           }
           else if(exp[i]=='/'){
               res=num2/num1;
           }
           push(res);
       }
   }
   
   printf("After evaluating the expression the value is : %d",pop());
   

    return 0;
}
