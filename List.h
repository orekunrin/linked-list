#ifndef LIST_H
#define LIST_H


class List
{
    public:         // this is where the function prototype go. Manipulates data in private section
        /** Default constructor */
        List();     // set default values
        void AddNode(int addData);
        void DeleteNode(int delData);       // whatever value is passed to this function will be deleted, effectively deleting the node
        void PrintList();



    private:        // can only be accessed by functions which we define later
        struct node{
            int data;       // each node will have an integer. Stores data of each node
            node* next;     // node pointer inside each node which points to the next node in the list
        };

        typedef struct node* nodePtr;       // every time you type in nodePtr, it will be the same as typing struct node. It refers to both int and node*

        nodePtr head;
        nodePtr curr;
        nodePtr temp;
};

#endif // LIST_H
