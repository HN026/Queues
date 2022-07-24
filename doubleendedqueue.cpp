#include<iostream>

using namespace std;

struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};

void create( struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = new int [q->size];
}

void Insertthroughrear(struct Queue *q, int x)
{
    if(q->rear == q->size-1)
    {
        cout<<"Queue is full"<<endl;
    }
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int deletethroughfront( struct Queue *q)
{
    int x = -1;
    if (q->front == q->rear)
    {
        cout<<"String is empty"<<endl;
    }
    else
    {
       q->front++;
       x = q->Q[q->front];
    }
    return x;
}

void InsertThroughfront(struct Queue *q, int x)
{
    if(q->front<0)
    {
        cout<<"No space to insert from the front"<<endl;
    }
    else
    {
        q->Q[q->front] = x;
        q->front--;
    }
}

int DeleteThroughBack(struct Queue *q)
{
    int x = -1;
    if(q->front == q->rear)
    {
        cout<<"Queue is Empty"<<endl;
    }
    else
    {
        x = q->Q[q->rear];
        q->rear--;
    }
    return x;
}

void Display(struct Queue q)
{
    int i;
    for ( i = q.front+1; i<=q.rear; i++)
    {
        cout<<q.Q[i]<<" ";
    }

cout<<endl;
}




int main()
{
    struct Queue q;
    create(&q, 5);
    Insertthroughrear(&q,10);
    Insertthroughrear(&q,20);
    Insertthroughrear(&q,30);
    Insertthroughrear(&q,40);
    Insertthroughrear(&q,50);

   Display(q);
   deletethroughfront(&q);
   Display(q);
   DeleteThroughBack(&q);
   Display(q);
   InsertThroughfront(&q,10);
   Display(q);
   InsertThroughfront(&q,10);
   Display(q);


    return 0;
}
