#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct treenode{
    char name[20];
    struct treenode *left;
    struct treenode *right;
}treenode;
treenode *nameList;
void printNames(treenode *key);
treenode * ins(treenode *key,char newname[]);
treenode * del(treenode *key,char newname[]);
