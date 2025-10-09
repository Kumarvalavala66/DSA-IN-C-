#include<stdio.h>
#include<stdlib.h>


 struct Node{
    struct Node*left;
    int data;
    struct Node*right;
 };

struct Node* create_node(int data){
    struct Node*new_node ;
    new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node -> left = NULL; 
    new_node -> right = NULL; 
    new_node -> data = data;
    return new_node; 

}


struct Node* insert_new(struct Node*root,int data){
    if (root == NULL){
        struct Node* new_node = create_node(data);
        return new_node;
    }
    struct Node* ptr = root;
    if(data < ptr -> data ){
       root -> left=  insert_new(ptr->left,data);
    }
    if(data > ptr -> data ){
       root -> right =  insert_new(ptr->right,data);
    }
    return root;
}
void preOrder(struct Node*root){
    if(root != NULL){
        printf("%d\n",root -> data);
        preOrder(root -> left);
        preOrder(root -> right);
    }
}


void inOrder(struct Node*root){
    if(root != NULL){
        inOrder(root -> left);
        printf("%d\n",root -> data);
        inOrder(root -> right);
    }
}







void postOrder(struct Node*root){
    if(root != NULL){
        postOrder(root -> left);
        postOrder(root -> right);
        printf("%d \n ",root->data);
    }
}




 int main(){
    struct Node*root;
    root = (struct Node*)malloc(sizeof(struct Node));
    root ->left= NULL;
    root ->right= NULL;
    root ->data= 123;
    root = insert_new(root,134); 
    root = insert_new(root,12);    
    root = insert_new(root,23); 
    root = insert_new(root,34);  
    root = insert_new(root,234); 
    root = insert_new(root,4);    
                                             

    inOrder(root);
    printf("\n \n");
    preOrder(root);
    printf("\n \n"); 
    postOrder(root);

    return 0;


 }
