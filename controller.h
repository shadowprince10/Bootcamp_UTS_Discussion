#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../model/model.h"

node *create_node (character c)
{
    node *temp = (node*)malloc(sizeof(node));
    strcpy(temp -> c.name, c.name);
    strcpy(temp -> c.job, c.job);
    temp -> c.level = c.level;
    temp -> c.damage = c.damage;
    return temp;
}

node *insert_node(node *root, character c)
{
    if(!root)
    {
        return create_node(c);
    }

    else if (c.damage < root -> c.damage)
    {
        root -> left = insert_node(root -> left, c);
    }

    else if (c.damage > root -> c.damage)
    {
        root -> right = insert_node(root -> right, c);
    }

    return root;
}

void preorder(node *root) // print dulu
{
    printf(" %d", root -> c.damage);
    preorder(root -> left);
    preorder(root -> right);
}

void inorder(node *root) // print di tengah
{
    inorder(root -> left);
    printf(" %d", root -> c.damage);
    inorder(root -> right);
}

void postorder(node *root) // print terakhir
{
    postorder(root -> left);
    postorder(root -> right);
    printf(" %d", root -> c.damage);   
}

void print_damage(node *root)
{
    printf("Preorder: ");
    preorder(root);
    puts("");
    printf("Inorder: ");
    inorder(root);
    puts("");
    printf("Postorder: ");
    postorder(root);
}

void print_all(node *root)
{
    if (!root)
    {
        printf("> %s | %s | lvl. %d | damage: %d\n", root -> c.name, root -> c.job, root -> c.level);
        print_all(root -> left);
        print_all(root -> right);
    }
}
// Di Print Damage, kita hanya print atribut damage
// Preorder untuk print 

void pop_all(node *root)
{
    if(root)
    {
        pop_all(root -> left);
        pop_all(root -> right);
        free(root);
        root = NULL;
    }
    // bermaksud untuk mengunjungi semua node dan untuk tiap node, dialokasikan memori atau dibuang alias difree root. Setelah itu, kita NULL-kan root-nya
}

// AVL Tree -- baru ada delete function
// Binary Search Tree -- Insert, Search, Print, Pop All
// Soal Teori dan Soal Kuis (200 Menit)
// Offline -- 100 menit