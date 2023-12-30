#include <iostream>
using namespace std;
 
// Representation of a node
struct Node 
{
    int data;
    struct Node* next;
};
 
// Function to insert node
void insert(Node** head, int item)
{
    Node* temp = new Node;
    Node* ptr;
    temp->data = item;
    temp->next = NULL;
 
    if (*head == NULL)
        *head = temp;
    else {
        ptr = *head;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}
 
void display(Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
 
Node *loadlist(int arr[], int n)
{
    Node *head = NULL;
    for (int i = 0; i < n; i++)
        insert(&head, arr[i]);
   return head;
}
 
// Driver code
int main()
{
    int arr[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* head = loadlist(arr, n);
    display(head);
    return 0;
}
