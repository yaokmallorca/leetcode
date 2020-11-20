#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class List{
private:
public:
	List(int* array, int len);
	~List();
	// void CreateList(int* array, int len);
	void ScanList();
	int GetLength();
	bool IsEmpty();
	ListNode* Find(int data);
	void InsertElemAtEnd(int data);
	void InsertElemAtIndex(int data, int index);
	void InsertElemAtHead(int data);
	void DeleteElemAtEnd();
	void DeleteAll(); 
	void DeleteElemAtData(int data);
	void DeleteElemAtHead();
	void ReverseList();

	ListNode *head;
};

bool List::IsEmpty() {
	if (head != nullptr)
		return false;
	else 
		return true;
}

List::List(int* array, int len){
	if (array == nullptr){
		head = nullptr;
		return;
	}
	if (len <= 0){
		head = nullptr;
		return;
	}
	head = new ListNode(array[0]);
	// tail = head;
	ListNode *pnode, *ptmp;
	ptmp = head;
	for (int i = 1; i < len; i++) {
		// cout << "i = " << i  << ", " << array[i] << endl;
		pnode = new ListNode(array[i]);
		// tail = pnode;
		ptmp->next = pnode;
		ptmp = pnode;
	}
}

List::~List(){
	DeleteAll();
}


void List::DeleteAll() {
	ListNode *p = head;
	ListNode *ptmp = nullptr;
	if (p == nullptr)
		return;
	while(p->next != nullptr) {
		ptmp = p->next;
		delete p;
		p = nullptr;
		p = ptmp;
	}
}

void List::ScanList(){
	if (head == nullptr) {
		return;
	}
	ListNode* p = head;
	do {
		std::cout << p->val << std::endl;
		p = p->next;
	}while (p != nullptr);
}

int List::GetLength(){
	if (head == nullptr) {
		return 0;
	}
	int len = 0;
	ListNode* p = head;
	do {
		// std::cout << p->val << std::endl;
		len += 1;
		p = p->next;
	}while (p != nullptr);
	return len;
}

ListNode* List::Find(int data) {
	if (head == nullptr)
		return nullptr;
	ListNode* p = head;
	do {
		if (p->val == data){
			return p;
		}
		p = p->next;
	}while (p != nullptr);
}

void List::InsertElemAtEnd(int data){
	if (head == nullptr)
		return;
	ListNode *pElem = new ListNode(data);
	ListNode *tail, *p;
	p = head;
	while(p!=nullptr){
		tail = p;
		p = p->next;
	}
	tail->next = pElem;
}

void List::InsertElemAtHead(int data){
	if (head == nullptr)
		return;
	ListNode *pnode = new ListNode(data);
	// ListNode *ptmp = head;
	pnode->next = head;
	head = pnode;
}

void List::InsertElemAtIndex(int data, int index) {
	if (head == nullptr) {
		return;
	}
	int len = this->GetLength();
	if (index > len){
		return;
	}
	ListNode* p = head;
	for (int i=0; i<len; i++) {
		if (i == index){
			ListNode *tmp, *node;
			node = new ListNode(data);
			tmp = p->next;
			p->next = node;
			node->next = tmp;
			return;
		}
		p = p->next;
	}
}

void List::DeleteElemAtEnd() {
	if (head == nullptr) {
		return;
	}
	ListNode *p = head;
	ListNode *tail, *prev;
	int len = this->GetLength();
	for(int i=0; i<(len-1); i++) {
		prev = p;
		p = p->next;
		tail = p;
	}
	if(tail != nullptr){
		delete tail;
		tail = nullptr;
	}
	tail = prev;
	tail->next = nullptr;
}

void List::DeleteElemAtHead() {
	if (head == nullptr) {
		return;
	}
	ListNode *p = head;
	ListNode *tmp = head->next;
	delete head;
	head = tmp;
}

void List::DeleteElemAtData(int data) {
	if (head == nullptr) {
		return;
	}
	ListNode *p = head;
	ListNode *tmp, *next, *prev;
	int len = this->GetLength();
	for(int i=0; i<len; i++) {
		int val = p->val;
		if (val == data){
			next = p->next;
			delete p;
			prev->next = next;
			return;
		}
		prev = p;
		p = p->next;
	}
}


void List::ReverseList() {
	if (head == nullptr)
		return;
	ListNode *prev, *curr, *next;
	curr = head->next;
	prev = head;
	while (curr != nullptr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head->next = nullptr;
	head = prev;
}


int main()
{
	int list_node[9] = {1,6,7,2,5,7,10,23,8};

	List list(list_node, 9);
	
	list.ScanList();
	int len = list.GetLength();
	cout << "list length: " << len << endl;
	ListNode* node = list.Find(10);
	if (node != nullptr)
		cout << "find node: " << node->val << endl;
	else
		cout << "do not find node" << endl;
	
	cout << "!!!!!!!!!!!!!!!!!!!!!!" << endl;
	list.InsertElemAtEnd(1);
	list.ScanList();
	len = list.GetLength();
	cout << "list length: " << len << endl;

	cout << "!!!!!!!!!!!!!!!!!!!!!!" << endl;
	list.InsertElemAtHead(111);
	list.ScanList();
	len = list.GetLength();
	cout << "list length: " << len << endl;
	
	cout << "!!!!!!!!!!!!!!!!!!!!!!" << endl;
	list.InsertElemAtIndex(-12, 3);
	list.ScanList();
	len = list.GetLength();
	cout << "list length: " << len << endl;
	
	cout << "!!!!!!!!!!!!!!!!!!!!!!" << endl;
	list.DeleteElemAtEnd();
	list.ScanList();
	len = list.GetLength();
	cout << "list length: " << len << endl;

	cout << "!!!!!!!!!!!!!!!!!!!!!!" << endl;
	list.DeleteElemAtHead();
	list.ScanList();
	len = list.GetLength();
	cout << "list length: " << len << endl;
	
	cout << "!!!!!!!!!!!!!!!!!!!!!!" << endl;
	list.DeleteElemAtData(-12);
	list.ScanList();
	len = list.GetLength();
	cout << "list length: " << len << endl;
	
	cout << "!!!!!!!!!!!!!!!!!!!!!!" << endl;
	list.ReverseList();
	list.ScanList();
	int len = list.GetLength();

	return 0;
}
