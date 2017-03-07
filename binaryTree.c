#include <binaryTree.h>

//Print the names to the console as well as save them to a file starting from the far left node
void printNames(treenode *key){
    if(key==NULL){
        return;
    }
    FILE *f=fopen("C:\\Users\\James\\Desktop\\ListOfNames\\names.txt","a");
    
    printNames(key->left);
    printf("%s\n",key->name);
    rewind(f);
    fprintf(f,key->name);
    fprintf(f,"\n");
    fclose(f);
    printNames(key->right);
}


//inserts into the tree in order from a-z 
treenode * ins(treenode *key, char newname[]){
    //if the inserted name is the root
    if(key==NULL){
        treenode *tempkey;
        tempkey=(treenode*)malloc(sizeof(treenode));
        //replace the name of the key with new name
        memcpy(tempkey->name,newname,sizeof(newname));
   
        tempkey->left=tempkey->right=NULL;
        
        return tempkey;
    }
    //if the new name should be before the name of the current node
    if(strcmp(newname,key->name)<0){
        key->left=ins(key->left,newname);
    }
    
    //if the new name should be after the name of the current node 
    if(strcmp(newname,key->name)>0){
        key->right=ins(key->right,newname);
    }
    
     return key;
}

//deleting a name from the list
treenode * del(treenode *key, char newname[]){
    treenode *tempkey;
    //if the given name is not on the list
    if(key==NULL){
        printf("Name not found.\n");
    }
    //if the given name comes before the the name of the current node
    else if(strcmp(newname,key->name)<0){
        key->left=del(key->left,newname);
    }
    //if the given name comes after the the name of the current node
    else if(strcmp(newname,key->name)>0){
        key->right=del(key->right,newname);
    }
    else{
        //replace the deleted node with a child node
        //since the left will always be before the right, I have chosen to just select the left node
        if(key->right && key->left){
            tempkey=key->left;
            memcpy(key->name,tempkey->name,sizeof(tempkey->name));
            key->left=del(key->left,tempkey->name);
        }
        else{
            //if there is only one child node
            tempkey=key;
            if(key->left==NULL){
                key=key->right;
            }
            else if(key->right==NULL){
                key=key->left;
            }
            free(tempkey);
        }
    }
    return key;
}

