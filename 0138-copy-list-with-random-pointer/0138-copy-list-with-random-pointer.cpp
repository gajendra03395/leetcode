/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
        {
            return NULL;
        }
        unordered_map<Node*,Node*>m;
        Node* newhead = new Node(head->val);
        Node* oldtemp = head->next;
        Node* newtemp = newhead;
        m[head] = newhead;

        while(oldtemp != NULL)
        {
            Node* copynode = new Node(oldtemp->val);
            m[oldtemp] = copynode;
            newtemp->next = copynode;
            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }
        oldtemp = head; newtemp = newhead;
        while(oldtemp != NULL)
        {
            newtemp->random = m[oldtemp->random];
            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }
        return newhead;
    }
};