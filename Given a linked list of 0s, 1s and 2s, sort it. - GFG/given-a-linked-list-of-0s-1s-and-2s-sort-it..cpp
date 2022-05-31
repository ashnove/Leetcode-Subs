// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


 // } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        if(head == NULL) return head;
        
        Node* dummyZero = new Node(0);
        Node* dummyOne = new Node(0);
        Node* dummyTwo = new Node(0);
        
        Node* zero = dummyZero, *one = dummyOne, *two = dummyTwo;
        Node *itr = head;
        while(itr){
            if(itr->data == 0){
                zero->next = itr;
                itr = itr->next;
                zero = zero->next;
            }
            else if(itr->data == 1){
                one->next = itr;
                one = one->next;
                itr = itr->next;
            }
            else if(itr->data == 2){
                two->next = itr;
                two = two->next;
                itr = itr->next;
            }
        }
        
        zero->next = ( dummyOne->next ? dummyOne->next : dummyTwo->next );
        one->next = dummyTwo->next;
        two->next = NULL;
        
        return dummyZero->next;
    }
};


// { Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}  // } Driver Code Ends