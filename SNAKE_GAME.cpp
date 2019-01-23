#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<conio.h>
#include <ctime>
#include<fstream>
#include<windows.h>
#include<iomanip>
//#include<stdlib.h>

using namespace std;
const int r = 20;
const int c = 40;
struct snake
{
	int x;
	int y;
	char value;
	snake *next;
};
snake *create(int x,int y)
{
	snake *ptr=new snake;
	ptr->x=x;
	ptr->y=y;
	ptr->value='~';
	ptr->next=NULL;
	return ptr;
}
void create_snake(snake **head)
{
	snake *temp,*t;
	int i,len=5;
	for(i=len;i>0;i--)
	{
		temp=create(3,i);
		if(*head==NULL)
		*head=temp;
		else
		{
			snake *t=*head;
			while(t->next!=NULL)
			{
				t=t->next;
			}
			t=t->next=temp;

		}
	}
}
void insert(snake **t,int x,int y)
{
    snake *p=*t;
    snake *temp;
    temp=create(x,y);
    if(*t==NULL)
        *t=temp;
    else
    {
        p=(*t);
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
    }

}
void create_map(char *map)
{
    int i,j;
	for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(i==0||i==r-1||j==0||j==c-1)
                map[i*c+j]='X';
            else
                map[i*c+j]=' ';
        }
    }
}
void display(char map[r][c])
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%c ",map[i][j]);
		}
		printf("\n");
	}
}
void put_snake(char *map,snake *t,int x,int y,int a,int b,int flag)
{
    while(t!=NULL)
    {
        map[(t->x)*c+(t->y)]=(t->value);
        t=t->next;
    }
    if(flag==0)
    {
    map[x*c+y]='o';
    }
    map[a*c+b]='-';
}
void right(snake **t)
{
    snake *p=(*t);
    snake *w=(*t);
    int x,y,temp;
    w=w->next;
    if(p->y+1!=w->y)
    {
    x=(p->x);
    y=(p->y)+1;
    if(y==c)
        y=1;
    while(p!=NULL)
    {
    	temp=(p->x);
    	p->x=x;
    	x=temp;
    	temp=(p->y);
    	p->y=y;
    	y=temp;
    	p=p->next;
	}
}}

 void down(snake **t)
{
    snake *p=(*t);
    snake *w=(*t);
    int x,y,temp;
    w=w->next;
    if(p->x+1!=w->x)
    {
    x=(p->x)+1;
    y=(p->y);
    if(x==r)
        x=1;
    while(p!=NULL)
    {
    	temp=(p->x);
    	p->x=x;
    	x=temp;
    	temp=(p->y);
    	p->y=y;
    	y=temp;
    	p=p->next;
	}
    }
}

void up(snake **t)
{
    snake *p=(*t);
    snake *w=(*t);
    int x,y,temp;
    w=w->next;
    if(p->x-1!=w->x)
    {
    x=(p->x)-1;
    y=(p->y);
    if(x==0)
        x=r-2;
    while(p!=NULL)
    {
    	temp=(p->x);
    	p->x=x;
    	x=temp;
    	temp=(p->y);
    	p->y=y;
    	y=temp;
    	p=p->next;
	}
    }
}
void left(snake **t)
{

    snake *p=(*t);
    snake *w=(*t);
    int x,y,temp;
    w=w->next;
    if(p->y-1!=w->y)
    {
    x=(p->x);
    y=(p->y)-1;
    if(y==0)
        y=c-2;
    while(p!=NULL)
    {
    	temp=(p->x);
    	p->x=x;
    	x=temp;
    	temp=(p->y);
    	p->y=y;
    	y=temp;
    	p=p->next;
	}
    }
}
void food(int *x,int *y)
{
    *x = (1 + (rand() % (int)((r-1) - 1 + 1)));
    *y = (1 + (rand() % (int)((c-1) - 1 + 1)));
}
void poison(int *a,int *b)
{
    *a = (1 + (rand() % (int)((r-1) - 1 + 1)));
    *b = (1 + (rand() % (int)((c-1) - 1 + 1)));
}
void grow(snake **t,char ch)
{
    snake *p,*temp;
    p=*t;
    if(ch=='w'||ch=='W')
    temp=create(p->x-1,p->y);
    else if(ch=='d'||ch=='D')
    temp=create(p->x,p->y+1);
    else if(ch=='a'||ch=='A')
    temp=create(p->x,p->y-1);
    else if(ch=='s'||ch=='S')
    temp=create(p->x+1,p->y);
    temp->next=*t;
    *t=temp;
}
int suicide(snake **t)
{
    snake *p,*temp;
    p=*t;
    temp=*t;
    p=p->next;
    while(p!=NULL)
    {
        if(p->x==temp->x&&p->y==temp->y)
            return 1;
        p=p->next;
    }
   return 0;
}
int enter()
{
    int n;
    system("cls");
    printf("WELCOME TO SNAKE GAME\n");
    printf("CHOOSE:-\n");
    printf("1.New Game\n");
    printf("2.Continue Game\n");
    scanf("%d",&n);
    return n;
}
int main()
{
    int choice=enter();
    int fx,fy,px,py,x,y,v,flag=0,points=0;
    char input;
	snake *head=NULL;
	snake *t;
	char map[r][c];
	fstream f;
    switch(choice)
    {
        case 1:create_snake(&head);
               food(&fx,&fy);
               poison(&px,&py);
               break;
        case 2: f.open("Save3.txt",ios::in);
                  f>>points;
                f>>fx;
                f>>fy;
                f>>px;
                f>>py;
                while(!f.eof())
                {
                    f>>x;
                    f>>y;
                    insert(&head,x,y);
                }
                break;
        default: system("cls");
                 printf("Invalid choice !! Please Enter Again\n");
                 getch();
                 choice=enter();
    }
	create_map((char *)map);
    put_snake((char *)map,head,fx,fy,px,py,flag);
    system("cls");
    display(map);
    input=getch();
    while(input!='q'&&input!='Q')
    {
        if(input=='d'||input=='D')
        {
            right(&head);
        }
        else if(input=='s'||input=='S')
        {
            down(&head);
        }
        else if(input=='w'||input=='W')
        {
            up(&head);
        }
        else if(input=='a'||input=='A')
        {
            left(&head);
        }
            create_map((char *)map);
            if(head->x==fx&&head->y==fy)
            {
            	Beep(1400,150);
                points++;
            flag=1;
            food(&fx,&fy);
            grow(&head,input);
            }
            if(head->x==px&&head->y==py)
            {
            	Beep(2000,150);
                points--;
                poison(&px,&py);
                 if(head->next==NULL)
                {
                	Beep(3000,150);
                    system("cls");
                    printf("Game Over\n");
                    exit(1);
                }
                 head=head->next;
                head->value='~';
            }
            if(suicide(&head))
            {
            	Beep(3000,150);
                system("cls");
                printf("Game Over\n");
                printf("Your Score is %d",points);
                getch();
             exit(1);
            }
            put_snake((char *)map,head,fx,fy,px,py,flag);
            flag=0;
            //clrscr();
            system("cls");
            display(map);
            input=getch();
    }
    if(input=='Q'||input=='q')
    {
	 f.open("Save3.txt",ios::out);
        f<<points;
        f<<'\n';
        f<<fx;
        f<<'\n';
        f<<fy;
        f<<'\n';
        f<<px;
        f<<'\n';
        f<<py;
        f<<'\n';
        t=head;
        while(t!=NULL)
        {
            f<<t->x;
            f<<'\n';
            f<<t->y;
            f<<'\n';
            t=t->next;
        }
        f.close();
    }
	return 0;
}

