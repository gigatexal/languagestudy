#include <iostream>
using namespace std;

class Llist {
    private:
        struct Node {
            int data;
            Node *next;
            //node *prev;
        };
        Node *head;
        Node *tail;
        int sz;
        void add(Node *head, int data);
        void destroy(Node *&head);
    public:
        Llist();
        ~Llist();
        void add(int data);
        const void print() const;
        int size();
};

int main()
{
    Llist *ll = new Llist();
    ll->add(1);
    ll->add(2);
    ll->add(3);
    ll->add(44);
    ll->print();
    return 0;
}

Llist::Llist(){
    this->head = new Node;
    this->head->next = nullptr;
    this->tail = new Node;
    this->tail->next = nullptr;
    sz = 0;
}

Llist::~Llist(){
    destroy(this->head);
}

void Llist::destroy(Node *&head){
    Node *iter = new Node;
    iter = head->next;
    cout << "del " << endl;
    while (iter){
       cout << "deleted " << endl;
       delete head;
       iter = iter->next;
    }
    delete iter;
}

void Llist::add(Node *head, int data){
    Node *elem = new Node;
    if (this->head){
       cout << "adding an element " << endl;
       elem->next = head->next;
       head->next = elem;
       elem->data = data;
    }

    ++sz;
}

void Llist::add(int data){
    add(this->head,data);
}

const void Llist::print() const {
    Node *iter = new Node;
    iter = this->head;
    while (iter){
       cout << iter->data << endl;
       iter = iter->next;
    }
    delete *&iter;
}
int Llist::size() {
    return this->sz;
}



