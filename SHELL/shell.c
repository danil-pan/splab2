#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void systemCustom(char *arg) {
    pid_t pid = fork();
    if (pid == 0){
        char *name[] = { "/bin/bash","-c",arg,NULL};
        execvp(name[0], name);
        exit(-1);
    } else {
        waitpid(pid, 0, 0);
    }
}

int main() {
    char * command;
    while (1) {
        printf("$ Enter your command: ");
        fflush(stdin);
        scanf("%s", command);
        if (!strcmp(command, "exit")) { break; }
        systemCustom(command);
    }q  
    return 0;
}
