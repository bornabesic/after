#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int process_exists(int pid) {
    return !kill(pid, 0);
}

int main(int argc, char **argv) {

    if (argc != 3) {
        printf("Invalid arguments.\n");
        return 1;
    }

    int pid = atoi(argv[1]);

    if (!process_exists(pid)) {
        printf("Cannot find a process with the specified PID.\n");
        return 1;
    }

    char *command = argv[2];

    while (process_exists(pid)) {
        sleep(1);
    }

    system(command);

    return 0;
}

