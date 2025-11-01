#include<stdio.h>
#include<stdlib.h>

struct Items{
    int weight;
    int profit;
};

int n,capacity;
struct Items items[50];
int max_profit = 0;

void knapsack_back(int index,int cur_weight,int cur_profit){
    if(index == n){
        if(cur_profit > max_profit){
            max_profit = cur_profit;
        }
        return;
    }
    knapsack_back( index +1, cur_weight, cur_profit);
    if(cur_weight + items[index].weight <= capacity){
    knapsack_back( index+1, cur_weight+items[index].weight, cur_profit+items[index].profit);

    }

}
int main(){
    printf("Enter the number of elements   :");
    scanf("%d",&n);
    printf("Enter the capacity   :");
    scanf("%d",&capacity);
    for(int i=0 ; i < n ; i++){
        printf("Enter the weight of item at %d :",i+1);
        scanf("%d",&items[i].weight);
        printf("Enter the profit of item at %d :",i+1);
        scanf("%d",&items[i].profit);
    }
    knapsack_back(0,0,0);
    printf("The maximum profit is %d ",max_profit);
    return 0;
}
