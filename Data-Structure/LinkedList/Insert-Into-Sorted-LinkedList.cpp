#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedListNode
{
public:
    int data;
    DoublyLinkedListNode *next;
    DoublyLinkedListNode *prev;

    DoublyLinkedListNode(int node_data)
    {
        this->data = node_data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList
{
public:
    DoublyLinkedListNode *head;
    DoublyLinkedListNode *tail;

    DoublyLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int node_data)
    {
        DoublyLinkedListNode *node = new DoublyLinkedListNode(node_data);

        if (!this->head)
        {
            this->head = node;
        }
        else
        {
            this->tail->next = node;
            node->prev = this->tail;
        }

        this->tail = node;
    }
};

void print_doubly_linked_list(DoublyLinkedListNode *node, string sep, ofstream &fout)
{
    while (node)
    {
        fout << node->data;

        node = node->next;

        if (node)
        {
            fout << sep;
        }
    }
}

void free_doubly_linked_list(DoublyLinkedListNode *node)
{
    while (node)
    {
        DoublyLinkedListNode *temp = node;
        node = node->next;

        free(temp);
    }
}

/*
 * Complete the 'sortedInsert' function below.
 *
 * The function is expected to return an INTEGER_DOUBLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_DOUBLY_LINKED_LIST llist
 *  2. INTEGER data
 */

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */

DoublyLinkedListNode *sortedInsert(DoublyLinkedListNode *llist, int data)
{
    if (llist->data > data)
    {
        DoublyLinkedListNode *node = new DoublyLinkedListNode(data);
        node->next = llist;
        llist->prev = node;
        llist = node;
        return llist;
    }

    DoublyLinkedListNode *first = llist;
    DoublyLinkedListNode *second = llist->next;

    while (second->data <= data && second->next != NULL)
    {
        first = first->next;
        second = second->next;
    }

    DoublyLinkedListNode *node = new DoublyLinkedListNode(data);

    if (second->data >= data)
    {
        node->next = second;
        first->next = node;
        second->prev = node;
        node->prev = first;
        return llist;
    }

    else
    {
        second->next = node;
        node->prev = second;
        return llist;
    }
}