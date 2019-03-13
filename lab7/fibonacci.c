#include<stdio.h>

int fibonacci(int n)
{
    if (n == 0 || n == 1)
        return n;
    else
        return (f(n - 1) + f(n - 2));
}

int main()
{
  int n;
  scanf("%d", &n);
  printf("%d\n", fibonacci(i));
  return 0;
}
