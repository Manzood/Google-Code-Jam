//Can be used to test solutions of multiple problems
#include<bits/stdc++.h>
using namespace std;

int rand(int a, int b)
{
	return a + rand() % (b-a+1);
}

int main(int argc, char *argv[])
{
    printf("1\n");
	srand(atoi(argv[1]));
	int n=rand(1,5);
	printf("%d ",n);
    int k = rand(1, 10);
    printf("%d\n", k);
	for (int i=0;i<n;i++)
	{
		int x;
        x=rand(1, k);
		printf("%d ",x);
	}
	puts("");
}
