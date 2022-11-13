#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

    SinglyLinkedListNode *result=NULL,*p=NULL;

    // Deklarasi Data pertama
    if(head1->data < head2->data){
        p=head1;
        result = p;
        head1=head1->next;
        p->next=NULL;
    }
    else {
        p=head2;
        result = p;
        head2=head2->next;
        p->next=NULL;
    }

    // Loop Semua data head1 dan 2
    while(head1!=NULL && head2!=NULL)
    {
        // jika head1 lebih kecil masukkan ke result dan head1=next(head1)
        if(head1->data < head2->data)
        {
            p->next = head1;
            p=head1;
            head1=head1->next;
            p->next=NULL;
        }
        else 
        { // jika head2 lebih kecil masukkan ke result dan head2=next(head2)
            p->next=head2;
            p=head2;
            head2=head2->next;
            p->next=NULL;
        }
    }

    // cek head1 jika tidak null maka masukkan seluruh data di head1 
    if(head1!=NULL)
    {
        p->next=head1;
    }
    else { // cek head2 jika tidak null maka masukkan seluruh data di head2 
        p->next=head2;
    }
    return result;
}
