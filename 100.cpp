#include <iostream>

using namespace std;

int calculate_length(int n) {
    int iterations = 1;
    while (n != 1) {
        iterations++;
        if (n % 2 == 0) {
            n = n/2;
        } else {
            n = 3*n + 1;
        }
    }
    return iterations;
}

int main()
{
    int m, n;

    while(fscanf(stdin,"%d %d", &m, &n)==2) {
        int max_length = 0;
        int min = m < n ? m : n;
        int max = m < n ? n : m;
        fprintf(stdout, "%d %d ", m, n);
        for (int i = min; i <= max; i++) {
            int cur_length = calculate_length(i);
            if (cur_length > max_length) {
                max_length = cur_length;
            }
        }
        fprintf(stdout, "%d\n", max_length);
    }
}