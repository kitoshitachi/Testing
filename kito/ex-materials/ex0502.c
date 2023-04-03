#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

void display_scores(int *scores, int n){
    for (int i = 0; i < n; i++) {
        printf("scores[%d] = %d\n", i, scores[i]);
    }
}

void get_scores(int *scores, int n){
    printf("scores = ");
    char string[50];
    getchar();
    fgets(string, 50, stdin);
    string[strcspn(string, "\n")] = '\0';
    char* token = strtok(string, " ");
    int i = 0;
    while(token != NULL && i < n){
        scores[i++] = atoi(token);
        token = strtok(NULL, " ");
    }
    // display_scores(scores,n);
}

float ave(int *scores, int n){
    int sum = 0, count = 0;
    for (int i = 0; i < n; i++) {
        if ( scores[i] > -1){
            sum += scores[i];
            count += 1;
        }
    }
    
    return (sum * 1.0) / count;
}

int Max(int *scores, int n){
    int temp = scores[0];
    for(int i = 1; i < n; i++){
            temp = max(temp,scores[i]);
    }
    return temp;
}

int Min(int *scores, int n){
    int temp = scores[0];
    for(int i = 1; i < n; i++){
        if (scores[i] > -1)
            temp = min(temp,scores[i]);
    }
    return temp;
}

int passed(int *scores, int n){
    int count = 0;
    for(int i = 0; i < n; i++){
        if(scores[i] >= 60)
            count += 1;
    }
    return count;
}

void result(int *scores, int n){

    int _Max;
    _Max = Max(scores,n);
    
    if ( _Max > 100)
        printf("ERROR: invalid score (%d)",_Max);
    else{
        printf("====== score info ======");
        printf("\n #student = %d", n);
        printf("\n #passed = %d", passed(scores,n));
        printf("\n ave = %.1f", ave(scores,n));
        printf("\n max = %d", _Max);
        printf("\n min = %d", Min(scores,n));
        printf("\n==========================");
    }

}


int main(void){
    int n;
    int* scores;
    printf("n = ");
    scanf("%d",&n);
    n=n;
    if(n <= 0 || n >= 10)
        printf("ERROR: invalid number of students (%d)",n);
    else
    {
        scores = (int*)malloc(n * sizeof(int));
        get_scores(scores,n);
        result(scores,n);
    }

}