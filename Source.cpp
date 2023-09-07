#include <stdio.h>
#include <iostream>

class Node {
public:
    char data;
    Node* next;

    Node(char value) : data(value), next(nullptr) {}
};


class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void append(char value) {
        Node* newNode = new Node(value);

        if (!head) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void display() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    bool is_ww(LinkedList l) {
        Node* fast = l.head;
        Node* slow = l.head;


        while (fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast->next == nullptr)
                break;


            fast = fast->next;
            if (fast->next == nullptr)    // The LinkedList is odd
                return false;
        }

        fast = l.head;
        while (slow->next != nullptr)
        {
            if (fast->data != slow->data)
                return false;
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }


    bool is_palindrome() {
        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* prev = nullptr;
        Node* current = slow;
        Node* next;

        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        Node* firstHalf = head;
        Node* secondHalf = prev;

        while (secondHalf) {
            if (firstHalf->data != secondHalf->data) {
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;
    }


};

//
//    bool is_palindrome() {
//        Node* fast = this->head;
//        Node* slow = this->head;
//        Node* p = nullptr;
//        Node* changer = new Node('a');
//        bool OddFlag = false;
//
//
//        while (fast->next != nullptr)
//        {
//            p = slow;
//            slow = slow->next;
//            p->next = changer;
//            changer = p;
//
//            fast = fast->next;
//            if (fast->next == nullptr)
//                break;
//
//
//            fast = fast->next;
//            if (fast->next == nullptr)    // The LinkedList is odd
//                OddFlag = true;
//        }  
//
//        // now slow is pointing to the middle, and the first half is connected upside down
//
//        p = p->next;
//        if (OddFlag)
//           slow = slow->next;
//            
//        while (slow->next != nullptr)
//        {
//            if (p->data != slow->data)
//                return false;
//            p = p->next;
//            slow = slow->next;
//        }
//        return true;
//    }
//
//};

int main() {
    LinkedList myList1;
    LinkedList myList2;
    LinkedList myList3;
    LinkedList myList4;
    LinkedList myList5;

    myList1.append('a');
    myList1.append('b');
    myList1.append('a');
    myList1.append('b');
    myList1.append('a');
    myList1.append('a');
    myList1.append('b');
    myList1.append('a');
    myList1.append('b');
    myList1.append('b');
    myList1.append('a');
    myList1.append('b');
    myList1.append('a');
    myList1.append('b');
    myList1.append('a');
    myList1.append('a');
    myList1.append('a');
    myList1.append('a');
    myList1.append('b');
    myList1.append('a');
    myList1.append('b');
    myList1.append('b');

    myList2.append('a');
    myList2.append('b');
    myList2.append('b');
    myList2.append('a');
    myList2.append('b');
    myList2.append('b');
    myList2.append('a');
    myList2.append('b');
    myList2.append('b');
    myList2.append('a');
    myList2.append('a');
    myList2.append('a');
    myList2.append('a');
    myList2.append('a');
    myList2.append('b');
    myList2.append('b');
    myList2.append('a');
    myList2.append('b');
    myList2.append('b');
    myList2.append('a');
    myList2.append('b');
    myList2.append('b');
    myList2.append('a');

    myList3.append('b');
    myList3.append('a');
    myList3.append('a');
    myList3.append('b');
    myList3.append('a');
    myList3.append('a');
    myList3.append('a');
    myList3.append('b');
    myList3.append('b');
    myList3.append('a');
    myList3.append('b');
    myList3.append('b');
    myList3.append('a');
    myList3.append('b');
    myList3.append('b');
    myList3.append('a');
    myList3.append('a');
    myList3.append('b');
    myList3.append('a');
    myList3.append('a');
    myList3.append('a');
    myList3.append('b');
    myList3.append('b');
    myList3.append('a');
    myList3.append('b');
    myList3.append('b');
    myList3.append('a');
    myList3.append('b');

    myList4.append('a');
    myList4.append('b');
    myList4.append('b');
    myList4.append('a');
    myList4.append('b');
    myList4.append('b');
    myList4.append('a');
    myList4.append('a');
    myList4.append('b');
    myList4.append('b');
    myList4.append('a');
    myList4.append('b');
    myList4.append('b');
    myList4.append('a');



    bool answer1 = myList1.is_ww(myList1);              // chcking first LinkedList
    if (answer1)
    {
        std::cout << "The LinkedList:";
        myList1.display();
        std::cout << "is a WW list" << std::endl << std::endl;
    }
    else
        std::cout << " The first LinkedList is not a WW list" << std::endl << std::endl;

    bool answer2 = myList2.is_ww(myList2);              // chcking second LinkedList 
    if (answer2)
    {
        std::cout << "The LinkedList:";
        myList2.display();
        std::cout << "is a WW list" << std::endl << std::endl;
    }
    else
        std::cout << " The second LinkedList is not a WW list" << std::endl << std::endl;

    bool answer3 = myList3.is_ww(myList3);              // chcking third LinkedList
    if (answer3)
    {
        std::cout << "The LinkedList:";
        myList3.display();
        std::cout << "is a WW list" << std::endl << std::endl;
    }
    else
        std::cout << " The third LinkedList is not a WW list" << std::endl << std::endl;

    bool answer4 = myList4.is_ww(myList4);              // chcking forth LinkedList
    if (answer4)
    {
        std::cout << "The LinkedList:";
        myList4.display();
        std::cout << "is a WW list" << std::endl << std::endl;
    }
    else
        std::cout << " The forth LinkedList is not a WW list" << std::endl << std::endl;

    std::cout << std::endl << std::endl << "--------------------------------------second part--------------------------------------" << std::endl << std::endl;

    bool answer1b = myList1.is_palindrome();              // chcking first LinkedList
    if (answer1b)
    {
        std::cout << "The first LinkedList is a palindrome!!!" << std::endl << std::endl << std::endl;
    }
    else
        std::cout << " The first LinkedList is not a palindrome :(" << std::endl << std::endl << std::endl;

    bool answer2b = myList2.is_palindrome();              // chcking second LinkedList 
    if (answer2b)
    {
        std::cout << "The second LinkedList is a polindrom!!!" << std::endl << std::endl << std::endl;
    }
    else
        std::cout << " The second LinkedList is not a palindrome :(" << std::endl << std::endl << std::endl;

    bool answer3b = myList3.is_palindrome();              // chcking third LinkedList
    if (answer3b)
    {
        std::cout << "The third LinkedList is a palindrome!!!" << std::endl << std::endl << std::endl;
    }
    else
        std::cout << " The third LinkedList is not a palindrome :(" << std::endl << std::endl << std::endl;

    bool answer4b = myList4.is_palindrome();              // chcking forth LinkedList
    if (answer4b)
    {
        std::cout << "The forth LinkedList is a palindrome!!!" << std::endl << std::endl << std::endl;
    }
    else
        std::cout << " The forth LinkedList is not a palindrome :(" << std::endl << std::endl;

    return 0;
}