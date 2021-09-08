#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 256

typedef struct StudentNode{
	char id[10];
	char name[50];
	double toan, ly, hoa;
	struct StudentNode *next;
}StudentNode;

StudentNode *first;
StudentNode *last;

StudentNode *makeStudentNode(char *id, char *name, double toan, double ly, double hoa){
	StudentNode *node = (StudentNode*)malloc(sizeof(StudentNode));
	strcpy(node->name, name);
	strcpy(node->id, id);
	node->toan = toan;
	node->ly = ly;
	node->hoa = hoa;
	node->next = NULL;
	return node;
}

void init(){
	first = NULL;
	last = NULL;
}

void processFind(){
	char id[10];
	printf("Enter id: ");
	scanf("%s",id);
	StudentNode *p;
	for(p=first; p!=NULL; p =p->next){
		if(strcmp(p->id, id)==0){
			break;
		}
	}
	if(p==NULL)	printf("Not found\n");
	else{
		printf("Found!\n");
		printf("ID: %s\tName: %s\tToan: %.2f\tLy: %.2f\tHoa: %.2f\n\n", p->id, p->name, p->toan, p->ly, p->hoa);
	}

}

void insertLast(char *id, char *name, double toan, double ly, double hoa){
	StudentNode* StudentNode = makeStudentNode(id, name,toan,ly,hoa);
    if((first == NULL) && (last == NULL))
      	first = last = StudentNode;
    else{
        last->next = StudentNode;
		last = StudentNode;
    }
}

void load(char *file){
	char name[50];
  	char id[10];
  	double toan, ly, hoa;
	FILE *f = fopen(file,"r");
	if(f == NULL){
		printf("File couldn't be opened\n");
		return;
	}else{
	    int num;
	    fscanf(f,"%d", &num);
		while(!feof(f)){
		    fscanf(f,"%s\n",id);
		    fgets(name,50,f);
		    name[strcspn(name, "\n")] = 0;
		    fscanf(f,"%lf %lf %lf\n",&toan,&ly,&hoa);
		    insertLast(id,name,toan,ly,hoa);
		}
	}
	fclose(f);
	return;
}

void processPrint(){
	StudentNode* p= first;
	if(p == NULL)	printf("List is empty\n");
	else{
	printf("%-10s%-20s%-10s%-10s%-10s\n","ID","Name","Toan","Ly","Hoa");
	printf("-----------------------------------------------------------\n");
		for(p = first; p != NULL ; p= p->next)
			printf("%s\t%-30s%.2f\t%.2f\t%.2f\n", p->id, p->name, p->toan, p->ly, p->hoa);
		printf("\n");
	}
	printf("------------------------------------------------------------\n");
}

void processInsert(){
	char name[50], id[10];
	double toan, ly, hoa;

	printf("Enter name: ");
    scanf("%s", &name);
    printf("Enter ID: ");
    scanf("%s", &id);
    printf("Enter grade (math, physics, chemistry): ");
    scanf("%lf %lf %lf",&toan,&ly,&hoa);
    for(StudentNode* p= first; p!=NULL; p=p-> next){
        if( strcmp(p->id,id)==0 ) {
            printf("ID already exist, please reenter...");
            printf("Enter name: ");
            scanf("%s", &name);
            printf("Enter ID: ");
            scanf("%s", &id);
            printf("Enter grade (math, physics, chemistry): ");
            scanf("%lf %lf %lf",&toan,&ly,&hoa);
        }
    }
    insertLast(id, name,toan,ly,hoa);

}

void save(char *file){
	FILE *f = fopen(file, "w+");
	if(f==NULL){
		perror("File not found\n");
	}else{
		StudentNode *p;
		for(p = first; p!=NULL; p=p->next){
			fprintf(f,"%s\n%s\n%f %f %f\n",p->id, p->name,p->toan, p->ly, p->hoa);
			if(p->next == NULL)	fprintf(f,"\n");
		}
	}
	fclose(f);
}

void removeStudent(char* id) {
  	StudentNode *i = first;
  	StudentNode *tmp, *q;
  	if ( first == NULL && last == NULL) return;

  	if (strcmp(first->id,id) == 0) {
  		tmp = first;
  		first = tmp->next;
  		free(tmp);
  	}

  	for(q = first, i=first->next; i!=NULL; q=q->next, i=i->next){
  		if(strcmp(i->id, id) == 0){
  			tmp = i;
  			i=i->next;
  			q->next = i;
  			free(tmp);
  			break;
	  	}
  	}
}

void processRemove(){
    char id[10];
    printf("Enter id: ");
    scanf("%s",id);
    removeStudent(id);
}

void processSave(){
	char filename[N];
	printf("Enter file name: ");
	scanf("%s",&filename);
	save(filename);
}

void processLoad(){
	char filename[N];
	printf("Enter filename: ");
	scanf("%s",filename);
	load(filename);
}

void print_special(){
    int n;
    scanf("%d", &n);
    for(StudentNode* p= first; p!=NULL; p=p-> next){
        if( ((p->toan)+(p->ly)+(p->hoa)) > n) printf("%s\t%-30s%.2f\t%.2f\t%.2f\n", p->id, p->name, p->toan, p->ly, p->hoa);
    }
}

void swap(){
    char id1[10], id2[10];
    printf("Enter first id");
    scanf("%s",&id1);
    printf("Enter second id");
    scanf("%s",&id2);
    StudentNode *p1, *p2;
    for(StudentNode*p = first; p!=NULL; p=p->next){
        if(strcmp(p->id,id1)==0) p1=p;
    }
    for(StudentNode*p = first; p!=NULL; p=p->next){
        if(strcmp(p->id,id2)==0) p2=p;
    }
    StudentNode* tmp;
        strcpy(tmp->id,p1->id);
        strcpy(tmp->name,p1->name);
        tmp->toan= p1->toan;
        tmp->ly= p1->ly;
        tmp->hoa= p1->hoa;
        strcpy(p1->id,p2->id);
        strcpy(p1->name,p2->name);
        p1->toan= p2->toan;
        p1->ly= p2->ly;
        p1->hoa= p2->hoa;
        strcpy(p2->id,tmp->id);
        strcpy(p2->name,tmp->name);
        p2->toan= tmp->toan;
        p2->ly= tmp->ly;
        p2->hoa= tmp->hoa;
}

int main(){
    init();
	for(;;) {
    int cmd ;
    printf("1.Load and Print\n") ;
    printf("2.Insert\n") ;
    printf("3.Delete\n") ;
    printf("4.Swap\n") ;
    printf("5.Find students with bigger points\n") ;
    printf("6.Load\n") ;
    printf("7.Quit\n") ;

    printf("Choose an action:");
    scanf("%d",&cmd) ;
    while(cmd<0 || cmd > 7){
        printf("action not exist, try again...") ;
        scanf("%d",&cmd) ;
    }
        switch(cmd){
        case 1:
            processLoad() ;
            processPrint();
            break;
        case 2:
            processInsert();
            processPrint();
            break;
        case 3:
            processRemove();
            processPrint();
            break;
        case 4:
            swap();
            processPrint();
            break;
        case 5:
            print_special();
            break;
        case 6:
            processPrint();
            break;
        case 7:
            exit(0);
            break;
        }
    }
}
