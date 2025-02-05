#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

void usage() {
    fprintf(stderr, "usage: wakeup [~grace period (min)] <times HH:MM...>\n");
}

int main(int argc, char **argv) {
    int i;
    int h, m, no_minutes, new_h, new_m, grace_period;

    if (argc == 1) { usage(); exit(1); }

    grace_period = 90;
    for (i = 1; i < argc; i++) {
        if (sscanf(argv[i], "~%d", &grace_period) == 1) continue;

        if (grace_period > (12 * 60) || grace_period < (-12 * 60)) {
            fprintf(stderr, "Grace period shouldn't be longer than 12 hours.\n");
            exit(1);
        }

        if (sscanf(argv[i], "%d:%d", &h, &m) != 2) {
            usage();
            exit(1);
        }

        no_minutes = m + (h * 60);
        no_minutes -= grace_period;
        
        if (no_minutes < 60) no_minutes += (12 * 60);

        new_h = no_minutes / 60;
        new_m = no_minutes % 60;

        printf("%2d:%02d -> %2d:%02d (%d min)\n", h, m, new_h, new_m, grace_period);      
    }
}
