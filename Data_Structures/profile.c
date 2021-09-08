#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_L 256
//#include "profile.h"

typedef struct Profile {
    char name[MAX_L];
    char email[MAX_L];
    struct Profile* next;
} Profile;


Profile* first, *last;

Profile* makeProfile(char* name, char* email) {
    Profile* node = (Profile*)malloc(sizeof(Profile));
    strcpy(node->name,name);
    strcpy(node->email,email);
    node->next = NULL;
    return node;
}

void init() {
    first = NULL; last = NULL;
}

Profile* getFirst() {
  return first;
}

Profile* getLast() {
  return last;
}

void cleanup() {
  Profile* i = first;
  Profile *tmp;
  while ( i!= NULL) {
    tmp = i;
    i = i->next;
    free(tmp);
  }
  first = last = NULL;
}

int isEmpty(){
  return ((first == NULL) && (last == NULL));
}

void insertLast(char* name, char* email){
    Profile* profile = makeProfile(name,email);
    if(isEmpty()){
      first = last = profile;
    }else{
        last->next = profile;
	last = profile;
    }
}

void removeProfile(char* name) {
  Profile *i = first;
  Profile *tmp, *prev;

  if (isEmpty()) return;

  if (strcmp(first->name,name) == 0) {
    while (strcmp(first->name,name) == 0) {
      tmp = first;
      first = tmp->next;
      free(tmp);
    }
    if (first == NULL) last = NULL;
  };

  prev = first;
  i = first->next;
  while (i != NULL)
    if (strcmp(i->name,name) == 0) {
      tmp = i;
      i = i->next;
      prev->next = i;
      free(tmp);
    } else {
      prev = i;
      i = prev->next;
    }
  last = prev;
}

Profile* findProfile(Profile*first, char* name) {
  Profile *i = first;
  while (i != NULL) {
    if (strcmp(i->name, name) == 0)
      return i;
    else i = i->next;
  }
}

void printList(){
  Profile *p;
  for(p = first; p != NULL; p = p->next)
    printf("%s %s\n",p->name, p->email);
}

void load(char* filename){
  char name[MAX_L];
  char email[MAX_L];

  FILE* f = fopen(filename,"r");

  if(f == NULL) {
    printf("Load data -> file not found\n");
    return;
  }

  while(1){
    if(feof(f)) break ;
    fgets(name, MAX_L, f);
    fgets(email, MAX_L, f);
    insertLast(name,email);
  }
  fclose(f);
}

void save(char *filename){
  FILE* f = fopen(filename,"w");
  if(f == NULL) {
    printf("Save data -> can\'t save\n");
    return;
  }

  for(Profile* p = first; p != NULL; p = p->next){
        fprintf(f,"%s\n%s",p->name,p->email);
        if(p->next != NULL) fprintf(f,"\n");
  }
  fclose(f);
}

int main(){
    init() ;
    load("minh.txt");
    printList();



}

