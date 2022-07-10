#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node<T> *next;
};

template<class T>
class SinglyCLL
{
    private:
        struct node<T> *Head;
        struct node<T> *Tail;
        int Count;

    public:
        SinglyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPosition(T,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int);
        void Display();
        int CountNode();
};

template<class T>
SinglyCLL<T>::SinglyCLL()
{
    Head = NULL;
    Tail = NULL;
    Count = 0;
}

template<class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    if(Head == NULL && Tail == NULL)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }
    Tail->next = Head;
    Count++;
}

template<class T>
void SinglyCLL<T>::InsertLast(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    if(Head == NULL && Tail == NULL)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        Tail->next = newn;
        Tail = newn;
    }
    Tail->next = Head;

    Count++;
}

template<class T>
void SinglyCLL<T>::Display()
{
    struct node<T> *temp = NULL;
    temp = Head;

    cout<<"Nodes of Singly Circular Linked List are : "<<endl;

    do 
    {
        cout<<"|"<<temp->data<<"| ->";
        temp = temp->next;
    }while(temp != Tail->next);
    cout<<endl;
}

template<class T>
int SinglyCLL<T>::CountNode()
{
    return Count;
}

template<class T>
void SinglyCLL<T>::DeleteFirst()
{
    if(Head == NULL & Tail == NULL)
    {
        return;
    }

    if(Head->next == NULL)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Head = Head->next;
        delete Tail->next;
    }
    Tail->next = Head;

    Count--;
}

template<class T>
void SinglyCLL<T>::DeleteLast()
{
    if(Head == NULL & Tail == NULL)
    {
        return;
    }

    if(Head->next == NULL)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        struct node<T> *temp = Head;

        while(temp->next != Tail)
        {
            temp = temp->next;
        }
        delete temp->next;
        Tail = temp;
    }
    Tail->next = Head;

    Count--;
}

template<class T>
void SinglyCLL<T>::InsertAtPosition(T no, int ipos)
{
    if((ipos < 1) || (ipos > (Count+1)))
    {
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == (Count+1))
    {
        InsertLast(no);
    }
    else
    {
        struct node<T> *newn = NULL;
        newn = new node<T>;
        newn->data = no;
        newn->next = NULL;

        struct node<T> *temp = Head;

        for(int iCnt = 1; iCnt < (ipos-1); iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        Count++;
    }
}

template<class T>
void SinglyCLL<T>::DeleteAtPosition(int ipos)
{
    if((ipos < 1) || (ipos > Count))
    {
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == Count)
    {
        DeleteLast();
    }
    else
    {
        struct node<T> *temp = Head;
        struct node<T> *tempdelete = NULL;

        for(int iCnt = 1; iCnt < (ipos-1); iCnt++)
        {
            temp = temp->next;
        }
        tempdelete = temp->next;
        temp->next = temp->next->next;
        delete tempdelete;

        Count--;
    }
}

// Write your main function(Entry Point Function) here