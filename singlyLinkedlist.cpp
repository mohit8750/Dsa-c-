#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};

node *insertbegin(node *head, int x)
{
    node *temp = new node(x);
    temp->next = head;
    return temp;
}

node *insertEnd(node *head, int x)
{
    node*temp = new node(x);
    if (head == NULL)
        return temp;
    node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}

node *deleteHead(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        node *temp = head->next;
        delete head;
        return temp;
    }
}


node*dellast(node*head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    node *curr = head;
    while (curr->next->next != NULL)
    {
        curr = curr->next;
        
    }
    delete curr->next;
        curr->next = NULL;
        return head;
   
}

// recursive print
void rprint(node *head)
{
    if (head == NULL)
        return;
    else
    {
        cout << (head->data) << " ";
    }
    rprint(head->next);
}

void printlist(node *head)
{
    node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main()
{
    node *head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);
    printlist(head);
    cout<<endl;
   head= insertbegin(head, 40);
   head=insertEnd(head,50);
   
    printlist(head);
    cout<<endl;
    
    head=deleteHead(head);
    printlist(head);
    cout<<endl;

    head=dellast(head);
    printlist(head);
    return 0;
}
