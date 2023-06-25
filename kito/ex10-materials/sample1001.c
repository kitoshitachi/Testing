#include <stdio.h>
#define X 10
int f1(int a[],int b,int c){int d;int e;e=b;for(d=b+1;d<=c;d++){if(a[d]<a[e])e=d;}return e;}
void f2(int a[],int b){int c,d,e;for(c=0;c<b;c++){d=f1(a,c,b-1);if(d!=c){e=a[d];a[d]=a[c];a[c]=e;}}}
int main(void){int a,b,c[X];scanf("%d", &b);if(b<=0){printf("[ERROR] data count must be positive!\n");return 1;}if(b>X){printf("[ERRRO] too many data!\n");return 1;}for(a=0;a<b;a++)scanf("%d",&c[a]);printf("before: ");for(a=0;a<b;a++)printf("%d ",c[a]);printf("\n");f2(c,b);printf("after:  ");for(a=0;a<b;a++)printf("%d ",c[a]);printf("\n");return 0;}
