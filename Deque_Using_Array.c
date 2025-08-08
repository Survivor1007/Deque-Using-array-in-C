#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define SIZE 5
#define Error INT_MIN

typedef struct
{
      int arr[SIZE];
      int rear;
      int front;
}Deque;
int isFull(Deque *deque)
{
      return deque -> front == ((deque -> rear + 1) % SIZE );
}
int isEmpty(Deque *deque)
{
      return deque -> front == -1;
}
int enqueuerear(Deque *deque, int ele)
{
      if( isFull(deque))
            return 0;
      if ( isEmpty(deque))
            deque -> front = deque -> rear = 0;
      else
            deque -> rear = (deque -> rear + 1) % SIZE;
      deque -> arr[deque -> rear] = ele;
      return 1;
}
int enqueuefront(Deque *deque, int ele)
{
      if( isFull(deque))
            return 0;
      if ( isEmpty(deque))
            deque -> front = deque -> rear = 0;
      else
            deque -> front = (deque -> front - 1 + SIZE) % SIZE;
      deque -> arr[deque -> front] = ele;
      return 1;
}
int dequeuerear(Deque *deque)
{
      if ( isEmpty(deque))
            return Error;
      int ele = deque -> arr[deque -> rear];
      if ( deque -> rear == deque -> front)
            deque -> rear = deque -> front = -1;
      else
            deque -> rear = (deque -> rear - 1 + SIZE) % SIZE;
      return ele;
}
int dequeuefront(Deque *deque)
{
      if ( isEmpty(deque))
            return Error;
      int ele = deque -> arr[deque -> front];
      if ( deque -> rear == deque -> front)
            deque -> rear = deque -> front = -1;
      else
            deque -> front = (deque -> front + 1) % SIZE;       
      return ele;
}
int main()
{
      Deque deque;
      deque.rear = deque.front = -1;
      int ele, choice;
      for( ;;)
      {
            printf("Enter your choice\n");
            printf("1.Enqueue Rear\n2Enqueue Front\n3.Dequeue Rear\n4.Dequeue Front\n5.Empty\n6.Full\n7.EXIT\n");
            printf("Your CHOICE:");
            scanf("%d", &choice);
            if ( choice == 7)
                  break;
            switch(choice)
            {
                  case 1:
                        printf("Enter the element:");
                        scanf("%d", &ele);

                        if(enqueuerear(&deque, ele) == 0)
                              printf("-----------------ERROR:OVERFLOW----------------\n");
                        break;
                  case 2:
                        printf("Enter the element:");
                        scanf("%d", &ele);

                        if(enqueuefront(&deque, ele) == 0)
                              printf("-----------------ERROR:OVERFLOW----------------\n");
                        break;
                  case 3:
                        if ( (ele = dequeuerear(&deque)) == Error)
                              printf("------------------ERROR:UNDERFLOW----------------\n");
                        else
                              printf("The popped element is : %d \n", ele);
                        break;
                  case 4:
                        if ( (ele = dequeuefront(&deque)) == Error)
                              printf("------------------ERROR:UNDERFLOW----------------\n");
                        else
                              printf("The popped element is : %d \n", ele);
                        break;
                  case 5:
                        if ( isEmpty(&deque))
                              printf("The deque is empty\n");
                        else
                              printf("The deque is not empty\n");
                        break;
                  case 6:
                         if ( isFull(&deque))
                              printf("The deque is full\n");
                        else
                              printf("The deque is not full\n");
                        break;
                  default:
                        printf("ERROR:Wrong Input!!!");
                        break;
            }
      }
}