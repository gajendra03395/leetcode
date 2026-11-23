class Solution {
public:
    struct Node
    {
        int data;
        Node* next;
        Node* prev;
    };
    Node* stringToList(const string& s) {
        Node* head = NULL;
        Node* tail = NULL;
        for (char c : s) {
            Node* n = new Node;
            n->data = c - '0';
            n->next = NULL;
            n->prev = tail;
            if (tail != NULL) {
                tail->next = n;
            } else {
                head = n;
            }
            tail = n;
        }
        return head;
    }
    string listToString(Node* head) {
        string res = "";
        while (head != NULL) {
            res += to_string(head->data);
            head = head->next;
        }
        return res.empty() ? "0" : res;
    }
    Node* addSum(Node*a , Node* b)
    {
        Node* p = a;
        Node* q = b;
        Node* result = NULL;
        int carry = 0 ;
        while(p != NULL && p->next != NULL) p = p->next;
        while(q != NULL && q->next != NULL) q = q->next;

        while(p!=NULL || q!=NULL || carry)
        {
            int sum = carry;
            if(p != NULL)
            {
                sum += p->data;
                p = p->prev;
            }
            if(q != NULL)
            {
                sum += q->data;
                q = q->prev;
            }
            Node* n = new Node();
            n->data = sum % 2;
            n->prev = NULL;
            n->next = result;
            if(result != NULL)
            {
                result->prev = n;
            }
            result = n;
            carry = sum/2;

        }
        return result;
    }
    string addBinary(string a, string b) {
        Node* listA = stringToList(a);
        Node* listB = stringToList(b);
        
        Node* sumList = addSum(listA, listB);
        
        return listToString(sumList);

       
    }
};