#include <vector>
#include <initializer_list>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reorderList(ListNode* head) {
    vector<ListNode*> vec;
    for (ListNode* node = head; node != nullptr; node = node->next) {
        vec.push_back(node);
    }

    int low = 0, high = vec.size() - 1;
    ListNode new_head, *node = &new_head;
    while (low <= high) {
        node->next = vec[low];
        node = node->next;
        ++low;
        if (low <= high) {
            node->next = vec[high];
            node = node->next;
            --high;
        }
    }
    node->next = nullptr;
}

ListNode* middle(ListNode*);
ListNode* reverse(ListNode*);
void merge(ListNode*, ListNode*);

void reorderList(ListNode* head, int) {
    if (head == nullptr) {
        return;
    }
    ListNode* mid = middle(head);
    ListNode *l2 = mid->next;
    mid->next = nullptr;
    l2 = reverse(l2);
    merge(head, l2);
}

ListNode* middle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* reverse(ListNode* head) {
    ListNode new_head, *node = &new_head;
    while (head != nullptr) {
        ListNode* temp = head->next;
        head->next = node->next;
        node->next = head;
        head = temp;
    }
    return new_head.next;
}

void merge(ListNode* l1, ListNode* l2) {
    ListNode head, *node = &head;
    while (l1 != nullptr && l2 != nullptr) {
        ListNode* temp = l1->next;
        node->next = l1;
        node = l1;
        l1 = temp;
        temp = l2->next;
        node->next = l2;
        node = l2;
        l2 = temp;
    }
    if (l1 != nullptr) {
        node->next = l1;
    }
}

ListNode* create_list(const initializer_list<int> &list)
{
    ListNode head, *node = &head;
    for (auto &v : list) {
        node->next = new ListNode(v);
        node = node->next;
    }
    node->next = nullptr;
    return head.next;
}

void free_list(ListNode *head)
{
    while (head != nullptr) {
        ListNode* temp = head->next;
        delete head;
        head = temp;
    }
}

ostream& operator<< (ostream& os, ListNode *head)
{
    while (head != nullptr) {
        os << head->val;
        head = head->next;
        if (head != nullptr) {
            os << "->";
        }
    }
    return os;
}

int main()
{
    ListNode* head = create_list({1, 2, 3, 4, 5});
    cout << head << endl;
    reorderList(head, 1);
    cout << head << endl;
    free_list(head);
}
