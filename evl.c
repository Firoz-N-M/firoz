#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
void push(float stk[],int *top,float op){
	*top=*top+1;
	stk[*top]=op;
}
 float pop(float stk[],int *top)
{
	float res;
	res=stk[*top];
	*top=*top-1;
	return res;
}
float compute (float op1,float op2,char s)
{
   switch(s){
	   case'+':return op1+op2;break;
	   case'-':return op1-op2;break;
	   case'*':return op1*op2;break;
	   case'/':return op1/op2;break;
      	   case'%':return (int) op1%(int) op2;break;
	   case'^':return pow(op2,op1);break;
           case'$':return pow(op2,op1);break;
           }}
void evalpostfix(){
	char sym,post[20];
	int i=0 ,j=0,top=-1;
	float stk[20],item,op1,op2,res;
        printf("enter the valid postfix expression \n");
	scanf("%s",post);
	while(post[i]!='\0')
	{
		sym=post[i++];
                if(isdigit(sym)){
			item=sym-'0';
			push(stk,&top,item);}
		else {
			op2=pop(stk,&top);
			op1=pop(stk,&top);
			res=compute(op1,op2,sym);
			push(stk,&top,res);
		}}
	res=pop(stk,&top);
	printf("the result of postfix expession is %f\n",res);
}
void main(){
		evalpostfix();}
