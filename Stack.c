#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int stack[30];
int top = -1;

void push(int x)
{
    stack[++top] = x;                                           
}

int pop()
{
    return stack[top--];                                          
}

int main()
{
    char e[50];
    char num[50];
    int g= 0;
    int res = 0,k=0, e1, op1, op2,temp;  
    fgets(e, sizeof(e), stdin);                                           
    int i = 0;
    while(e[i] != '\0')                                                                
    {
        if(g)                                                                
        {
            if(e[i] == ' ' || e[i] == ',' || e[i] == '\0')           
            {
                g= 0;
                temp = atoi(num);
                push(temp);
                k = 0;
                memset(num, 0, 5);
            }
            else
            {
                num[k] = e[i];
                k++;
            }
        }
        else if((e[i] != ' ' && e[i] != ',' && e[i] !='*' && e[i] != '/' && e[i] != '+' && e[i] && e[i] != '-')||(e[i] == '-' && e[i+1] != ' ' && e[i+1] != ',' && e[i+1] !=' ' && e[i+1] != '/' && e[i+1] != '+'))                                             /*if beginning of a number*/
        {
                g= 1;
                k = 0;
                num[k] = e[i];
                k++;
        }
        else if(e[i] == '+' || e[i] == '-' || e[i] =='*' || e[i] == '/')                                     
        {                                                                   
            op2 = pop();                                                                                          
            op1 = pop();
            if(e[i] == '+')
            {
                e1= op1+op2;
            }
            else if(e[i] == '-')
            {
                e1= op1-op2;
            }
            else if(e[i] == '*')
            {
                e1= op1*op2;
            }
            else if(e[i] == '/')
            {
                e1= op1/op2;
            }
            push(e1);                                                                                       
        }
        i++;
    }
    res = pop();                                                                                                                          
    printf("\n%d", res);                                                                                                        
    return 0;
}
