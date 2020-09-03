#include<stdio.h>
void newContact();
void deleteContact();
void showContactInfo();
void showAllContact();
void modContact();



void main(){
int instruction=10;
while(instruction!=0){
printf("\n1-add New Contact\n2-delete contact\n3-show contact info\n4-show all contact\n0-exit\n ");
scanf("%d",&instruction);
if(instruction==1){
    newContact();
}
else if(instruction==2){
            deleteContact();
}
else if(instruction==3){
    showContactInfo();
}
else if(instruction==4){
    showAllContact();
}
}
}


void showContactInfo(){
    char nom[20];
    char num[20];
    char desiredName[20];
    int n;
    n=0;
    FILE *f;
    f=fopen("contacts.txt","r");
    printf("tap your contact name \n");
    scanf("%d",&desiredName);
    while(fscanf(f,"%s %s",nom,num)!=EOF){
        if(strcmp(nom,desiredName)==0)
        {
            printf("\n nom- %s\n",nom);
            printf("\n No°: %s\n",num);
            n=1;
        }
    }
    if(n==0){
        printf("contact not found");
    }
    return;
    }


void showAllContact(){
    FILE *f;
    f=fopen("contacts.txt","r");
    char nom[20],num[20];
    while(fscanf(f,"%s %s",nom,num)!=EOF)
    {
        printf("\n nom:  %s",nom);
    }
    fclose(f);
return;
}

void modContact(){
 FILE *f,*f1;
    f=fopen("contacts.txt","r+");
    f1=fopen("ex.txt","w");
    printf("\n taper le nom  ");
        char nom[20];
    scanf("%s",&nom);
    char nom1[20],num[20];
    while(fscanf(f,"%s %s",nom1,num)!=EOF)
    {
        if(strcmp(nom,nom1)==0)
        {
            printf("\n new number");
            char num1[20];
            scanf("%s",num1);
            fprintf(f1,"%s %s\n",nom1,num1);
            continue;
        }
        fprintf(f1,"%s %s\n",nom1,num);
    }
    fclose(f);
    fclose(f1);
    f=fopen("contacts.txt","w");
    f1=fopen("ex.txt","r");
    while(fscanf(f1,"%s %s",nom1,num)!=EOF)
    {

        fprintf(f,"%s %s\n",nom1,num);
    }
    fclose(f);
    fclose(f1);
    remove("ex.txt");
    return;

}


void deleteContact(){
   FILE *f,*f1;
    f=fopen("contacts.txt","r");
    f1=fopen("ex.txt","w");
    printf("\n name of contact  ");
    char nom[20],num[20],nom1[20];
    scanf("%s",nom);
    while(fscanf(f,"%s %s",nom1,num)!=EOF)
    {
        if(strcmp(nom,nom1)==0){
                printf("deleted");
        continue;
        }
                fprintf(f1,"%s %s\n",nom1,num);
    }
    fclose(f);
    fclose(f1);
    f=fopen("contacts.txt","w");
    f1=fopen("ex.txt","r");
    while(fscanf(f1,"%s %s",nom1,num)!=EOF)
    {
        fprintf(f,"%s %s\n",nom1,num);
    }
    fclose(f);
    fclose(f1);
    remove("ex.txt");
}
void newContact(){
    char nom[20];
        //num de 20 khater kif 3malt num[8] maysobech el nom
    char num[20];
FILE *contacts;
contacts=fopen("contacts.txt","a+");
printf("donner le nom de niveau contact\n");
scanf("%s",&nom);
printf("donner sa numero\n");
scanf("%s",&num);
fprintf(contacts,"%s %s\n",nom,num);
fclose(contacts);
return;
}
