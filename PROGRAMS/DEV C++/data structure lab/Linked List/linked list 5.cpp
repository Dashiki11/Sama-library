#include <iostream>
#include <cstdlib>
using namespace std;
struct node
{
 int data;
 struct node *next;
};
struct node * createNode(int);
struct node * movebackwardlist(struct node *, int);
struct node * moveforwardlist(struct node *, int);
void insertAfter(struct node *, int);
void display(struct node *);

int main(void)
{   
    struct node *header = NULL;

    cout << "Insert Front: (8)" << endl;
    header = moveforwardlist(header, 8);
    display(header);
    cout << endl;

    cout << "Insert Front: (3)" << endl;
    header = moveforwardlist(header, 3);
    display(header);  
    cout << endl;

    cout << "Insert Back: (1)" << endl;
    header = movebackwardlist(header, 1);
    display(header);   
    cout << endl;

    cout << "Insert After header: (6)" << endl;
    insertAfter(header, 6);
    display(header);       
    cout << endl;

    return 0;
}
struct node * createNode(int item)
{
     struct node * temp;
     temp = (struct node *) malloc(sizeof(node));
     temp->data = item;
     temp->next = NULL;
     return temp;
}

void insertAfter(struct node *afterNode, int data)
{
     // 1. Create node
     struct node * temp = createNode(data);
     // 2. Connect new node after the AfterNode
     temp->next=afterNode->next;
     // 3. Change the AfterNode pointer value so 
     //that it points to the new node.
     afterNode->next = temp;
}

struct node * movebackwardlist(struct node *header, int data)
{
       // 1. Create node
       struct node * temp = createNode(data);
       struct node * headertemp;
       // 2. Check if the list is empty
       if (header == NULL)
       {
          header = temp;
          return header;
       }
       // 3. Find the end of list
       headertemp=header;

       while(headertemp->next != NULL)
            headertemp=headertemp->next;
       // 4. Connect new node to the end of list.
       headertemp->next = temp;
       // 5. Return header
       return header;
}

struct node * moveforwardlist(struct node *header, int data)
{
     // 1. Create node
     struct node * temp = createNode(data);
     // 2. Connect new node to the front of the list
     temp->next = header;
     // 3. Change the header value so that it points 
     // to the beginning of the LL.
     header=temp;
     // 4. Return new header
     return header;
}

void display(struct node *header)
{
    if (header == NULL)
        cout << "List is empty" << endl;
        
    struct node *temp = header;

    while (temp != NULL)
    {
        cout << temp->data << " --> ";
        temp=temp->next;
    }
    cout << endl;
}


