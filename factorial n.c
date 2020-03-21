#include <stdio.h>
#include <stdlib.h>

int fac(int);

int main(){
    int n;
    printf ("Input a positive integer n:\n...");
    scanf("%d", &n);
    for (int i=0; i<=n; i++)
        printf ("fac(%d)=%d \n", i, fac(i));
    return 0;    
}

/* factorial: n!=n*(n-1)*(n-2)*...*1 */
int fac(int n){
    int sum = 1;
    for (int i=1; i <= n; i++){
        sum *= i;
    }
    return sum;
}