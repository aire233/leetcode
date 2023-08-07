class MyLinkedList
{
private:
    ListNode *head;

public:
    MyLinkedList()
    {
        head = new ListNode(0);
    }

    int get(int index)
    {
        ListNode *p = head->next;
        while (p && index > 0)
        {
            p = p->next;
            index--;
        }
        return p ? p->val : -1;
    }

    void addAtHead(int val)
    {
        ListNode *p = new ListNode(val);
        p->next = head->next;
        head->next = p;
    }

    void addAtTail(int val)
    {
        ListNode *p = head;
        while (p->next)
        {
            p = p->next;
        }
        p->next = new ListNode(val);
    }

    void addAtIndex(int index, int val)
    {
        ListNode *p = head;
        while (p && index > 0)
        {
            p = p->next;
            index--;
        }
        if (p)
        {
            ListNode *tmp = p->next;
            p->next = new ListNode(val);
            p->next->next = tmp;
        }
    }

    void deleteAtIndex(int index)
    {
        ListNode *p = head;
        while (p && index > 0)
        {
            p = p->next;
            index--;
        }
        if (p && p->next)
        {
            ListNode *tmp = p->next;
            p->next = p->next->next;
            delete tmp;
        }
    }
};

class MyLinkedList {
private:
    ListNode* head;
    int size;

public:
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }
        ListNode* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->val;
    }

    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            ListNode* tail = head;
            while (tail->next) {
                tail = tail->next;
            }
            tail->next = newNode;
        }
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            return;
        }
        if (index == 0) {
            addAtHead(val);
        } else if (index == size) {
            addAtTail(val);
        } else {
            ListNode* newNode = new ListNode(val);
            ListNode* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            size++;
        }
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        ListNode* toDelete;
        if (index == 0) {
            toDelete = head;
            head = head->next;
        } else {
            ListNode* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            toDelete = current->next;
            current->next = current->next->next;
        }
        delete toDelete;
        size--;
    }
};

    /**
     * Your MyLinkedList object will be instantiated and called as such:
     * MyLinkedList* obj = new MyLinkedList();
     * int param_1 = obj->get(index);
     * obj->addAtHead(val);
     * obj->addAtTail(val);
     * obj->addAtIndex(index,val);
     * obj->deleteAtIndex(index);
     */