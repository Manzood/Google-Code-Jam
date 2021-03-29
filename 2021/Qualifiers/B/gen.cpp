#include<bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
	return a + rand() % (b - a + 1);
}

int main (int argc, char *argv[]) {
	srand(atoi(argv[1]));
    // test cases
    int t = 1;
    printf("%d\n", t);                  // comment this if no test cases
    while (t--) {
        int x1 = rand(1, 5);
        int x2 = rand(1, 5);
        printf("%d %d ", x1, x2);
        int n = rand(2, 10);
        // printf ("%d\n", n);
        for (int i = 0; i < n; i++) {
            int x;
            x = rand(1, 3);
            // int y;                   // second number
            // y = rand (1, 10);
            if (x == 1) {
                printf("C");
            } else if (x == 2) {
                printf("J");
            } else {
                printf("?");
            }
            // printf("%d ", y);
        }
        puts("");
    }
}
