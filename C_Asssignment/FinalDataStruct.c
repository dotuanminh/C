#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int menuSize; //size of Menu
int F[10000],foodSize ; // Array contains the time of ordering food
int D[10000],drinkSize; //Array contains the time of ordering drinks

// create struct for Food (BST)
typedef struct Node {
    char type[20];
    char name[30];
    int price;
    int duration;
    int ordered;
    struct Node* leftChild;
    struct Node* rightChild;
}Node;
//intitialize the root
Node* root;

//make node
Node* makeNode(char* type, char* name, int price, int duration){
    Node* q = (Node*)malloc(sizeof(Node));
    strcpy(q->type, type);
    strcpy(q->name, name);
    q->price = price;
    q->duration= duration;
    q->ordered = 0;
    q->leftChild = q->rightChild = NULL;
    return q;
}
//insert node
Node* insert(Node* r, char* type, char* name, int price, int duration){
    if(r == NULL) {
        return makeNode(type, name, price, duration);
    }
    int c = strcmp(r->name, name);
    if( c == 0){
        menuSize--; //if found then menu size can not increase
        return r;
    }else if(c<0){
        r->rightChild = insert(r->rightChild, type, name, price, duration);
        return r;
    }else if(c>0){
        r->leftChild = insert(r->leftChild, type, name, price, duration);
        return r;
    }
}

//find node
Node* find(Node* r, char* name){
    if(r == NULL) return NULL;
    int c = strcmp(r->name, name);
    if(c == 0) return r;
    if(c<0) return find(r->rightChild, name);
    return find(r->leftChild, name);
}

//max function
int Max(int *a, int *b)
{
  if(a>b) return a;
  return b;
}

//count the number of unfinished order food and drinks
int inProgressServe(int hour, int min){
    int cnt = 0; //the number of unfinished order food and drinks
    min+= hour*60;
    //calculate F[i],D[i] used
    for(int i = 0; i< 10000; ++i){
        if(min< F[i]) {
            cnt++;
        }
    }
    for(int i = 0; i< 10000; ++i){
        if(min< D[i]){
            cnt++;
        }
    }
    return cnt;
}

//function calculates the time needed to serve food
int order(int hour, int min, char* order1, char* order2){
    min+=hour*60; //change to minute to compare
    Node* p = find(root, order1);
    (p->ordered)++;
    if(strcmp(p->type, "FOOD") == 0){
        F[foodSize] = Max(min,F[foodSize-1])+ p->duration; //add new food order to FoodArray
        foodSize++;
    }
    if(strcmp(p->type, "DRINK") == 0){
        D[drinkSize] = Max(min,D[drinkSize -1])+ p->duration; //add new drink order to DrinkArray
        drinkSize++;
    }
    Node* q = find(root, order2);
    (q->ordered)++;
    if(strcmp(q->type, "FOOD") == 0) {
        F[foodSize] = Max(min,F[foodSize-1])+ q->duration; //add new food order to FoodArray
        foodSize++;
    }
    if(strcmp(q->type, "DRINK") == 0) {
        D[drinkSize] = Max(min,D[drinkSize -1])+ q->duration; //add new drink order to DrinkArray
        drinkSize++;
    }
    // calculate the time needed
    if(strcmp(p->type, q->type) == 1){
        return (Max(F[foodSize-1],D[drinkSize-1])-min) ;
    }else {
        if(strcmp(p->type, "FOOD") == 0) return F[foodSize-1] - min;
        return D[drinkSize-1] - min;
    }
}

void solve(){
    char str[10];
    root = NULL;
    menuSize = 0;
    foodSize = 1;
    drinkSize = 1;
    for(int i = 0; i<10000; i++){
        F[i] = D[i] = 0;
    }
    while(1){
        scanf("%s", str);
        if(strcmp(str, "***")==0) break;
        if(strcmp(str, "$ADD") == 0){
            char type[20];
            char name[30];
            int price;
            int duration;
            scanf("%s %s %d %d", type, name, &price, &duration);
            root = insert(root, type, name, price, duration);
            menuSize++;
            printf("%d\n", menuSize);
        }else if(strcmp(str, "$ORDER") == 0){
            int hour, min;
            char order1[30];
            char order2[30];
            scanf("%d %d %s %s", &hour, &min, order1, order2);
            printf("%d\n", order(hour, min, order1, order2));
        }else if(strcmp(str, "$WAIT") == 0) {
            int hour;
            int min;
            scanf("%d %d", &hour, &min);
            printf("%d\n", inProgressServe(hour, min));
        }else if(strcmp(str, "$PRICE") == 0){
            char name[30];
            scanf("%s", name);
            Node* res = find(root, name);
            printf("%d\n", res->price);
        }else if(strcmp(str, "$COUNT") == 0){
            char name[30];
            scanf("%s", name);
            Node* res= find(root, name);
            printf("%d\n", res->ordered);
        }
    }
}
int main(){
    solve();
    return 0;
}
