#include <stdio.h>

int N;
int P[1000];
int O[1000];

struct Birthday {
    char tmp[20];
    int date;
    int month;
    int year;
};
void init(int *date, int *month, int *year, char tmp[20]) {
    date = (tmp[0]-'0')*10 + tmp[1]-'0';
    month = (tmp[3]-'0')*10 + tmp[4]-'0';
    year = (tmp[6]-'0')*1000 + (tmp[7]-'0')*100 + (tmp[8]-'0')*10 + tmp[9]-'0';
}
struct Man {
    int StudentID;
    char StudentName[20];
    struct Birthday Birthdate;
    char ClassName[15];
    char CourseName[20];
} T[1000];

void Enter() {
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; ++i) {
        scanf("%d",&T[N].StudentID);
        scanf("%s",&T[N].StudentName);
        scanf("%s",&T[N].Birthdate.tmp);
        scanf("%s",&T[N].ClassName);
        scanf("%s",&T[N].CourseName);
        init(&T[N].Birthdate.date,&T[N].Birthdate.month,&T[N].Birthdate.year,T[N].Birthdate.tmp);
        N++;
    }

    FILE *os = fopen("student.dat","w");
    fprintf(os,"%d\n",N);
    for(int i=0; i<N; ++i) {
        fprintf(os,"%d\n",T[i].StudentID);
        fprintf(os,"%s\n",T[i].StudentName);
        fprintf(os,"%s\n",T[i].Birthdate.tmp);
        fprintf(os,"%s\n",T[i].ClassName);
        fprintf(os,"%s\n\n",T[i].CourseName);
    }
    fclose(os);

    for(int i=0; i<N; ++i)
        P[i]=i;
}

void Show() {
    printf("%s %d\n","Total number of student: ",N);
    printf("No  StudentID          StudentName        Birthdate           ClassName           CourseName\n");
    printf("===================================================================================================================\n");
    for(int i=0; i<N; ++i) {
        int j=P[i];
        printf("%-3d%-20d%-20s%-20s%-20s%s\n",i+1,T[j].StudentID,T[j].StudentName,T[j].Birthdate.tmp,T[j].ClassName,T[j].CourseName);

    }
    printf("\n");
}

void SearchByStudentID() {
    printf("Enter StudentID.. ");
    int ID;
    scanf("%d",&ID);

    for(int i=0; i<N; ++i) {
        for(int j=i+1; j<N; ++j) {
            if(T[P[i]].StudentID > T[P[j]].StudentID) {
                int tmp=P[i];
                P[i]=P[j];
                P[j]=tmp;
            }
        }
    }

    int le=0,mi,ri=N-1, ret;
    while(le<=ri) {
        mi=(le+ri)/2;
        printf("%d %d ",le,ri);
        printf("%d\n ",T[P[mi]].StudentID);
        if(T[P[mi]].StudentID == ID) {
            printf("%d, %s, %s, %s, %s\n\n",T[P[mi]].StudentID, T[P[mi]].StudentName, T[P[mi]].Birthdate.tmp, T[P[mi]].ClassName, T[P[mi]].CourseName);
            return;
        }
        if(T[P[mi]].StudentID < ID)
            le=mi+1;
        else
            ri=mi-1, ret=mi;
    }
    mi=ret;
    if(T[P[mi]].StudentID == ID) {
        printf("%d, %s, %s, %s, %s\n\n",T[P[mi]].StudentID, T[P[mi]].StudentName, T[P[mi]].Birthdate.tmp, T[P[mi]].ClassName, T[P[mi]].CourseName);
        return;
    } else
        printf("No student is found!\n\n");
}

void NewStudent() {
    int n=1;
    for(int i=0; i<n; ++i) {
        scanf("%d",&T[N].StudentID);
        scanf("%s",&T[N].StudentName);
        scanf("%s",&T[N].Birthdate.tmp);
        scanf("%s",&T[N].ClassName);
        scanf("%s",&T[N].CourseName);
        init(&T[N].Birthdate.date,&T[N].Birthdate.month,&T[N].Birthdate.year,T[N].Birthdate.tmp);
        N++;
    }

    FILE *os = fopen("student.dat","w");
    fprintf(os,"%d\n",N);
    for(int i=0; i<N; ++i) {
        fprintf(os,"%d\n",T[i].StudentID);
        fprintf(os,"%s\n",T[i].StudentName);
        fprintf(os,"%s\n",T[i].Birthdate.tmp);
        fprintf(os,"%s\n",T[i].ClassName);
        fprintf(os,"%s\n\n",T[i].CourseName);
    }
    fclose(os);

    for(int i=0; i<N; ++i)
        P[i]=i;
}

int main() {
    for(;;) {
        printf("1. Enter information the students of HUST\n");
        printf("2. Display the information of the entered students\n");
        printf("3. Sort ascending information the students by student name\n");
        printf("4. Add a new student of HUST\n");
        printf("5. Search for students by student ID\n");
        printf("6. Exit\n");
        int cmd ;
        printf("Enter command.. ") ;
        scanf("%d", &cmd) ;
        while(cmd <=0 || cmd >6) {
            printf("Invalid command, try again.. ") ;
            scanf("%d", &cmd) ;
        }
        switch(cmd) {
        case(1) :
            Enter();
            break;
        case(2) :
            for(int i=0; i<N; ++i)
                P[i]=i;
            Show();
            break;
        case(3) :
            for(int i=0; i<N; ++i) {
                for(int j=i+1; j<N; ++j) {
                    if(strcmp(T[P[i]].StudentName,T[P[j]].StudentName)>0) {
                        int tmp=P[i];
                        P[i]=P[j];
                        P[j]=tmp;
                    }
                }
            }
            Show();
            break;
        case(4) :
            NewStudent();
            break;
        case(5) :
            SearchByStudentID();
            break;
        case(6) :
            printf("Make sure to close the opened file and free up memory (if any) before exiting.. ");
            getchar();
            exit(0);
            break;
        }
    }
}
/**
20204936
Nguyen_
07/08/2002
VI__DDD
gummy

20204960
PHMA_
10/07/2001
ICT_
C_Pro
*/
