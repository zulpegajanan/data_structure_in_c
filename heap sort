
#include <stdio.h>
int size = 0;
int size2 = 0;
void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}
void heapify(int array[], int size, int i)
{
  if (size == 1)
  {
    printf("Single element in the heap");
  }
  else
  {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] > array[largest])
      largest = l;
    if (r < size && array[r] > array[largest])
      largest = r;
    if (largest != i)
    {
      swap(&array[i], &array[largest]);
      heapify(array, size, largest);
    }
  }
}
void heapify2(int array2[], int size2, int i)
{
  if (size2 == 1)
  {
    printf("Single element in the heap");
  }
  else
  {
    int small = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size2 && array2[l] < array2[small])
      small = l;
    if (r < size2 && array2[r] < array2[small])
      small = r;
    if (small != i)
    {
      swap(&array2[i], &array2[small]);
      heapify(array2, size2, small);
    }
  }
}

void insert(int array[], int newNum)
{
  if (size == 0)
  {
    array[0] = newNum;
    size += 1;
  }
  else
  {
    array[size] = newNum;
    size += 1;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      heapify(array, size, i);
    }
  }
}

void insert2(int array2[], int newNum)
{
  if (size2 == 0)
  {
    array2[0] = newNum;
    size2 += 1;
  }
  else
  {
    array2[size2] = newNum;
    size2 += 1;
    for (int i = size2 / 2 - 1; i >= 0; i--)
    {
      heapify2(array2, size2, i);
    }
  }
}





int delete_root(int array[])
{
  int i=0;
  swap(&array[i], &array[size - 1]);
  int a= array[size-1];
  size -= 1;
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    heapify(array, size, i);
  }
  return a;
}

void printArray(int array[], int size)
{
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}


int  delete_root2(int array2[])
{
  int i=0;
  swap(&array2[i], &array2[size2 - 1]);
  int z=array2[size2 - 1];
  size2 -= 1;
  for (int i = size2 / 2 - 1; i >= 0; i--)
  {
    heapify(array2, size2, i);
  }
  return z;
}

void printArray2(int array2[], int size2)
{
  for (int i = 0; i < size2; ++i)
    printf("%d ", array2[i]);
  printf("\n");
}

int main()
{
  int array[10];
  int array2[10];
  int ch;
  do{
      printf("\n1.insert\n2.delete\n3.display max tree \n4.display min tree\n5.sort max heap \n6.exit\n\t\t");
      scanf("%d",&ch);
     
      switch(ch){
          case 1:{
              int k;
              printf("enter which number you want to insert ");
              scanf("%d",&k);
              insert(array,k);
              insert2(array2,k);
              printf("done");
              break;
          }
          case 2:{
              int kk=delete_root(array);
              int kk2 =delete_root2(array2);
              printf("\t%d root element is deleted from max heap",kk);
              printf("\n\t%d root element is deleted from mix heap",kk2);
              break;
          }
          case 3: {
              printArray(array,size);
              break;
          }
          case 4:{
              printArray2(array2,size2);
              break;
              //min heap
          }
          case 5:{
            
            printf("mix heap sort\n");
            int nako=size;
            for(int i=0;i<nako;i++){
                printf("%d ",delete_root(array));
            }
             
          }
         case 6:{
              printf("gajanan zulpe");
         }
      }
  }while(ch!=6);

}
