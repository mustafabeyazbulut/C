#include<stdio.h>
#include<stdlib.h>

struct heap {
	int data;
    	struct heap *left, *right;
};

int heapify(struct heap* kok) {
    struct heap *temp = NULL;
	if (kok)
    {
        if (!heapify(kok->left))               return 0;

        if (temp != NULL && kok->data <= temp->data)    return 0;

        temp = kok;

        return heapify(kok->right);
    }

    return 1;

}

int main(){

	struct heap* h1 = NULL;;
	struct heap* h2 = NULL;
	struct heap* h3 = NULL;
	struct heap* h4 = NULL;

	h1 = (struct heap*)malloc(sizeof(struct heap));
	h2 = (struct heap*)malloc(sizeof(struct heap));
	h3 = (struct heap*)malloc(sizeof(struct heap));
	h4 = (struct heap*)malloc(sizeof(struct heap));

	h1->data = 4;
	h1->left = h2;
	h1->right = h3;

	h2->data = 2;
	h2->left = h4;
	h2->right = NULL;

	h3->data = 3;
	h3->left = NULL;
	h3->right = NULL;

	h4->data = 1;
	h4->left = NULL;
	h4->right = NULL;

	printf("%d \n", heapify(h1));

	return 0;
}
