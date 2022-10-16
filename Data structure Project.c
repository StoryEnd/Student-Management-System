#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct student
{
    int id;
    char name[20];
    char adress[20];
    char par_name[20];
    int batch;
    int phone_no;
    struct student *next;

} student;
student *head, *temp, *curr;
void create()
{
    student *h=NULL;
    student s;
    int count=0;

    student *current;
    int id;
    char name[20];
    char adress[20];
    int batch;
    char par_name[20];
    int phone_no;
    printf("Enter Roll No: ");
    scanf("%d", &id);
    FILE *fp=fopen("data.txt", "ab+");
    while(fread(&s, sizeof(student), 1, fp)==1)
    {
        if(id==s.id)
        {
            count=1;
            printf("This Value is Already exist");
            break;
        }
    }
    if(count==0)
    {

        fflush(stdin);
        printf("Enter Name: ");
        gets(name);
        fflush(stdin);
        printf("Enter Adress: ");
        gets(adress);
        fflush(stdin);
        printf("Enter Parent's Name: ");
        gets(par_name);
        fflush(stdin);
        printf("Enter Batch No: ");
        scanf("%d", &batch);
        printf("Enter Phone No: ");
        scanf("%d", &phone_no);
        if(h==NULL)
        {
            head=(student *)malloc(sizeof(student));
            head->id=id;
            strcpy(head->name, name);
            strcpy(head->adress, adress);
            strcpy(head->par_name, par_name);
            head->batch=batch;
            head->phone_no=phone_no;
            head->next=NULL;
            //head=temp;
            //curr=temp;
        }
        else
        {
            while(h->next!=NULL)
            {
                h=h->next;
            }
            h->next=(student*)malloc(sizeof(student));
            h->next->id=id;
            strcpy(h->next->name,name);
            strcpy(h->next->adress,adress);
            strcpy(h->next->par_name,par_name);
            h->next->batch=batch;
            h->next->phone_no=phone_no;
            h->next->next=NULL;
        }
    }
    student *c=head;
    while(c!=NULL)
    {
        fwrite(c, sizeof(student), 1, fp);
        c=c->next;
    }
    fclose(fp);



}
void readData()
{
    student  s1;
    student *temp, *h=NULL;
    // h=(student* )malloc(sizeof(student));
    FILE *fp=fopen("data.txt", "r");
    while(fread(&s1, sizeof(student), 1, fp))
    {

        if(h==NULL)
        {
            h=(student *)malloc(sizeof(student));
            h->id=s1.id;
            strcpy(h->name, s1.name);
            strcpy(h->adress, s1.adress);
            strcpy(h->par_name, s1.par_name);
            h->batch=s1.batch;
            h->phone_no=s1.phone_no;
            h->next=NULL;
            head=h;



            //head=temp;
        }
        /* if(curr->id==s1.id){
             break;
         }*/
        else
        {
            // h=head;
            while(h->next!=NULL)
            {
                h=h->next;
            }
            temp=(student*)malloc(sizeof(student));

            temp->id=s1.id;
            strcpy(temp->name,s1.name);
            strcpy(temp->adress,s1.adress);
            strcpy(temp->par_name,s1.par_name);
            temp->batch=s1.batch;
            temp->phone_no=s1.phone_no;
            temp->next=NULL;
            h->next=temp;
        }
    }
    fclose(fp);
    main();
}
void display()
{
    // FILE *fp=fopen("data.txt", "ab+");
    /* student s;
     FILE *fp=fopen("data.txt", "ab+");
      while(fread(&s, sizeof(student), 1, fp)==1){

      }*/
    // readData();
    student *h=head;
    printf("    Id \t\t Name\t\t\t Adress\t\t Parents Name \t\tBatch \t\t Phone Number\n");
    int i;
    for(i=0; i<20; i++)
    {
        printf("------");
    }
    while(h!=NULL)
    {
        printf("    %d \t\t%s    \t\t%s    \t%-10s   \t\t%-10d    \t%-10d\n", h->id, h->name, h->adress, h->par_name, h->batch, h->phone_no);
        h=h->next;
    }
    main();
}

void searchFunction()
{

    student *h=head, s;
    int item;

    printf("Enter ID Which you want to search: ");
    scanf("%d", &item);
    FILE *fp=fopen("data.txt", "ab+");
    while(fread(&s, sizeof(student), 1, fp)==1)
    {
        if(item==s.id)
        {
            printf("\tId  \t  Name\t\t\t Adress\t\t Parents Name \t\tBatch \t\t Phone Number\n");
            printf("\t%d            %s\t\t\t %s\t\t %s \t\t\t %d\t\t %d", s.id, s.name, s.adress, s.par_name, s.batch, s.phone_no);
            break;

        }
    }
    main();


}
void modify()
{
    int item;
    student s1;
    char name[20];
    char adress[20];
    int batch;
    char par_name[20];
    int phone_no;
    printf("Enter ID Which you want to Modify: ");
    scanf("%d", &item);
    FILE *fp=fopen("data.txt", "rb+");
    while(fread(&s1, sizeof(student), 1, fp)==1)
    {

        if(s1.id==item)
        {
            printf("\nEnter Name: ");
            fflush(stdin);
            gets(s1.name);
            fflush(stdin);
            printf("\nEnter Adress: ");
            gets(s1.adress);
            fflush(stdin);
            printf("\nEnter Parent's Name: ");
            gets(s1.par_name);
            fflush(stdin);
            printf("\nEnter Batch No: ");
            scanf("%d", &s1.batch);
            printf("\nEnter Phone Number: ");
            scanf("%d", &s1.phone_no);
            //s.id=item;
            //strcpy(s.name, name);
            // strcpy(s.adress, adress);
            // strcpy(s.par_name, par_name);
            // s.batch= batch;
            // s.phone_no=phone_no;

            /*
            printf("\nEnter Name: ");
            fflush(stdin);
            gets(name);
            fflush(stdin);
            printf("\nEnter Adress: ");
            gets(adress);
            fflush(stdin);
            printf("\nEnter Parent's Name: ");
            gets(par_name);
            fflush(stdin);
            printf("\nEnter Batch No: ");
            scanf("%d", &batch);
            printf("\nEnter Phone Number: ");
            scanf("%d", &phone_no);
            s.id=item;
            strcpy(s.name, name);
            strcpy(s.adress, adress);
            strcpy(s.par_name, par_name);
            s.batch= batch;
            s.phone_no=phone_no;

            */
            fseek(fp,-sizeof(student), SEEK_CUR);
            fwrite(&s1,sizeof(student), 1, fp);
            break;
        }
        else
        {
            printf("This is Wrong ID!");
        }


    }
    fclose(fp);

}
void delete()
{
    student s;
    int i=0;
    FILE *fp = fopen("data.txt","rb");
    FILE *temp = fopen("temp.txt", "wb");
    printf("Enter Id which you want to delete: ");
    int data;
    scanf("%d", &data);
    while(fread(&s, sizeof(student), 1, fp) == 1)
    {


        if(data!=s.id)
        {
            fwrite(&s, sizeof(student), 1, temp);


        }

    }
    fclose(fp);
    fclose(temp);
    remove("data.txt");
    rename("temp.txt","data.txt");
    printf("record deleted\n");
    main();


}
void sort(){
int c=0,i,j;
student s1[50],s, t;
system("cls");
printf("\t\t\t\t\t<<== Sort by batch ==>\n\n");
printf("    Id \t\t Name\t\t\t Adress\t\t Parents Name \t\tBatch \t\t Phone Number\n");

    for(i=0; i<20; i++)
    {
        printf("------");
    }
FILE *fp=fopen("data.txt", "rb");
while(fread(&s, sizeof(student), 1,fp)==1){
    s1[c++]=s;
}
for(i=0; i<c-1; i++){
    for(j=i+1; j<c; j++){
        if(s1[i].batch>s1[j].batch){
                t=s1[i];
                s1[i]=s1[j];
                s1[j]=t;
        }
    }
}
for(i=0; i<c; i++){
    printf("%5d   \t%-10s    \t%-10s    \t%-10s   \t\t%-10d    \t%-10d\n", s1[i].id, s1[i].name, s1[i].adress, s1[i].par_name, s1[i].batch, s1[i].phone_no);
}

fclose(fp);
}


int main()
{
    int i,j,choice;
    printf("\n\nMenu\n\n");
    printf("1. Add Student\n");
    printf("2. Search Student\n");
    printf("3. Modify Student Record\n");
    printf("4. Display Student List\n");
    printf("5. Delete Student Record\n");
    printf("6. Read Data with File\n");
    printf("7. Data With Sorted\n");
    printf("8. Exit\n\n");

    printf("Enter your choice: \n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        create(head);
        main();
        break;
    case 2:
        // write_data(head);
        searchFunction();
        break;
    case 3:
        modify();
        main();
        break;
    case 4:
        system("cls");
        display(head);
        break;
    case 5:
        system("cls");
        delete();
        break;
    case 6:
        readData();
    case 7:
        sort();
        main();
    case 8:
        break;
    default:
        break;
    }


}


