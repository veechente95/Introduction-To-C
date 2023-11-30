#include <stdio.h>
#include <unistd.h>

int count = 10;

int main(void) {
    // count greater than 0
    while (count > -1) {
    printf("\v%d\n ", count);
    fflush(stdout);     // holds in buffer for 1 sec
    sleep(1);           // sleep for a second
    count --;           // count = count - 1
    }
    printf("\n Ready to Start");

    return 0;
}
