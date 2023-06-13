#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {green,yellow,red }trafficstate;
void wait(int seconds) {
    clock_t endtime = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < endtime) {
    }
}
int main() {
    trafficstate state = green;

    while (1) {
        switch (state) {
            case green:
                printf("Traffic light:green\n");
                wait(360);            // Wait for 6 minutes
                state = yellow;
                break;
            case yellow:
                printf("Traffic light:yellow\n");
                wait(10);        // Wait for 10 seconds
                state =red;
                break;
            case red:
                printf("Traffic light:red\n");
                wait(120);     // Wait for  (2 minutes)
                state = green;
                break;
        }
    }

    return 0;
}







