#include<stdio.h>
int fib_sec(int limit);

int main(){
    printf("Enter the limit for series :\n");
    int limit ;
    scanf("%d",&limit);
    printf(" ");
    for(int i =0;i< limit ;i++){
        printf("%d  \n ",fib_sec(i));
    }
    return 0;

}

int fib_sec (int num){
    if (num <= 1){
        return num;
    }
    return   fib_sec(num-1) + fib_sec(num -2);


}