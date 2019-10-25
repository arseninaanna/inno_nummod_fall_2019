#include <stdio.h>
#include "blackbox.h"

int main() {
    int n;
    scanf("%d", &n);
    blackbox_init(n);

    const size_t k = 1e8;
    const double h = 2.0 / k;
    const double double_h = 2*h;
    const double h_div_3 = h/3;
    double sum = 0;

    double start = -1;
    double finish = 1 - double_h;
    double blackbox_prev = blackbox(start);
    while(start <= finish) {
        double right_part = blackbox(start + double_h);
        sum += (blackbox_prev + 4*blackbox(start + h) + right_part);
        blackbox_prev = right_part;
        start = start + double_h;
    }

    printf("%.12lf\n", h_div_3*sum);
}