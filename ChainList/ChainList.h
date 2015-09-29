
typedef struct{
    char key[15];
    char name[20];
    int age;
}DATA;

typedef struct Node{
    DATA data;
    struct Node *next;
}ChainListType;


ChainListType *ChainListAddEnd(ChainListType *head, DATA data);

ChainListType *ChainListAddFirst(ChainListType *head, DATA data);

ChainListType *ChainListFind(ChainListType *head, char key[]);

ChainListType *ChainListInsert(ChainListType *head, DATA data, char key[]);

int ChainListDelete(ChainListType *head, char key[]);

int ChainListLength(ChainListType *head);


ChainListType *ChainListInit(ChainListType *head);

void ChainListTraverse(ChainListType *head);
