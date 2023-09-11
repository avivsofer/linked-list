#include <stdio.h>
#include <iostream>

class Node { //יצירת צומת ברשימה
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
            std::cout << current->data;
            current = current->next;
        }
        std::cout << std::endl;
    }



    bool is_ww(LinkedList l) { //פונקציה לבדיקה האם זה ww
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


int main() {      //הפעלת הפונקציות שבנינו על המחרוזות שהתבקשנו לבדוק והוצאת פלט בהתאם לתוצאה

    std::string str1 = "ababaababbababaaaababb";
    std::string str2 = "abbabbabbaaaaabbabbabba";
    std::string str3 = "baabaaabbabbabbaabaaabbabbab";
    std::string str4 = "abbabbaabbabba";

    LinkedList List1;
    for (char c : str1) {
        List1.append(c);
    }

    LinkedList List2;
    for (char c : str2) {
        List2.append(c);
    }

    LinkedList List3;
    for (char c : str3) {
        List3.append(c);
    }

    LinkedList List4;
    for (char c : str4) {
        List4.append(c);
    }




    std::cout << std::endl << std::endl << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Question 1 - Part one ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << std::endl << std::endl;



    bool answer1 = List1.is_ww(List1);              // בדיקת מחרוזת ראשונה
    if (answer1)
    {
        std::cout << " $~~  First string check  ~~$ " << std::endl;
        std::cout << " LinkedList: ";
        List1.display();
        std::cout << " This is A WW type linked list" << std::endl << std::endl;
    }
    else
    {
        std::cout << " $~~  First string check  ~~$ " << std::endl;
        std::cout << " LinkedList: ";
        List1.display();
        std::cout << " This is NOT a WW type linked list" << std::endl << std::endl;
    }


    bool answer2 = List2.is_ww(List2);              // בדיקת מחרוזת שניה 
    if (answer2)
    {
        std::cout << " $~~  Second string check  ~~$ " << std::endl;
        std::cout << " LinkedList: ";
        List2.display();
        std::cout << " This is A WW type linked list" << std::endl << std::endl;
    }
    else
    {
        std::cout << " $~~  Second string check  ~~$ " << std::endl;
        std::cout << " LinkedList: ";
        List2.display();
        std::cout << " This is NOT a WW type linked list" << std::endl << std::endl;
    }


    bool answer3 = List3.is_ww(List3);              // בדיקת מחרוזת שלישית
    if (answer3)
    {
        std::cout << " $~~  Third string check  ~~$ " << std::endl;
        std::cout << " LinkedList: ";
        List3.display();
        std::cout << " This is A WW type linked list" << std::endl << std::endl;
    }
    else
    {
        std::cout << " $~~  Third string check  ~~$ " << std::endl;
        std::cout << " LinkedList: ";
        List3.display();
        std::cout << " This is NOT a WW type linked list" << std::endl << std::endl;
    }


    bool answer4 = List4.is_ww(List4);              // בדיקת מחרוזת רביעית
    if (answer4)
    {
        std::cout << " $~~  Fourth string check  ~~$ " << std::endl;
        std::cout << " LinkedList: ";
        List4.display();
        std::cout << " This is A WW type linked list" << std::endl << std::endl;
    }
    else
    {
        std::cout << " $~~  Fourth string check  ~~$ " << std::endl;
        std::cout << " LinkedList: ";
        List4.display();
        std::cout << " This is NOT a WW type linked list" << std::endl << std::endl;
    }


    std::cout << std::endl << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Question 2 - Part Two ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << std::endl << std::endl;




    std::cout << " $~~  First string check  ~~$ " << std::endl;
    std::cout << " LinkedList: ";
    List2.display();
   
    bool answer1b = List1.is_palindrome();              // בדיקה של הרשימה מקושרת הראשונה, האם הוא מסוג פולינדרום
    if (answer1b)
    {
        std::cout << " This is a palindrome!" << std::endl << std::endl;
    }
    else
    {
        std::cout << " This is not a palindrome " << std::endl << std::endl;
    }   


    std::cout << " $~~  Second string check  ~~$ " << std::endl;
    std::cout << " LinkedList: ";
    List2.display();

    bool answer2b = List2.is_palindrome();              // בדיקה של הרשימה מקושרת השניה, האם הוא מסוג פולינדרום 
    if (answer2b)
    {
        
        std::cout << " This is a palindrome!" << std::endl << std::endl;
    }
    else
    {
        std::cout << " This is not a palindrome " << std::endl << std::endl;
    }


    std::cout << " $~~  Third string check  ~~$ " << std::endl;
    std::cout << " LinkedList: ";
    List3.display();

    bool answer3b = List3.is_palindrome();              // בדיקה של הרשימה מקושרת השלישית, האם הוא מסוג פולינדרום
    if (answer3b)
    {
        std::cout << " This is a palindrome!" << std::endl << std::endl;
    }
    else
    {
        std::cout << " This is not a palindrome " << std::endl << std::endl;
    }


    std::cout << " $~~  Fourth string check  ~~$ " << std::endl;
    std::cout << " LinkedList: ";
    List4.display();

    bool answer4b = List4.is_palindrome();              // בדיקה של הרשימה מקושרת הרביעית, האם הוא מסוג פולינדרום
    if (answer4b)
    {
        std::cout << " This is a palindrome!" << std::endl << std::endl;
    }
    else
    {
        std::cout << " This is not a palindrome " << std::endl << std::endl;
    }


    return 0;
}