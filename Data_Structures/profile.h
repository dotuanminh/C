#ifndef __PROFILE_H__
#define __PROFILE_H__

#define MAX_L 256

typedef struct Profile {
    char name[MAX_L];
    char email[MAX_L];
    struct Profile* next;
} Profile;

void init();
void cleanup();

Profile *getFirst();
Profile *getLast();

int isEmpty();

void insertLast(char* name, char* email);
void removeProfile(char* name);
Profile* findProfile(Profile* first, char* name);

void printList();

void load(char* filename);
void save(char* filename);  

#endif
