# include<stdio.h>
void knapsack(int n, float weight[], float profit[], float capacity) {
   float x[20], total_pro = 0; //TOTAL PROFIT.
   int i, j, u;
   u = capacity;
 
   for (i = 0; i < n; i++)
      x[i] = 0.0;
 
   for (i = 0; i < n; i++) {
      if (weight[i] > u)
         break;
      else {
         x[i] = 1.0;
         total_pro = total_pro + profit[i];
         u = u - weight[i];
      }
   }
 
   if (i < n)
      x[i] = u / weight[i];
 
   total_pro = total_pro + (x[i] * profit[i]);
 
   printf("\n>>>\nThe result vector is:- ");
   for (i = 0; i < n; i++)
      printf("%0.2f\t",x[i]);
 
   printf("\nMaximum profit is:- %0.2f", total_pro);
 
}
 
int main() {
   float weight[20], profit[20], capacity;
   int num, i, j;
   float ratio[20], temp;
 
   printf("\nEnter the no. of objects:- ");
   scanf("%d", &num);
 
   printf("\nEnter the wts  of each object:- ");
   for (i = 0; i < num; i++) {
      scanf("%f", &weight[i]);
   }
    printf("\nEnter the profit  of each object:- ");
   for (i = 0; i < num; i++) {
      scanf("%f",&profit[i]);
   }
 
   printf("\nEnter the capacityacity of knapsack:- ");
   scanf("%f", &capacity);
 
   for (i = 0; i < num; i++) {
      ratio[i] = profit[i] / weight[i];
   }
 // just sort WEIGHT AND PROFIT  arrays ON THE BASIS OF RATIO ARRAY.
   for (i = 0; i < num; i++) {
      for (j = i + 1; j < num; j++) {
         if (ratio[i] < ratio[j]) {
            temp = ratio[j];
            ratio[j] = ratio[i];
            ratio[i] = temp;
 
            temp = weight[j];
            weight[j] = weight[i];
            weight[i] = temp;
 
            temp = profit[j];
            profit[j] = profit[i];
            profit[i] = temp;
         }
      }
   }
 printf("\nafter sorting weight and profit array on the basis of ratio array \n>>>\n");
  printf("sorting of weight array");
     for (i = 0; i < num; i++) {
      printf(" %.2f",weight[i]);
   }
   printf("\nsorting of profit array");
     for (i = 0; i < num; i++) {
      printf(" %0.2f",profit[i]);
   }
   printf("\nsorting of ratio array");
     for (i = 0; i < num; i++) {
      printf(" %0.2f",ratio[i]);
   }
   knapsack(num, weight, profit, capacity);
   return(0);
}
