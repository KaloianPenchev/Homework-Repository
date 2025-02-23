#include "processes.h"
#include <string.h>

Process processes[5];
int processescount = 0;

static unsigned long nextprocessid() {
    if (processescount == 5) {
        return 0;
    }
    return processescount + 1;
}

unsigned long createnewprocess(char *name) {
    Process new_process;
    int newID = nextprocessid();

    if (newID == 0) {
        return 0;
    }

    new_process.ID = newID;
    strcpy(new_process.name, name);

    processes[newID - 1] = new_process; 
    processescount++;

    return newID;
}

void stopprocess(unsigned long ID) {
    if (ID < 1 || ID > processescount) {
        return;
    }

    for (int i = ID - 1; i < processescount - 1; i++) {
        processes[i] = processes[i + 1];
        processes[i].ID = i + 1;
    }

    processescount--;
}
