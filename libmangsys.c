/* Using C Language */

#include <stdio.h>
#include <stdlib.h>

void maximum_students();
int i,j,k,ai=0,cse=0,it=0,me=0,ece=0,stus[5],choice,max,max_stu,k=0;
char p,t,b,l,y,n,a,r,s;

struct student
{
    char student_id;
    char student_name[10];
    char branch[3];
    int year;
}st[10]= {
         {'A', "Ayush", "AI", 1},
         {'B', "Ramesh", "CSE", 1},
         {'C', "Suresh", "CSE", 2},
         {'D', "Rakesh", "ME", 2},
         {'E', "Lavani", "IT", 3},
         {'F', "Honey", "AI", 3},
         {'G', "Dev", "AI", 1},
         {'H', "Sparsh", "ECE", 1},
         {'I', "Raghav", "ECE", 2},
         {'J', "Ravi", "ME", 2}
         };

struct book
{
    char book_id;
    char book_title[50];
    int no_of_pages;
    float price;
}bk[20] = {
 {'a', "Let us c", 620, 255.5},
 {'b', "The Pragmatic Programmer", 300, 200.0},
 {'c', "Modern Operating Systems", 628, 258.1},
 {'d', "Introduction to Algorithms", 500, 241.2},
 {'e', "C Programming Language", 120, 255.3},
 {'f', "The C++ Programming Language", 980, 782.4},
 {'g', "The Little Schemer", 750, 249.5},
 {'h', "The Mythical Man-Month", 154, 987.6},
 {'i', "Programming Pearls", 785, 841.7},
 {'j', "Design Patterns", 623, 789.8},
 {'k', "Hackers: Heroes of the Computer Revolution", 629, 645.9},
 {'l', "Computer Graphics: Principles and Practice", 654, 781.2},
 {'m', "Effective Java", 941, 451.5},
 {'n', "Transaction Processing", 451, 123.7},
 {'o', "Computing: A Concise History", 199, 321.9},
 {'p', "Thinking in Java", 795, 456.2},
 {'q', "Data Structures and Algorithms", 123, 654.1},
 {'r', "Selected Papers on Computer Science", 784, 552.5},
 {'s', "The Art of UNIX Programming", 985, 156.5},
 {'t', "The Soul of A New Machine", 546, 651.6}};

 struct issue
 {
     char student_id;
     char book_id;
     int status;
 }iss[100];

 int main()
 {
 do
    {
    printf("Enter your choice:\n1) Wants to see which branch has maximum students\n2) To issue a book\n3) To deposit a book\n");
    scanf("%d",&choice);

    switch (choice)
    {
        case 1:maximum_students();
               break;

        case 2:printf("Enter student id: ");
               scanf("%c",&t);
               scanf("%c",&p);
               for(i=0;i<10;i++)
                    {
                        if(p==st[i].student_id)
                            {
                                printf("Enter book id to be issued: ");
                                scanf("%c",&a);
                                scanf("%c",&b);

                                for(j=0;j<20;j++)
                                    {
                                        if(b==bk[j].book_id)
                                           {
                                               for(l=0;l<k;l++)
                                                {
                                                    if(b==iss[l].book_id && iss[l].status==1)
                                                        {
                                                            printf("\nBook is already issued!");
                                                            break;
                                                        }
                                                }
                                                if(l==k)
                                                {
                                                    iss[k].student_id=p;
                                                    iss[k].book_id=b;
                                                    printf("\nBook issued!\n");
                                                    printf("Student's name: %s\n",st[i].student_name);
                                                    printf("Book name: %s\n",bk[j].book_title);
                                                    iss[k].status=1;
                                                    printf("Status: %d",iss[k].status);
                                                    k++;
                                                }
                                                break;
                                           }
                                       }
                                       if(j==20)
                                            printf("\nBook id doesn't exist!");
                                       break;
                                   }
                               }
                               if(i==10)
                                    printf("\nStudent id doesn't exist!\n");
                               break;
        case 3:printf("Enter student id: ");
               scanf("%c",&t);
               scanf("%c",&p);
               for(i=0;i<k;i++)
               {
                   if(p==iss[i].student_id)
                   {
                       printf("Enter book id to be deposited: ");
                       scanf("%c",&a);
                       scanf("%c",&b);
                       for(j=0;j<k;j++)
                       {
                           if(b==iss[j].book_id)
                           {
                               if(i==j && iss[i].status==1)
                               {
                                    printf("\nBook deposited!\n");
                                    iss[i].status=0;
                                    printf("Status: %d",iss[i].status);
                               }
                               else
                               {
                                   if(iss[i].status==0)
                                   {
                                       printf("\nThis student had already deposited this book!\n");
                                   }
                                   else
                                   {
                                       printf("\nThis book hadn't been issued to this student!");
                                   }
                               }
                               break;
                           }
                       }
                       if(j==k)
                        printf("\nThis book hadn't been issued!");
                       break;
                   }
               }
               if(i==k)
                    printf("\nThis student hadn't been issued any book!\n");
               break;

    }
    printf("\n\nWant to continue(y/n): ");
    scanf("%c",&y);
    scanf("%c",&n);
    printf("\n");
    }while(n=='y');


    return 0;
}


void maximum_students()
{
    for(i=0;i<10;i++)
                    {
                        if(strcmp(st[i].branch,"AI")==0)
                            ai++;
                        else if(strcmp(st[i].branch,"CSE")==0)
                            cse++;
                        else if(strcmp(st[i].branch,"IT")==0)
                            it++;
                        else if(strcmp(st[i].branch,"ECE")==0)
                            ece++;
                        else if(strcmp(st[i].branch,"ME")==0)
                            me++;
                    }

                printf("\nMaximum students is in ");

                if(ai>cse && ai>it && ai>ece && ai>me)
                    max=ai;
                else if(cse>ai && cse>it && cse>ece && cse>me)
                    max=cse;
                else if(it>ai && it>cse && it>ece && it>me)
                    max=it;
                else if(ece>ai && ece>cse && ece>it && ece>me)
                    max=ece;
                else if(me>ai && me>cse && me>it && me>ece)
                    max=me;

                if(max==ai)
                    printf("AI");
                else if(max==cse)
                    printf("CSE");
                else if(max==it)
                    printf("IT");
                else if(max==ece)
                    printf("ECE");
                else if(max==me)
                    printf("ME");

}
