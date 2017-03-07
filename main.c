#include <stdio.h>
#include <binaryTree.h>
int main()
{
    greeting();
}

void greeting(){
    int responce;
    char name[20];
    printf("------------------------------------------------\n");
    printf("To add a name press 1.\n");
    printf("To delete a name press 2.\n");
    printf("To print a list of all the names press 3.\n");
    printf("Your responce: ");
    
    scanf("%d",&responce);
    
    //invalid responce
    if(responce!=1&&responce!=2&&responce!=3){
        printf("Invalid responce.");
    }
    //add a name
    if(responce==1){
        
        printf("Please enter the name you would like to add(max 20 characters): ");
        scanf("%s",name);
        nameList=ins(nameList,name);
        
        anythingElse();
        
    }
    //delete a name
    if(responce==2){
        char name[20];
        printf("Please enter the name that you would like to delete(max of 20 characters): ");
        scanf("%s",name);
        del(nameList,name);
        anythingElse();
        
    }
    //print the list of names to the console as well as to a text file
    if(responce==3){
        printNames(nameList);
        anythingElse();
    }
}

void anythingElse(){
    
    int nextResponce;
    printf("Is there anything else you would like to do?(1=yes 2=no): ");
    scanf("%d",&nextResponce);
    if(nextResponce==1){
            greeting();
        }
        if(nextResponce==2){
            printf("Goodbye.");
        }
        if(nextResponce!=1&&nextResponce!=2){
            printf("Invalid responce.");
        }
}