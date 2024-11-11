#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node * KokDugumOlustur(int veri)
{
    struct node * root = (struct node*)malloc(sizeof(struct node));

    root ->data = veri;
    root ->left = NULL;
    root ->right = NULL;

    return root;
}

struct node * ElemanEkle(struct node * root,int veri)
{
    if(root==NULL)
    {
        root = KokDugumOlustur(veri);
    }
    else
    {
        if(veri < root->data)
        {
            root->left = ElemanEkle(root->left,veri);
        }
        else
        {
            root->right = ElemanEkle(root->right,veri);
        }
    }
    return root;
}

int Find(struct node* root, int aranan)
{
    if (root == NULL)
    {
        return -1;
    }
    if (aranan == root->data)
    {
        return 1;
    }
    else if (aranan < root->data)
    {
        return Find(root->left, aranan);
    }
    else
    {
        return Find(root->right, aranan);
    }
}

void PreOrder(struct node * root)
{
    if(root != NULL)
    {
        printf("%d",root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void PostOrder(struct node * root)
{
    if(root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d",root->data);
    }
}

void InOrder(struct node * root)
{
    if(root != NULL)
    {
        InOrder(root->left);
        printf("%d",root->data);
        InOrder(root->right);
    }
}


int Max(struct node * root)
{
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root->data;
}

int Min(struct node * root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root->data;
}

struct node* FindMin(struct node* root) {
    while (root->left != NULL) 
    {
        root = root->left;
    }
    return root;
}

struct node* Delete(struct node* root, int data) {
    if (root == NULL)
    {
        return root;
    }
    else if (data < root->data) 
    {
        root->left = Delete(root->left, data);
    }
    else if (data > root->data) 
    {
        root->right = Delete(root->right, data);
    }
    else {
        // Case 1: No Child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
        // Case 2: One Child
        else if (root->left == NULL) {
            struct node* temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL) {
            struct node* temp = root;
            root = root->left;
            free(temp);
        }
        // Case 3: Two Children
        else {
            struct node* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

int main()
{
    struct node * eleman = NULL;
    int sayi;
    int i=0;

    while(i<7)
    {
        printf("Bir sayi girin \n");
        scanf("%d",sayi);
        eleman = ElemanEkle(eleman,sayi);
        i++;
    }
    return 0;
}