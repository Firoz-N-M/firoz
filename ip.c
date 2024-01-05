#include<stdio.h>
#include<stdlib.h>
int g(char);
int f(char);
int f(char sym)
{
	switch(sym){
		case'+':return 2;
		case '-':return 2; 
	        case'*':return 4;
		case'/':return 4;
		case'%':return 4;
		case'$':return 5;
		case'^':return 5;
		case'(':return 0;
		case'#':return -1;
		default:return 8;
		}}
int g(char sym){
	switch(sym){
		case'+':return 1;
		case'-':return 1;
		case'*':return 3;
		case'/':return 3;
		case'%':return 3;
		case'$':return 6;
		case'^':return 6;
		case'(':return 9;
		case')':return 0;
                defalut:return 7;}}
void infixtopostfix(char in[],char post[]){
	int i=0,j=0,top=-1;
	char stk[20],sym;
	stk[++top]='#';
	while(in[i]!='\0')
	{
		sym=in[i++];
		while(f(stk[top])>g(sym))
			post[j++]=stk[top--];
		if(f(stk[top])!=g(sym))
			stk[++top]=sym;
		else
			stk[top--];
	}
	while(stk[top]!='#'){
		post[j++]=stk[top--];}
	post[j++]='\0';
}
int main(){
	char infix[50],postfix[50];
	printf("enter a valid infix expression\n");
	scanf("%s",infix);
	infixtopostfix(infix,postfix);
	printf("the given infix expression is: %s\n  equivalent psotfix expression is: %s\n",infix,postfix);
	return 0;}
