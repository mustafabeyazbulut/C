#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct cell {
    char *anahtar;
    struct cell *next;
};

struct table_node{
    int count;
    struct cell *header;
};

struct hash_tablosu{
    struct table_node *tablo_basi;
    int tablo_uzunlugu;
    int multiplier;
};

unsigned int hash(char *s, int multiplier, int table_size){
    int i=0;
    unsigned int value =0;
    while(s[i] != '\0'){
        value=(s[i]+multiplier*value) % table_size;
        i++;
    }
    return value;
}

void initialize_hash_table(struct hash_tablosu **hash_table,int multiplier, int table_size){
    int i;
    *hash_table=(struct hash_tablosu*)malloc(sizeof(struct hash_tablosu));
   if(*hash_table==NULL){
       printf(" Hash tablosu icin yer ayrilamnadi... Hata!!!");
       exit(1);
   }
    (*hash_table)->tablo_basi= (struct table_node *)malloc(table_size*sizeof(struct table_node));
    if((*hash_table)->tablo_basi==NULL){
       printf(" Hash tablosu icin yer ayrilamnadi... Hata!!!");
       exit(1);
    }
    (*hash_table)->tablo_basi->header=(struct cell *)malloc(table_size*sizeof(struct cell));
    if((*hash_table)->tablo_basi->header==NULL){
       printf(" Hash tablosu icin yer ayrilamnadi... Hata!!!");
       exit(1);
    }
    (*hash_table)->tablo_uzunlugu= table_size;
    (*hash_table)->multiplier= multiplier;

    for(i=0; i<table_size; i++){
        ((*hash_table)->tablo_basi+i)->count = 0;
        ((*hash_table)->tablo_basi+i)->header = NULL;
    }
}

void push (struct cell **liste_basi, char *new_data) {
         /* allocate node */
    struct cell* new_node = (struct cell*)malloc(sizeof(struct cell));
    struct cell* temp = (struct cell*)malloc(sizeof(struct cell));
    new_node->anahtar = new_data;
    new_node->next = NULL;

    if(*liste_basi==NULL){
        *liste_basi=new_node;
    }
    else {
        temp=*liste_basi;
        while(temp->next!=NULL){

            temp=temp->next;
        }
        temp->next=new_node;
    }
    }

void push1(struct cell** head_ref, char *new_data)
{

    /* allocate node */
    struct cell* new_node = (struct cell*)malloc(sizeof(struct cell));

    /* put in the data  */
    new_node->anahtar = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

void print_list(struct cell *l){
    if(l!=NULL){
        printf("%s ", l->anahtar);
        print_list(l->next);
    }
}
void print_hash_table(struct hash_tablosu *hash_table){
    if(hash_table){
        int index;
        printf("----- HASH TABLOSU -----\n");
        for(index=0; index<hash_table->tablo_uzunlugu; index++){
            printf("%5d : (%2d) ",index,(hash_table->tablo_basi +index)->count);
          //  printf("%5d : (%2d) ",index,hash_table->tablo_basi[index].counter);
            print_list((hash_table->tablo_basi+index)->header);
            printf("\n");
        }
    }
    else printf("Hash Tablosu Bos ...\n");

}

void liste_yok_et(struct cell **liste_basi){
    struct cell *onceki;
    while(*liste_basi){
        onceki=*liste_basi;
        *liste_basi=(*liste_basi)->next;
        free(onceki->anahtar);
        free(onceki);
    }
}
void cell_kopyala_2(struct cell **liste_basi){
	struct cell *kopya;
	struct cell *yeni;
	kopya = *liste_basi;
	yeni = kopya;
	free(liste_basi);
	free(kopya);
	while(yeni!=NULL){
		printf("%s \n",yeni->anahtar);
		yeni=yeni->next;
	}
}
int insert(char *anahtar, struct cell **l){
    if(*l==NULL){
        *l=(struct cell*)malloc(sizeof(struct cell));
        (*l)->anahtar=(char*)malloc((strlen(anahtar)+1)*sizeof(char));
        strcpy((*l)->anahtar,anahtar);
        (*l)->next=NULL;
        return 1;
    }
    else if(strcmp(anahtar,(*l)->anahtar))
        return insert(anahtar, &((*l)->next));
    else return 0;
}
void listeyi_hash_tablosuna_donusturme1(struct hash_tablosu *htable, struct cell **liste_basi){

    while(*liste_basi){
    int hash_index = hash((*liste_basi)->anahtar, htable->multiplier,htable->tablo_uzunlugu);
    if(insert((*liste_basi)->anahtar,&((htable->tablo_basi +hash_index)->header)))
     (htable->tablo_basi +hash_index)->count++;

     (*liste_basi)=(*liste_basi)->next;
    }

}

void listeyi_hash_tablosuna_donusturme2(struct hash_tablosu *htable, struct cell **liste_basi){

    while((*liste_basi) != NULL){
        int hash_index = hash((*liste_basi)->anahtar, htable->multiplier, htable->tablo_uzunlugu);
        struct cell *temp= (*liste_basi)->next;
        (*liste_basi)->next = NULL;

        if((htable->tablo_basi+hash_index)->header == NULL){
            (htable->tablo_basi+hash_index)->header = *liste_basi;
            (htable->tablo_basi+hash_index)->count++;
        }
        else{
            struct cell *iter = NULL;
            iter = (htable->tablo_basi+hash_index)->header;

            while(iter!=NULL){
                if(strcmp((*liste_basi)->anahtar,iter->anahtar)) {
                    if(iter->next!=NULL) {
                        iter=iter->next;
                    }
                    else{
                        iter->next = *liste_basi;
                        (htable->tablo_basi+hash_index)->count++;
                    }
                }
                else{
                    break;
                }
            }
        }
        *liste_basi = temp;
    }
}
void listeyi_hash_tablosuna_donusturme3(struct hash_tablosu *htable, struct cell **liste_basi){

       while(*liste_basi!=NULL){
            int hash_index = hash((*liste_basi)->anahtar, htable->multiplier,htable->tablo_uzunlugu);
            struct table_node * setHeader=(htable->tablo_basi+hash_index);
            struct cell *setCell=(*liste_basi)->next;
            (*liste_basi)->next=NULL;
                    while(1){
                                if(setHeader->header==NULL){
                                    setHeader->header=*liste_basi;
                                    (htable->tablo_basi+hash_index)->count++;
                                    break;
                                }else if(setHeader->header->anahtar!=(*liste_basi)->anahtar     ) {
                                    setHeader=setHeader->header;
                                    }
                                else break;
                              }
            *liste_basi=(*liste_basi)->next;
            *liste_basi=setCell;
        }


}




void listeyi_hash_tablosuna_donusturme(struct hash_tablosu *htable, struct cell **liste_basi){

    while(*liste_basi !=NULL){
        int hash_index = hash((*liste_basi)->anahtar, htable->multiplier,htable->tablo_uzunlugu);
		struct table_node *headertemp =(htable->tablo_basi+hash_index);
        struct cell *celltemp=(*liste_basi)->next;
        (*liste_basi)->next=NULL;

		while(headertemp->header!=NULL && headertemp->header->anahtar!=(*liste_basi)->anahtar)
		headertemp=headertemp->header;

        if(headertemp->header==NULL  ){
                (htable->tablo_basi+hash_index)->count++;
                headertemp->header=*liste_basi;
        }
		*liste_basi=celltemp;
    }
}
void listeyeye_donusturme(struct hash_tablosu *htable, struct cell **liste_basi){
	int i = 0;
	struct cell *liste_sonu;

	for(i = 0; i < htable->tablo_uzunlugu; i++){
		if((htable->tablo_basi +i)->header != NULL){
			*liste_basi = (htable->tablo_basi +i)->header;
			(htable->tablo_basi +i)->header = (*liste_basi)->next;
			liste_sonu = *liste_basi;
			break;
		}
	}
for(i = 0; i < htable->tablo_uzunlugu; i++){
		if((htable->tablo_basi +i)->header != NULL){
			while((htable->tablo_basi +i)->header != NULL){
				liste_sonu->next = (htable->tablo_basi +i)->header;
				liste_sonu = liste_sonu->next;
				(htable->tablo_basi +i)->header = liste_sonu->next;
			}
		}
		(htable->tablo_basi+i)->count=NULL;

	}

}

void listeyeye_donusturme1(struct hash_tablosu *htable, struct cell **liste_basi){

    struct hash_tablosu *hash_temp;
    struct cell *cell_temp=*liste_basi;
    for(int i = 0; i < htable->tablo_uzunlugu; i++){
        while((htable->tablo_basi +i)->header != NULL){
            hash_temp=(htable->tablo_basi +i)->header->next;

            if(*liste_basi==NULL){
                    *liste_basi=(htable->tablo_basi +i)->header;
                    cell_temp=*liste_basi;
            }
            else {
                    cell_temp->next=(htable->tablo_basi +i)->header;
                    cell_temp=cell_temp->next;
            }
            (htable->tablo_basi +i)->header->next=NULL;
            (htable->tablo_basi +i)->header=hash_temp;
        }
        (htable->tablo_basi+i)->count=NULL;
    }

}


int main()
{
    struct hash_tablosu *htable=NULL;
    initialize_hash_table(&htable,3,5);

    struct cell *cello=NULL;
    push(&cello,"kadayif");
    push(&cello,"Trabzonspor");
    push(&cello,"kadayif");
    push(&cello,"gundogdu");
    push(&cello,"besiktas");
    push(&cello,"baklava");
    push(&cello,"dembaba");
    push(&cello,"cardoza");
    push(&cello,"bakiray");
    push(&cello,"beklava");
    push(&cello,"beklavaa");
    push(&cello,"beklavas");
    push(&cello,"beklavasd");
    push(&cello,"Faruk");
   // print_list(cello);
   // printf("\n \n");

        //liste_yok_et(&cello);
    print_list(cello);
    printf("\n");

    print_hash_table(htable);
    printf("\n");

    //hash_tablo_olustur(htable,&cello);
    listeyi_hash_tablosuna_donusturme(htable,&cello);
    print_hash_table(htable);
    printf("\n");

    listeyeye_donusturme1(htable,&cello);
    print_list(cello);
    printf("\n");

    print_hash_table(htable);
    printf("\n");

    print_list(cello);
    printf("\n");


}
