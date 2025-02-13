#ifndef PROCESSES_H_
#define PROCESSES_H_



typedef struct{
    unsigned long ID;
    char name[30];
}Process;

extern Process processes[5];
extern int processescount;

unsigned long createnewprocess(char name[]);

void stopprocess(unsigned long ID);

#endif