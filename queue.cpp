#include <iostream>
#define MAX 5
using namespace std;
class queue
{
    int arr[MAX], front, rear;

public:
    queue()
    {
        front = rear = -1;
    }
    bool eq(int data)
    {
        bool success;
        if ((sizeof(arr) / 4) > MAX)
        {
            success = false;
        }
        else
        {
            rear++;
            arr[rear] = data;
            if (front == -1)
            {
                front = 0;
            }
            success = true;
            cout << "pushed " << arr[rear];
        }
        return success;
    }
    bool dq()
    {
        bool success;
        int dataout;
        if (front== -1)
        {
            success = false;
        }
        else
        {
            dataout = arr[front];
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                ++front;
                success = true;
            }
        }
        cout << "poped" << dataout << endl;

        return success;
    }
    bool queuefront(int dataout)
    {
        bool success;
        if (front = rear = -1)
        {
            success = false;
        }
        else
        {
            dataout = arr[front];
            success = true;
        }
        return success;
    }
    bool queuerear(int dataout)
    {
        bool success;
        if (front = rear = -1)
        {
            success = false;
        }
        else
        {
            dataout = arr[rear];
            success = true;
        }
        return success;
    }
    bool emptyqueue()
    {
        bool empty;
        if (front == -1 && rear == -1)
        {
            empty = true;
        }
        else
        {
            empty = false;
        }
        return empty;
    }
    bool fullqueue()
    {
        bool full;
        if (rear == MAX)
        {
            full = true;
        }
        else
        {
            full = false;
        }
        return full;
    }
    int queuecount()
    {
        if (front == -1 && rear == -1)
        {
            return 0;
        }
        else
        {
            return rear - front + 1;
        }
    }
    void display()
    {
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
    }
};
int main()
{
    queue q;
    bool a, b, c;
    cout << "enter 1 for enqueue \n 2 for dequeue\n 3 for queuefront \n 4 forqueuerear \n 5 for empty q \n 6 for full q \n 7 for q count \n 8 for display " << endl;
    int choice, again, data, dataout;
   
    do
    {
        cout << "enter choice ";
            cin >> choice;
        switch (choice)
        {
            
        case 1:
            cout << "enter the element to push- ";
            cin >> data;
            q.eq(data);
            break;
        case 2:
            q.dq();
            break;
        case 3:
            q.queuefront(dataout);
            cout << dataout << endl;
            break;
        case 4:
            q.queuerear(dataout);
            cout << dataout << endl;
            break;
        case 5:
            a = q.emptyqueue();
            if (a == true)
            {
                cout << "q is empty" << endl;
            }
            else
            {
                cout << "q is not empty" << endl;
            }
            break;
        case 6:
            b = q.fullqueue();
            if (b == true)
            {
                cout << "q is full" << endl;
            }
            else
            {
                cout << "q is not full" << endl;
            }
            break;
        case 7:
            int n;
            n = q.queuecount();
            cout << n << endl;
            break;
        case 8:
            q.display();
            break;
        default:
            cout << "enter valid choice";
        }
        cout << "enter 1 to continue and 0 to end ";
        cin >> again;
    } while (again);
    return 0;
}