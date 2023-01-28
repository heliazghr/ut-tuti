#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct post post;        
struct post{
    char *username;
    int post_id;
    int like;
    char* post;
    post *next;
};

typedef struct user user;               
struct user{
    char *username;
    char *password;
    user *next;
};

typedef struct like like;
struct like{
    char *username;
    int post_id;
    like *next;
};

user* find_user(user* head,char* username){
    if(head==NULL)
    return NULL;
    user* currentuser=(user*)malloc(sizeof(user));
    currentuser=(head)->next;
    while(currentuser!=NULL){
        if(strcmp(currentuser->username,username)==0){
            return currentuser;
        }
        currentuser=currentuser->next;
    }
    return NULL;
}

int command(char* commnd){
    if(strcmp(commnd,"signup")==0)
        return 1;
}

int signup(char* username,char* password, user* head){    
    if(find_user(head,username)!=NULL)
        return 1;
    user* newuser=(user*)malloc(sizeof(user));
    newuser->username=(char*)malloc(50);
    newuser->password=(char*)malloc(100);
    strcpy(newuser->username,username);
    strcpy(newuser->password,password);
    newuser->next=NULL;
    user* currentuser=(user*)malloc(sizeof(user)); 
    currentuser=head;
    while(currentuser->next!=NULL)
        currentuser=currentuser->next;
    currentuser->next=newuser;
    return 0;
    }

char* input(char* input){
  int i=0;
  char temp='-';
  while(1){
    temp=getchar();
    if(temp=="\n" || temp==" ")
    break;
    *(input+i)=temp;
    i++;
    input=(char*)realloc(input,i+1);
  }
  *(input+i)="\0";
  return input;
}

int main(){
    user* head=(user*)malloc(sizeof(user));
    user* currentuser=(user*)malloc(sizeof(user));
    currentuser->next=NULL;
    currentuser=NULL;
    head->username=(char*)malloc(1);
    head->password=(char*)malloc(1);
    strcpy(head->username,"-");
    strcpy(head->password,"-");
    while(1){
    char* commnd=(char*)malloc(1);
    printf("choose signup or login:");
    commnd=input(commnd);
    int command_id=command(commnd);
        free(commnd);
        if(command_id==1){
            char* username=(char*)malloc(1);
            printf("Enter your usrename:");
            username=input(username);
            char* password=(char*)malloc(1);
            printf("Enter your password:");
            password=input(password);
            int id_temp=signup(username,password,head);
            if(id_temp==1)
                printf("username already exists!\n");
            else
                printf("user %s signed up successfully =)\n",username);
            free(username);
        }
    }
}