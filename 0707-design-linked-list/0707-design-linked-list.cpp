class MyLinkedList {
    struct Node {
        int val;
        Node* next;

        Node(int x) {
            val = x;
            next = nullptr;
        }
    };

    Node* head;

public:
    MyLinkedList() {
        head = nullptr;
    }

    int get(int index) {
        Node* curr = head;

        for (int i = 0; i < index && curr != nullptr; i++) {
            curr = curr->next;
        }

        if (curr == nullptr)
            return -1;

        return curr->val;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* curr = head;

        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = newNode;
    }

    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* curr = head;

        for (int i = 0; i < index - 1 && curr != nullptr; i++) {
            curr = curr->next;
        }

        if (curr == nullptr)
            return;

        Node* newNode = new Node(val);
        newNode->next = curr->next;
        curr->next = newNode;
    }

    void deleteAtIndex(int index) {
        if (head == nullptr)
            return;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* curr = head;

        for (int i = 0; i < index - 1 && curr != nullptr; i++) {
            curr = curr->next;
        }

        if (curr == nullptr || curr->next == nullptr)
            return;

        Node* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
    }
};