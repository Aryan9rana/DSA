#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stack{
    int size;
    int top;
    char *arr;
}stack;



int isempty(stack *a){
    if(a->top==-1) return 1;
    else return 0;
}

int isfull(stack * a){
    if(a->top==(a->size)-1) return 1;
    else return 0;
}

void push(stack * s,char data)
{
    if(isfull(s)){
        printf("stack overflow");
    }
    else{
        (s->top)++;
        s->arr[s->top]=data;
    }
}

char pop(stack * s){

        char val= s->arr[s->top];
        s->top--;
        return val;
}

int match(char a, char b){
    if(a=='{'&&b=='}') return 1;
    if(a=='['&&b==']') return 1;
    if(a=='('&&b==')') return 1;
    if(a=='<'&&b=='>') return 1;

    else return 0;
}

int parenthesis (char * str){
    stack *s=(stack*)malloc(sizeof(stack));
    s->size=20;
    s->top=-1;
    s->arr=(char*)malloc(s->size * sizeof(char));

    int l=strlen(str);
    for(int i=0;i<l;i++){
        if(str[i]=='{'||str[i]=='['||str[i]=='('||str[i]=='<'){
            push(s,str[i]);
        }
        else if(str[i]=='}'||str[i]==']'||str[i]==')'||str[i]=='>'){
            char a=pop(s);
            if(!match(a,str[i])){
                return 0;
        }
       
    }
    }
    if(isempty(s)){
        return 1;
    }
    else{
        return 0;
    }

}

int main(){

            char str[20];
            printf("Enter a expression: \n");
            scanf("%[^\n]%*c", str);
            int c=parenthesis(str);
            if(c){
                printf("correct\n");
  
            }
            else printf("Incorrect");
        

    return 0;
    }
