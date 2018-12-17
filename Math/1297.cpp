#include<stdio.h>
#include<math.h>
int main(void) {
	float a, b, c, d;
	float f;
	scanf("%f %f %f", &a, &b, &c);
	f = sqrt(c*c + b * b);
	printf("%d %d", (int)(a*b / f), (int)(a*c / f));
	return 0;
}