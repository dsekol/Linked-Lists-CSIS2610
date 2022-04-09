
/*****************************************************************************/
/* Skeleton provided by S. Bassil (Spring 2022)                              */
/*                                                                           */
/* Programmer:                                                               */
/*                                                                           */
/* Program: assignment05                                                     */
/*                                                                           */
/* Approximate Completion Time:                                              */
/*****************************************************************************/

/*
   This program builds a linked list and traverses it iteratively.
*/

#include <iostream>
using namespace std;

/* declaration of structure */
struct node{
	int data;
	node *next = nullptr;
};

/* functions prototypes */
node* insert_node(node *ptr, node *new_ptr);
node* find_node(node *ptr, int n, bool success_flag);
node* delete_node(node *ptr, int n, bool success_flag);
void print_backward(node *ptr);

int main()
{
	// Write your code here
  
  node* head = nullptr; //points to the front of the list
  
  int menuSelect;
  bool flag = false;
  node *tempNode;
  
  do{
    cout << "\n\n1  Insert integer into linked list\n";
    cout << "2  Find integer in linked list\n";
    cout << "3  Delete integer from linked list\n";
    cout << "4  Print out integers backwards\n";
    cout << "5  Quit\n";
    cout << "\nEnter 1, 2, 3, 4, or 5: ";
    cin >> menuSelect;
    
    switch(menuSelect){
      case 1:{
        
        tempNode = new node;

        cout << "Enter an integer to be added to the list: ";
        cin >> tempNode->data;
        head = insert_node(head, tempNode);
        break;
      }
      case 2:{
        
        int search;

        cout << "Input the integer you would like to search for: ";
        cin >> search;
        find_node(head, search, flag);

        break;}
      case 3:{
        int findDelete;
        cout << "Which integer would you like to delete? ";
        cin >> findDelete;
        
        delete_node(head, findDelete, flag);

        break;}
      case 4:{
        print_backward(head);
        break;}
      case 5:{
        cout << "\nProgram Ended.\n";
        break;}
      default:{
        cout << "Please enter a valid option,\n" << 
                "1, 2, 3, 4, or 5: ";
        
        break;
      }
    }
  } while(menuSelect != 5);
	
  
  return 0;
}

/******************************************************************************/
/* Function: insert_node                                                      */
/*                                                                            */
/* Description: Write a brief description of what the function does           */
/*                                                                            */
/* Data in: ptr to first node in linked list, ptr to the node to be inserted  */
/*                                                                            */
/* Data out: ptr to the first node in new linked list                         */
/******************************************************************************/

node* insert_node(node *ptr, node *new_ptr)
{
    node* current = ptr;
    if (current){

        while(current->next){
            current = current->next;
        }

        current->next = new_ptr;
        new_ptr->next = nullptr;
    }
    else{
        ptr = new_ptr;
    }

    return ptr;
}



/******************************************************************************/
/* Function: find_node                                                        */
/*                                                                            */
/* Description: Write a brief description of what the function does           */
/*                                                                            */
/* Data in: ptr to first node in linked list, the integer searching for       */
/*                                                                            */
/* Data out: ptr to the node with data equals to integer searched for,        */
/*           nullptr if integer searched for was not found                    */
/******************************************************************************/

node* find_node(node *ptr, int n, bool success_flag)
{
    node* current = ptr;

    while(current->next){
        current = current->next;
        
        if(current->data == n){
            cout << "\nI found your integer!\n";
            success_flag = true;
            return current;

        }
    }
    cout << "I could not find your integer.\n";
}

/******************************************************************************/
/* Function: delete_node                                                      */
/*                                                                            */
/* Description: Write a brief description of what the function does           */
/*                                                                            */
/* Data in: ptr to first node in linked list, the integer searching for,      */
/*          flag to be set to:                                                */
/*            - true if integer was found and corresponding node deleted      */
/*            - false otherwise                                               */
/*                                                                            */
/* Data out: ptr to the first node in new linked list                         */
/******************************************************************************/

node* delete_node(node *ptr, int n, bool success_flag)
{
    node *current = ptr;
    node *temp = current;
    if(current){
        while(current->data == n){
            current = current->next;

            if(current->data == n){
                cout << "\nI found your integer!\n";
                success_flag = true;
           }
    }   temp->next = NULL;


    } else {
        cout << "There is no data in this list\n";
    }
}
/******************************************************************************/
/* Function: print_backward                                                   */
/*                                                                            */
/* Description: Write a brief description of what the function does           */
/*                                                                            */
/* Data in: ptr to first node in linked list                                  */
/*                                                                            */
/* Data out: none                                                             */
/******************************************************************************/

void print_backward(node *ptr)
{
    
    int count = 0;
    node* current = ptr;
    if(current){
        while(current->next != nullptr){
            current = current->next;
            count++;
        }

        cout << "nullptr <- " << current->data;

        for(int i = count - 1; i > -1; i--){
            current = ptr;
            for(int j = 0; j < i; j++){

                current = current->next;

            }
            cout << " <- " << current->data;
        }

    }else{
        cout << "This is an empty list.\n";
        count = -1;
    }
}
