#include<iostream>
#include<unordered_set>
using namespace std;

struct node{
    int data;
    node* next;
    node(int val): data(val), next(NULL){}
};
void insertAtHead(node*&head,node*&tail,int val){
    node* newnode = new node(val);
    if(head==NULL){
        head = tail = newnode;
        return;
    }
    newnode->next = head;
    head = newnode;
}
void insertAtTail(node*&head,node*&tail,int val){
    node* newnode = new node(val);
    if(head==NULL){
        head= tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}
void insertAtPosition(node*&head,node*&tail,int pos,int val){
    if(pos<=1){
        insertAtHead(head,tail,val);
        return;
    }
    node* curr = head;
    int cnt = 1;
    while(cnt<pos-1 && curr->next != NULL){
        curr = curr->next;
        cnt++;
    } 
    if(curr->next == NULL){
        insertAtTail(head,tail,val);
        return;
    }  
    else if(curr->next != NULL){
        node* newnode = new node(val);
        newnode->next = curr->next;
        curr->next = newnode;
    }
}
void deleteAtHead(node*&head,node*&tail){
    if(head==NULL) return;
    node*temp = head;
    head = head->next;
    if(head==NULL){
        tail = NULL;
    }
    delete temp;
}
void deleteAtTail(node*&head,node*&tail){
    if(head == NULL) return;
    if(head == tail){
        delete head;
        head = tail =NULL;
        return;
    }
    node* curr = head;
    while(curr->next !=tail){
        curr = curr->next;
    }
    delete tail;
    curr->next = NULL;
    tail = curr;
}
void deleteAtPosition(node*&head,node*&tail,int pos){
    if(pos<=1){
        deleteAtHead(head,tail);
        return;
    }
    node* curr = head;
    int cnt = 1;
    while(cnt<pos-1 && curr->next != NULL){
        curr = curr->next;
        cnt++;
    }
    if(curr->next == tail){
        deleteAtTail(head,tail);
        return;
    }
    else if(curr->next != tail){
        node* nodetodelete = curr->next;
        curr->next = nodetodelete->next;
        delete nodetodelete;
    }

}
node* reverse(node* head){
    if(head==NULL || head->next == NULL) return head;
    node* prev = NULL;
    node* curr = head;
    node* next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
node* recreverse(node* head){
    if(head==NULL || head->next == NULL){
        return head;
    }
    node* newnnode = recreverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newnnode;
}
node* middleElement(node* head){
    node* slow = head;
    node* fast = head;
    while(fast!=NULL || fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
node* hasCYcle(node* head){
    if(head==NULL || head->next == NULL){
        return NULL ;
    }
    node* slow = head;
    node* fast = head;
    while(fast != NULL || fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            return slow;
        }
    }
    return NULL;
}
node * getstartnode(node* head){
    if(head==NULL) return NULL;
    node* inter = hasCYcle(head);
    node* slow = head;
    while(slow != inter){
        slow = slow->next;
        inter = inter->next;
    }
    return slow;

}
node * removeLOOP(node* head){
    if(head==NULL) return NULL;
    node* start = getstartnode(head);
    if(start ==NULL) return head;
    node* temp = start;
    while(temp->next != start){
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}
void removeduplicatesorted(node* head){
    node* curr = head;
    while(curr!=NULL && curr->next != NULL){
        if(curr->data == curr->next->data){
            node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else{
            curr = curr->next;
        }  
    }
}
//using hash set
void removedupliUNSORTED(node* head){
    unordered_set<int> s;
    node* curr = head;
    node* prev = NULL;
    while(curr!=NULL){
        if(s.find(curr->data)!=s.end()){
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else{
            s.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }
}
//using two loops
void removedupli(node* head){
    node* curr = head;
    while(curr != NULL){
        node* runner = curr;
        while(runner->next != NULL){
            if(curr->data == runner->next->data){
                node* temp = runner;
                runner->next = runner->next->next;
                delete temp;
            }
            else{
                runner = runner->next;
            }
        }
        curr = curr->next;
    }
}
bool isPalindrome(node* head){
    if(head==NULL || head->next == NULL){
        return true;
    }
    node* slow = head;
    node* fast = head;
    while(fast->next != NULL && fast->next->next !=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }  
    node* prev = NULL;
    node* curr = slow->next;
    while(curr!=NULL){
        node* NEW = curr->next;
        curr->next = prev;
        prev = curr;
        curr = NEW;
    } 
    node*first = head;
    node*second = prev;
    while(second != NULL){
        if(first->data != second->data){
            return false;
        }
        first = first->next;
        second = second->next;
    }
    return true;
}
int length(node* head){
    if(head==NULL){
        return -1;
    }
    int len = 0;
    while(head != NULL){
        len++;
        head = head->next;
    }
    return len;
}
void printList(node* head){
    node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
//--------------------------------------
//Add two number represented by LL
node* addList(node* l1,node* l2){
    node*head = NULL;
    node* tail = NULL;
    int carry = 0;
    while(l1 || l2 || carry){
        int sum = carry;
        if(l1){
            sum+= l1->data;
            l1 = l1->next;
        }
        if(l2){
            sum+= l2->data;
            l2 = l2->next;
        }
        int digit = sum%10;
        carry = sum/10;
        node* newNode = new node(digit);
        if(!head){
            head = tail =newNode;
        }
        else{
            tail->next = newNode;
            tail =newNode;
        }
    }
    return head;
}
node* addtwoList(node* l1,node* l2){
    l1 = reverse(l1);
    l2 = reverse(l2);
    node* result = addList(l1,l2);
    return reverse(result);
}
//BY using stack
//include<stack>
/*node* addtwo(node* l1, node* l2){
    stack<int> s1 , s2;
    while(l1){
        s1.push(l1->data);
        l1 = l1->next;
    }
    while(l2){
        s2.push(l2->data);
        l2 = l2->next;
    }
    int carry = 0;
    node* head = NULL;
    while(!s1.empty() || !s2.empty() || carry){
        int sum = carry;
        if(!s1.empty()){
            sum += s1.top();
            s1.pop();
        }
        if(!s2.empty()){
            sum += s2.top();
            s2.pop();
        }
        int digit = sum%10;
        carry = sum/10;
        node* newNODE = new node(digit);
        newNODE->next = head;
        head = newNODE;
    }
    return head;
}
*/
int main(){

    node* head = NULL;
    node* tail = NULL;
    insertAtHead(head,tail,1);
    insertAtPosition(head,tail,2,2);
    insertAtTail(head,tail,6);
    insertAtTail(head,tail,6);
    insertAtTail(head,tail,7);
    insertAtTail(head,tail,2);
    printList(head);
    removedupliUNSORTED(head);
    printList(head);
    // tail->next = head->next->next;
    // node* find = getstartnode(head);
    // cout<<"starting node :"<<find->data;
    // deleteAtHead(head,tail);
    // printList(head);
    // deleteAtTail(head,tail);
    // printList(head);
    // deleteAtPosition(head,tail,2);
    // printList(head);
}
