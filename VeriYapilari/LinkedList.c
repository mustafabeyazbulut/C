// A simple C program for traversal of a linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// This function prints contents of linked list starting from
// the given node
void printList(struct Node* n)
{
    while (n != NULL) {
        printf(" %d ", n->data);
        n = n->next;
    }
}
void ilk_ve_son_dugumleri_sil(struct Node **liste_basi) {

        struct Node* temp=NULL;
        struct Node* once = *liste_basi;


        temp = once->next;
        free(once);
        *liste_basi = temp;

	while(temp->next->next != NULL){

		temp = temp->next;
	}
	free(temp->next);
	temp->next = NULL;

}


int main()
{
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    struct Node* fourth = NULL;
    struct Node* fifth = NULL;

    // allocate 3 nodes in the heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    fifth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1; // assign data in first node
    head->next = second; // Link first node with second

    second->data = 2; // assign data to second node
    second->next = third;

    third->data = 3; // assign data to third node
    third->next = fourth;

    fourth->data = 4;
    fourth->next= fifth;

    fifth->data = 5;
    fifth->next =  NULL;
    printList(head);
    ilk_ve_son_dugumleri_sil(&head);
    printf("\n");
    printList(head);
    printf("\n");

    return 0;
}
