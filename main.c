#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>
int main() {
    srand(time(NULL));
    int f = fork();
    if(f) {
        rand();
        f = fork();
    }

    if(f) {
        int status;
        int pid = wait(&status);
        printf("finished child pid: %d\tasleep for: %ds\nparent mission complete\n",pid,WEXITSTATUS(status));

        return 0;
    }
    if (!f) {
        printf("child pid: %d\n",getpid());
        int bed = rand()%9+2;
        sleep(bed);
        printf("\nthe child has awoken\n");

        return bed;
    }
}
