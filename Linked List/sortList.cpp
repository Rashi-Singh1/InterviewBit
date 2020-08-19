#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* sortList(ListNode* A) {
    int s = 0;
    ListNode *cur = A, *head = A;
    while(cur){
        s++;
        cur = cur->next;
    }
    for(int i = 1 ; i <= s/2; i = i<<1){
        ListNode* print = head;
        while(print){
            cout<<print->val<<" ";
            print = print->next;
        }
        cout<<endl;
        ListNode* left = head, *right = head, *lprev = NULL, *rprev = NULL, *lnext = NULL, *rnext = NULL;
        while(left){
            int count = 0;
            while(right && count < i){
                rprev = right;
                right = right->next;
                count++;
            }
            count = 0;
            ListNode* temp = NULL;
            bool path1 = true;
            if(right){
                while(left && right && count < i){
                    rnext = right->next;
                    lnext = left->next;
                    if(left->val <= right->val){
                        path1 = true;
                        lprev = left;
                        left = lnext;
                        lnext = left == NULL ? NULL : left->next;
                    }else{
                        path1 = false;
                        if(rprev) rprev->next = rnext;
                        if(right) right->next = left;
                        if(lprev) lprev->next = right;
                        else head = right;
                        lprev = right;
                    }
                    right = rnext;
                    count++;
                }
                if(path1 == false) lprev = rprev;
                else lprev = right;
                left = rnext;
            }else left = NULL;
        }
    }
    return head;
}

int main(int argc, char const *argv[])
{
    // vector<int> A = {9, 8, 7, 4, 5, 3, 0, 2, 1};
    vector<int> A = {9, 8, 7, 4, 5, 3, 0, 2, 1, 7, 4, 5, 3, 9, 8, 7, 4, 2};
    ListNode* head = NULL, *root = NULL;
    for(auto x : A){
        if(head) {
            head->next = new ListNode(x);
            head = head->next;
        }
        else{
            root = head = new ListNode(x);
        }
    }
    root = sortList(root);
    while(root){
        cout<<root->val<<" ";
        root = root->next;
    }
    cout<<endl;
    return 0;
}
