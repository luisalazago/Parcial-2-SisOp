/* Test with a dumb file the changes made and the new insertions
   on the files */

#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[]) {
    int pid;
    int k, n;
    long long x, z;
    long long temp = 2000000000;
    long long temp2 = temp + temp;

    if(argc < 2) n = 1; // Default
    else n = atoi(argv[2]);
    
    if(n < 0 || n > 20) n = 2;
    x = 0;
    pid = 0;

    for(k = 0; k < n; ++k) {
        pid = fork();
        if(pid < 0) printf(1, "%d failed in fork!\n", getpid());
        else if(pid > 0) {
            // Parent
            printf(1, "Parent %d creating child %d\n",getpid(), pid);
            wait();
        }
        else {
            printf(1,"Child %d created\n",getpid());
            for(z = 0; z < temp2; ++z)
                x = x + 3.14 * 89.64; //Useless calculation to consume CPU time
            break;
        }
    }

    exit();
}