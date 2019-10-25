#include <stdio.h>
#include "blackbox.h"

int main() {
    int n;
    scanf("%d", &n);
    blackbox_init(n);

    const size_t k = 40;
    const double h = 2.0 / k;
    double sum = 0;

    double start = -1;
    while(start <= 1 - 2*h) {
        sum += (h/3) * (blackbox(start) + 4*blackbox(start + h) + blackbox(start + + 2*h));
        start = start + 2*h;
    }

    printf("%.12lf\n", sum);
}