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

void parenthesis (char * str){
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
                printf("Wrong expression\n");
        }
       
    }
    }
    if(!isempty(s)){
        printf("Correct expression\n");
    }
    else{
        printf("Wrong");
    }

}

int main(){
    stack *s1=(stack*)malloc(sizeof(stack));
    s1->size=10;
    s1->top=-1;
    s1->arr=(char*)malloc(s1->size * sizeof(char));
    int choice=-1;
        int i ;
        printf("1.Push\n2.Pop\n3.Paranthesis\n4.Exit\n");
     while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        // If-else ladder
        if(choice == 1){
           printf("Enter data: ");
           scanf("%d\n", &i);
           push(s1,i);
        }
        else if (choice == 2){
            printf("data popped: %d\n",pop(s1));
        }
        else if (choice == 3){
            char str[20];
            printf("Enter a expression: \n");
            gets(str);
            parenthesis(str);
        }

        else if (choice == 4){
            printf("BYE!!!\n");
            // Termination of the Loop using break statement
            break;
        }
        else{
            printf("> Invalid Input\n");
        }
    }
    return 0;
}