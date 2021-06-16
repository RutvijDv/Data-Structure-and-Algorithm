#include <bits/stdc++.h>
using namespace std;

//Queue Based
string FirstNonRepeating(string s)
{

    int n = s.length();
    string res = "";
    queue<char> q;
    unordered_map<char, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;
        if (mp[s[i]] == 1)
            q.push(s[i]);

        while (!q.empty() && mp[q.front()] != 1)
        {
            q.pop();
        }

        res += q.empty() ? '#' : q.front();
    }

    return res;
}

//DLL based Solution
class Solution
{
    struct Node
    {
        char data;
        Node *next;
        Node *prev;

        Node(int x)
        {
            data = x;
            next = NULL;
            prev = NULL;
        }
    };

public:
    void append(Node **head, Node **tail, char x)
    {

        Node *temp = new Node(x);

        if (*head == NULL)
        {
            *head = *tail = temp;
            return;
        }
        (*tail)->next = temp;
        temp->prev = *tail;
        *tail = temp;

        return;
    }

    void del(Node **head, Node **tail, Node *del)
    {

        if (*head == NULL)
            return;

        if (*head == del)
            *head = (*head)->next;
        if (*tail == del)
            *tail = (*tail)->prev;
        if (del->next != NULL)
            del->next->prev = del->prev;
        if (del->prev != NULL)
            del->prev->next = del->next;

        delete (del);

        return;
    }

    string FirstNonRepeating(string s)
    {

        int n = s.length();
        string res = "";
        Node *head = NULL;
        Node *tail = NULL;
        unordered_map<char, Node *> mp;
        unordered_map<char, bool> visited;

        for (int i = 0; i < n; i++)
        {
            if (visited[s[i]] == false)
            {

                if (mp[s[i]] == NULL)
                {
                    append(&head, &tail, s[i]);
                    mp[s[i]] = tail;
                }
                else
                {
                    del(&head, &tail, mp[s[i]]);
                    visited[s[i]] = true;
                }
            }

            if (head == NULL)
            {
                res += '#';
            }
            else
            {
                res += head->data;
            }
        }

        return res;
    }
};