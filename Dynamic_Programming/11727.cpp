#include <stdio.h>

int main(void){

    int Dp[1010] = {};
    int n;
    Dp[0] = 1; Dp[1] = 1;

    scanf("%d", &n);

    for (int i = 2; i <= n; i++)
        Dp[i] = (Dp[i - 1] + Dp[i - 2] *2) % 10007;

    printf("%d\n", Dp[n] % 10007);

    return 0;
}