#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class LinkedList {
    private:
        Node* head;
        Node* tail;
    public:
        LinkedList() {
            head = NULL;
            tail = NULL;
        }
        
        void addNode(int value) {
            Node* newNode = new Node;
            newNode->data = value;
            newNode->prev = NULL;
            newNode->next = NULL;
            if (head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }
        
        int search(int value) {
            int index = 0;
            Node* temp = head;
            while (temp != NULL) {
                if (temp->data == value) {
                    return index;
                }
                temp = temp->next;
              index++;
            }
            return -1;
        }
};

int main() {
    LinkedList list;
    list.addNode(1);
    list.addNode(8);
    list.addNode(54);
    list.addNode(40);
    list.addNode(3);
    list.addNode(345);

  //Test1
    int searchValue = 3;
    int result = list.search(searchValue);
    if (result == -1) {
      cout << "Value: " << searchValue << " not found" <<".\n";
    }
    else {
      cout << "Value: " << searchValue << " found. Index: " << result <<".\n";
    };
  //Test2
  searchValue = 228;
  result = list.search(searchValue);
    if (result == -1) {
      cout << "Value: " << searchValue << " not found." <<"\n";
    }
    else {
      cout << "Value: " << searchValue << " found. index: " << result <<"\n";
    }
  return 0;
}
