// circular increment  😀😀😀  i=(i+1)%size   😀😀😀;
// linear increment  😀😀😀  i=(i+1)   😀😀😀;

#include <bits/stdc++.h>
using namespace std;

// A structure to represent a queue
class Queue
{
public:
    int f, r, size;
    unsigned capacity;
    int *arr;
};

// function to create a queue
// of given capacity.
// It initializes size of queue as 0
Queue *createQueue(unsigned capacity)
{
    Queue *queue = new Queue();
    queue->capacity = capacity;
    queue->f = queue->r = 0;
    queue->arr = new int[queue->capacity];
    return queue;
}

// Queue is full when size
// becomes equal to the capacity
int isFull(Queue *queue)
{
    if ((queue->r + 1) % (queue->capacity) == queue->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Queue is empty when size is 0
int isEmpty(Queue *queue)
{
    if (queue->f == queue->r)
    {
        cout << "Empty queue" << endl;
        return 1;
    }
    else
    {
        return 0;
    }
}

// Function to add an item to the queue.
// It changes rear and size
void enqueue(Queue *queue, int item)
{
    if (isFull(queue))
    {
        cout << "queue full!!" << endl;
        return;
    }
    else
    {
        queue->r = (queue->r + 1) % queue->capacity;
        queue->arr[queue->r] = item;
    }
}

// Function to remove an item from queue.
// It changes front and size
int dequeue(Queue *queue)
{
    if (isEmpty(queue))
        return -1;
    else
    {
        queue->f = (queue->f + 1) % queue->capacity;
        int item = queue->arr[queue->f];
        return item;
    }
}

// Function to get front of queue
int front(Queue *queue)
{
    // if (queue->f == queue->r)
    // {
    //     return -1;
    // }
    return queue->arr[(queue->f + 1) % queue->capacity];
}

// Function to get rear of queue
int rear(Queue *queue)
{
    // if (queue->r == -1)
    // {
    //     return queue->arr[(queue->r + 1)];
    // }
    return queue->arr[(queue->r) % queue->capacity];
}

// Driver code
int main()
{
    Queue *queue = createQueue(5);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    // enqueue(queue, 50);
    // enqueue(queue, 60);
    // cout << isEmpty(queue) << endl;
    // cout << isFull(queue) << endl;
    cout << dequeue(queue) << " dequeued from queue\n";
    cout << dequeue(queue) << " dequeued from queue\n";
    cout << dequeue(queue) << " dequeued from queue\n";
    // cout << dequeue(queue) << " dequeued from queue\n";
    // cout << dequeue(queue) << " dequeued from queue\n";
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    cout << dequeue(queue) << " dequeued from queue\n";
    cout << dequeue(queue) << " dequeued from queue\n";
    // cout << dequeue(queue) << " dequeued from queue\n";
    // cout << dequeue(queue) << " dequeued from queue\n";
    // cout << dequeue(queue) << " dequeued from queue\n";
    // cout << isEmpty(queue) << endl;
    // cout << isFull(queue) << endl;

    cout << "Front item is " << front(queue) << endl;
    cout << "Rear item is " << rear(queue) << endl;

    return 0;
}

// This code is contributed by rathbhupendra
