#include<stdio.h>
#include<stdlib.h>
int n=0;
struct studentnode {
	char name[15];
        char usn[15];
        char programme[10];
        char phoneno[15];
        int sem;
	struct studentnode *next;
};
typedef struct studentnode(*NODE);
NODE createlist(NODE first);
NODE insertfront(NODE first);
NODE insertrear(NODE first);
NODE deletefront(NODE first);
NODE deleterear(NODE first);
NODE stacksimulation(NODE first);void display(NODE first);NODE getnode();


NODE createlist(NODE first)
{
	int i;
	printf("enter the number of students information to be stored in linked list \n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		first=insertfront(first);
	}
	return first;
}
NODE insertfront(NODE first){
	NODE newnode ;
	newnode=getnode();
	if(newnode==NULL)
		printf("no memory available\n");
	else 
		newnode->next=first;
	return newnode;
	}
NODE getnode(){
	NODE newnode;
	newnode=(NODE) malloc (sizeof(struct studentnode));
	if(newnode==NULL)
			return NULL;
	printf("\n enter the name,usn,programme,phoneno,sem\n");
	scanf("%s %s %s  %s",newnode->name,newnode->usn,newnode->programme,newnode->phoneno);
	scanf("%d",&newnode->sem);
	newnode->next=NULL;
	return newnode;
}
NODE insertrear(NODE first)
{
	NODE newnode,cur=first;
	newnode=getnode();
	if(newnode==NULL)
		return newnode;
	while(cur->next!=NULL)
		cur=cur->next;
	cur->next=newnode;
	n++;
	return first;
}

NODE deletefront(NODE first)
{
	NODE temp=first;

	printf("the deleted student information is %s %s %s %d %s",first->name,first->usn,first->programme,first->sem,first->phoneno);
	first=first->next;
	free(temp);
	n--;
	return first;
}
NODE deleterear(NODE first){
	NODE cur ,prev;
	cur=first;
	if(first==NULL){
		printf("list is empty \n");
		return NULL ;
	}
	if(first->next==NULL){
		printf("the deleted student information is %s %s %s %d %s",first->name,first->usn,first->programme,first->sem,first->phoneno);           first=NULL;
		free(first);
	}
	while(cur->next!=NULL){
		prev=cur;
		cur=cur->next;
	}
	prev->next=NULL;
	printf("the deleted student information is %s %s %s %d %s",first->name,first->usn,first->programme,first->sem,first->phoneno);
       free(cur);
       n--;
       return first;}
NODE stacksimulation(NODE first)
{
	int ch;
	while(1){
		printf("\n1.push(insert at front)\n2.pop(deleted at front)\n3.display\n4.exit");
		scanf("%d",&ch);
		switch(ch){
			case 1:first=insertfront(first);break;
			case 2:first=deletefront(first);break;
			case 3:display(first);break;
			case 4:return first;
		}
	}
}
void display(NODE first){
	NODE cur;
	if(first==NULL)
		printf("list is empty\n");else{
	cur=first;
	printf("\nstudent\tusn\tprogramme\tsem\tphone no\n");while(cur!=NULL){
	printf("%s\t %s\t %s\t %d\t %s\n",cur->name,cur->usn,cur->programme,cur->sem,cur->phoneno);
	cur=cur->next;}}}
void main(){
	int ch;
	NODE first=NULL;
	while(1){
		printf("\n1.create list\n2.insertionfront\n3.insertion rear\n4.delete front\n5.delete rear\n6.stack impletation\n7.display\n8.exit");
	       printf("enter your choice \n");
       scanf("%d",&ch);
       switch(ch){
	       case 1:first=createlist(first);break;
	       case 2:first=insertfront(first);break;
	       case 3:first=insertrear(first);break;
	       case 4:first=deletefront(first);break;
	       case 5:first=deleterear(first);break;
	       case 6:first=stacksimulation(first);break;
	       case 7:display(first);break;
	       case 8:exit(0);break;default :printf("enter valid choice\n");
       }}}

	      



