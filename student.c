#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

int r=1,gr=4000; FILE *p;

struct student
{
    char name[100];
    int roll_no,GR_no;
    int twelvethmark;
    struct student *next;
}*start;

void create()
{
    int n;
    struct student *newnode,*temp;

   newnode=(struct student*)malloc(sizeof(struct student));
   printf("enter name in capitals only and twelve-th mark  no. \n");
   scanf("%s%d",newnode->name,&newnode->twelvethmark);

  newnode->GR_no=gr++;
  newnode->roll_no=r++;
  newnode->next=NULL;
  if(start==NULL)
   {
       start=newnode;
       start->next=NULL;
   }
   else
   {
       temp=start;
       while(temp->next!=NULL)
       temp=temp->next;
       temp->next=newnode;
   }
   printf("creation successful.\n");


}


void sort()
{
     struct student *tem;   int m; char n[50];
     int i;
     if(start==NULL)
   {
    printf("first enter students detail!!\n");
   }
     else
   {
   do
   {
       i=0;
       tem=start;
       while(tem->next!=NULL)
    {

        if(strcmp(tem->name,tem->next->name)>0)
        {
          strcpy(n,tem->name);
          strcpy(tem->name,tem->next->name);
          strcpy(tem->next->name,n);
          m=tem->twelvethmark;
          tem->twelvethmark=tem->next->twelvethmark;
          tem->next->twelvethmark=m;
          m=tem->GR_no;
          tem->GR_no=tem->next->GR_no;
          tem->next->GR_no=m;
        i=1;
        }

        tem=tem->next;
    }
   }while(i!=0);


    p=fopen("F:\\exp.text","w");
    if(start->next==NULL)
    {
        fprintf(p,"%d\t%d\t%s\t%d\n",start->GR_no,start->roll_no,start->name,start->twelvethmark);
        printf("%d\t%d\t%s\t%d\n",start->GR_no,start->roll_no,start->name,start->twelvethmark);
        fclose(p);
    }
    else
    {

     tem=start;
     while(tem->next!=NULL)
     {
     fprintf(p,"%d\t%d\t%s\t%d\n",tem->GR_no,tem->roll_no,tem->name,tem->twelvethmark);
     printf("%d\t%d\t%s\t%d\n",tem->GR_no,tem->roll_no,tem->name,tem->twelvethmark);
     tem=tem->next;

     }
     fprintf(p,"%d\t%d\t%s\t%d\n",tem->GR_no,tem->roll_no,tem->name,tem->twelvethmark);
     printf("%d\t%d\t%s\t%d\n",tem->GR_no,tem->roll_no,tem->name,tem->twelvethmark);

     fclose(p);
    }

       printf("you can ALSO see the students details in TEXT file exp in F drive.");
  }
}


void sm()
{
     struct student *tem;   int m; char n[50];
     int i;
     if(start==NULL)
 {
    printf("first enter students detail!!\n");
 }
     else
 {
  do
   {
       i=0;
       tem=start;
       while(tem->next!=NULL)
       {

        if(tem->twelvethmark<tem->next->twelvethmark)
        {
          strcpy(n,tem->name);
          strcpy(tem->name,tem->next->name);
          strcpy(tem->next->name,n);
          m=tem->twelvethmark;
          tem->twelvethmark=tem->next->twelvethmark;
          tem->next->twelvethmark=m;
          m=tem->GR_no;
          tem->GR_no=tem->next->GR_no;
          tem->next->GR_no=m;
          i=1;
        }

        tem=tem->next;
    }
   }while(i!=0);


    p=fopen("F:\\exp.text","w");
    if(start->next==NULL)
    {
        fprintf(p,"%d\t%d\t%s\t%d\n",start->GR_no,start->roll_no,start->name,start->twelvethmark);
        printf("%d\t%d\t%s\t%d\n",start->GR_no,start->roll_no,start->name,start->twelvethmark);
        fclose(p);
    }
    else
    {

     tem=start;
     while(tem->next!=NULL)
     {
     fprintf(p,"%d\t%d\t%s\t%d\n",tem->GR_no,tem->roll_no,tem->name,tem->twelvethmark);
     printf("%d\t%d\t%s\t%d\n",tem->GR_no,tem->roll_no,tem->name,tem->twelvethmark);
     tem=tem->next;

     }
     fprintf(p,"%d\t%d\t%s\t%d\n",tem->GR_no,tem->roll_no,tem->name,tem->twelvethmark);
     printf("%d\t%d\t%s\t%d\n",tem->GR_no,tem->roll_no,tem->name,tem->twelvethmark);

     fclose(p);
    }

       printf("you can ALSO see the students details in TEXT file exp in F drive.");
  }
}


void restore()
{
    int x,i; FILE *f2;
    int a,b,c; char s[50];
    int m=0;


    struct student *newnode,*temp;


    x=count();
    f2=fopen("F:\\exp.text","r");
    i=1;

    while(i<=x)
    {
         newnode=(struct student *)malloc(sizeof(struct student));
         fscanf(f2,"%d%d%s%d",&a,&b,newnode->name,&c);

        if(a>m)
        {
            m=a;
        }
        newnode->GR_no=a;
        newnode->roll_no=b;
        newnode->twelvethmark=c;
         newnode->next=NULL;

   if(start==NULL)
   {
       start=newnode;
       start->next=NULL;
   }
   else
   {
       temp=start;
       while(temp->next!=NULL)
       temp=temp->next;
       temp->next=newnode;
   }
   i++;
    }


    if(m!=0&&b!=0)
    {
    gr=++m;
    r=++b;
    }


    fclose(f2);
}

 int  count()
 {
       FILE *fp; int c,i ;int count=0;
       struct student *newnode,*temp;
       newnode=(struct student*)malloc(sizeof(struct student));

      fp=fopen("F:\\exp.text","r");
      if (fp == NULL)
    {
               return 0;
    }

    // Extract characters from file and store in character c
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n') // Increment count if this character is newline
            count = count + 1;
    fclose(fp);

    return(count);

}


void deletedata()
{  FILE *p2;
    struct student *tem,*temp,*temp1,*temp2;
    char s[50];
    printf("enter name of student in capitals only:\n");
    scanf("%s",s);
    temp=start;
    if(start==NULL)
    {
        printf("Database is empty.\n");
    }
   else
    {
        if(start->next==NULL)
        {
            start=NULL;
            r=1;    gr=4000;
        }
    else
        {
          while(temp->next!=NULL)
           {
            temp1=temp;
             temp=temp->next;
             if(strcmp(s,temp1->name)==0)
             {
                 start=temp1->next;
                  r=temp1->roll_no;
                 break;
             }
             else
                if(strcmp(s,temp->name)==0)
                {
                 temp1->next=temp->next;
                 r=temp->roll_no;
                  break;
                }
            }
//==================================================================================

    temp2=temp1->next;
    while(temp2!=NULL)
    {
       temp2->roll_no=r++;
       temp2=temp2->next;
    }
    }
    printf("\nstudent's detail is deleted successfully.");
    }


    //====================================================================================
    printf("\nThe updated Student data is:");

    p2=fopen("F:\\exp.text","w");
    if(start==NULL)
    {printf("\nThe database is already empty!");
    fclose(p2);
    }
    else
    {
     tem=start;
     while(tem->next!=NULL)
     {
    fprintf(p2,"%d\t%d\t%s\t%d\n",tem->GR_no,tem->roll_no,tem->name,tem->twelvethmark);
    printf("\n%d\t%d\t%s\t%d",tem->GR_no,tem->roll_no,tem->name,tem->twelvethmark);
     tem=tem->next;

     }
     fprintf(p2,"%d\t%d\t%s\t%d\n",tem->GR_no,tem->roll_no,tem->name,tem->twelvethmark);
     printf("\n%d\t%d\t%s\t%d",tem->GR_no,tem->roll_no,tem->name,tem->twelvethmark);

     fclose(p2);
    }

       printf("\nyou can ALSO see the students details in TEXT file exp in F drive.");



}


void main()
{ int y;
  restore();
    do
    {
      printf("\n===MENU===\n0:Sort according to marks\n1:insert details of student\n2:display according to name\n3:Delete data of student\n4:exit\nenter choice:");
      scanf("%d",&y);
      switch(y)
      {   case 0:
          sm();
          break;
          case 1: create();
                  break;
         case 2: sort();
                break;
         case 3:deletedata();
                break;
         case 4: exit(0);
                 break;
         default: printf("enter valid choice!!!\n");
      }

    }while(y!=4);


}
