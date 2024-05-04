#include <iostream>

struct Node
{
    int value;
    Node *nxtPtr;
};

class LinkedList
{

    Node *head = new Node();

public:
    LinkedList(int value)
    {
        head->value = value;
    }

    int insert(int a)
    {
        Node *first = new Node();
        first->value = a;
        Node *temp = head;
        while (true)
        {
            if (temp->nxtPtr == NULL)
            {
                temp->nxtPtr = first;
                break;
            }
            temp = temp->nxtPtr;
        }
        return 0;
    }

    void traverse()
    {
        Node *temp = head;
        while (true)
        {
            std::cout << temp->value << std::endl;
            if (temp->nxtPtr == NULL)
            {
                break;
            }
            temp = temp->nxtPtr;
        }
    }

    int deletion(int num)
    {
        Node *temp = head;
        Node *next = head->nxtPtr;


		if (head->value == num){
			head = head->nxtPtr;
			delete(temp);
			return 0;
		}

        while (temp->nxtPtr != NULL)
        {
            if (next->value == num)
            {
                Node *del = next;
                temp->nxtPtr = next->nxtPtr;
                delete (del);
                break;
            }

            temp = temp->nxtPtr;
            next = next->nxtPtr;
        }
		return 0;
    }

    void sort()
    {
        Node *temp1 = head;
        Node *temp2 = head;
		int temp;
        while (temp1 != NULL)
        {
			temp2 = temp1;
            while (temp2 != NULL)
            {
                if (temp1->value > temp2->value)
                {
					temp = temp1 -> value;
					temp1 -> value = temp2->value;
					temp2 -> value = temp;
                }
                temp2 = temp2->nxtPtr;
            }
            temp1 = temp1->nxtPtr;
        }
    }
};


int main () {
	LinkedList l1 = LinkedList(4);
	l1.insert(8);
	l1.insert(2);
	l1.insert(5);
	l1.insert(11);
	l1.deletion(4);
	l1.sort();
	l1.traverse();


}

