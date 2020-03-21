#include <stdio.h>
#include <stdlib.h>

int fib(int);			/* fib() 斐波鈉契數列 */

int main(void)
{
   int i,n;
   printf("輸入一正整數n: ");
   scanf("%d",&n); 
   
   for(i=0;i<=n;i++)			/* �p��e1n�ӶO��ƦC */
      printf("fib(%d)=%d\n",i,fib(i));		
   
   return 0;
}

int fib(int n) 		/* fib() 使用遞迴 */
{ 	
   if (n==0)
      return 0; /* �p�Gn=0 �h�Ǧ^ 0*/ 
   else if(n==1 || n==2)	/* �p�Gn=1��n=2�A�h�Ǧ^1 */
      return 1;
   else				/* �_�h�Ǧ^ fib(n-1)+fib(n-2) */
      return (fib(n-1)+fib(n-2));
}

