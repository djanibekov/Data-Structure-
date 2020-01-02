#include<iostream>
#include<string>
using namespace std;
class Details {                                      //parent class of all details 
private:
	string name;
	bool inQueue = false;
	bool change = false;
public:
	void setName(string name) {
		this->name = name;
	}

	string getName() {
		return name;
	}

	void setChange() {
		change = !change;
	}

	bool isChange() {
		return change;
	}

	void changeStatus() {
		inQueue = !inQueue;
	}

	bool isInQueue() {
		return inQueue;
	}

	virtual void PutIn() {  };
	virtual void TakeOff() {};
};
class A_detail : public Details {
public:
	void PutIn() {
		if (isChange()) {
			cout << "New A detail put in" << endl << endl;
			setChange();
		}
		else
			cout << "A detail put in" << endl << endl;
	}
	void TakeOff() {
		cout << "A detail took off" << endl << endl;
	}
};
class B_detail : public Details {
public:
	void PutIn() {
		if (isChange()) {
			cout << "New B detail put in" << endl << endl;
			setChange();
		}
		else
			cout << "B detail put in" << endl << endl;

	}
	void TakeOff() {
		cout << "B detail took off" << endl << endl;
	}
};
class C_detail : public Details {
public:
	void PutIn() {
		if (isChange()) {
			cout << "New C detail put in" << endl << endl;
			setChange();
		}
		else
			cout << "C detail put in" << endl << endl;
	}
	void TakeOff() {
		cout << "C detail took off" << endl << endl;
	}
};
class D_detail : public Details {
public:
	void PutIn() {
		if (isChange()) {
			cout << "New D detail put in" << endl << endl;
			setChange();
		}
		else
			cout << "D detail put in" << endl << endl;
	}
	void TakeOff() {
		cout << "D detail took off" << endl << endl;
	}
};
class E_detail : public Details {
public:
	void PutIn() {
		if (isChange()) {
			cout << "New E detail put in" << endl << endl;
			setChange();
		}
		else
			cout << "E detail put in" << endl << endl;
	}
	void TakeOff() {
		cout << "E detail took off" << endl << endl;
	}
};
class F_detail : public Details {
public:
	void PutIn() {
		if (isChange()) {
			cout << "New F detail put in" << endl << endl;
			setChange();
		}
		else
			cout << "F detail put in" << endl << endl;
	}
	void TakeOff() {
		cout << "F detail took off" << endl << endl;
	}
};
class G_detail : public Details {
public:
	void PutIn() {
		if (isChange()) {
			cout << "New G detail put in" << endl << endl;
			setChange();
		}
		else
			cout << "G detail put in" << endl << endl;
	}
	void TakeOff() {
		cout << "G detail took off" << endl << endl;
	}
};
class H_detail : public Details {
public:
	void PutIn() {
		if (isChange()) {
			cout << "New H detail put in" << endl << endl;
			setChange();
		}
		else
			cout << "H detail put in" << endl << endl;
	}
	void TakeOff() {
		cout << "H detail took off" << endl << endl;
	}
};





//node that is used in Queue (Order) and Stack (Reverse)
class Node {  // node consists of pointer to the object of class Detail and pointer to the next object of class Node
public:
	Details* detail;
	Node* next;
	Node* newNode(Details* detail) {
		Node* newNode = new Node();
		newNode->detail = detail;
		newNode->next = NULL;
		return newNode;
	}
};





//Queue is used to store pointers to object of class Detail in order, that they will be taken off.
class Order {
private:
	Node* Front;
	Node* Rear;
	Node* ptr;
public:
	Order(void) {
		Front = NULL;
		Rear = NULL;
		ptr = NULL;	}
	Order* createQueue() {
		Order* q = new Order();
		q->Front = q->Rear = NULL;
		return q;	}
	Node* Dequeue() {
		ptr = NULL;
		if (Front == NULL) {
			cout << "Underflow" << endl;		}
		else {
			ptr = Front;
			Front = Front->next;	}
		ptr->detail->changeStatus();
		return ptr;	}
	void Enqueue(Details* value) {
		Node N;
		ptr = N.newNode(value);
		if (Front == NULL) {
			Front = ptr;
			Rear = Front;
			Front->next = NULL;
			Rear->next = Front->next;		}
		else {
			Rear->next = ptr;
			Rear = ptr;
			Rear->next = NULL;		}
		ptr = NULL;
		value->changeStatus();	}
	bool endOfQueue() {
		if (Front == NULL)
			return true;
		else
			return false;	}};
//Stack is used to store pointers to object of class Detail in order, that they will be put on.
class Reverse {
private:
	Node* Top;
	Node* ptr;
public:
	Reverse() {
		Top = NULL;	}
	void Push(Details* data) {
		Node N;
		Node* New = N.newNode(data);
		if (Top == NULL) {
			New->next = NULL;
			Top = New;
		}
		else {
			New->next = Top;
			Top = New;		}	}
	Node* Pop() {
		ptr = NULL;
		if (Top == NULL) {
			cout << "Underflow" << endl;		}
		else {
			ptr = Top;
			Top = Top->next;		}
		return ptr;	}
	bool endOfStack() {
		if (Top == NULL)
			return true;
		else
			return false;	}};






class LinkedLists;


class NodeLinkedList {		//Node of linked list consists of 
public:						//pointer to another linked list and 
	LinkedLists* ptrList;	//pointer to the next node.
	NodeLinkedList* next;
};







class LinkedLists {
public:
	NodeLinkedList* Head;   //linked list consists of two pointers to the first node(Head) 
	NodeLinkedList* Rear;	//and to the last node(Rear), in other words it is queue.
	Details* details;       //Also it holds pointer to the object of class detail.
	LinkedLists() {
		Head = NULL;
	}
	void setDetail(Details* detail) {
		this->details = detail;
	}
	void InsertNodeEnd(LinkedLists* ptrList) {
		NodeLinkedList* ptr = new NodeLinkedList();
		ptr->ptrList = ptrList;
		ptr->next = NULL;
		if (Head == NULL) {
			ptr->next = NULL;
			Head = ptr;
			Rear = Head;
		}
		else {
			Rear->next = ptr;
			Rear = Rear->next;
		}
	}
};
void changeDetail(LinkedLists* list, Order* order, Reverse* reverse) {
	NodeLinkedList* ptr;
	ptr = list->Head;
	while (ptr != NULL) {
		if (!ptr->ptrList->details->isInQueue())
			changeDetail(ptr->ptrList, order, reverse);
		ptr = ptr->next;
	}

	order->Enqueue(list->details);
	reverse->Push(list->details);
}
void ReverseInstructions(Order* order, Reverse* reverse) {
	while (!order->endOfQueue()) {
		order->Dequeue()->detail->TakeOff();
	}
	while (!reverse->endOfStack()) {
		reverse->Pop()->detail->PutIn();
	}
}
int main() {
	LinkedLists listOfDetails[8], tmp;
	Order queueTakeOff;
	Reverse stackPutOn;
	string name;
	A_detail a_detail;
	B_detail b_detail;
	C_detail c_detail;
	D_detail d_detail;
	E_detail e_detail;
	F_detail f_detail;
	G_detail g_detail;
	H_detail h_detail;
	listOfDetails[0].setDetail(&a_detail);
	listOfDetails[1].setDetail(&b_detail);
	listOfDetails[2].setDetail(&c_detail);
	listOfDetails[3].setDetail(&d_detail);
	listOfDetails[4].setDetail(&e_detail);
	listOfDetails[5].setDetail(&f_detail);
	listOfDetails[6].setDetail(&g_detail);
	listOfDetails[7].setDetail(&h_detail);
	a_detail.setName("A");
	b_detail.setName("B");
	c_detail.setName("C");
	d_detail.setName("D");
	e_detail.setName("E");
	f_detail.setName("F");
	g_detail.setName("G");
	h_detail.setName("H");
	listOfDetails[0].InsertNodeEnd(&listOfDetails[1]);                                  //make connection between details (show their dependence).
	listOfDetails[0].InsertNodeEnd(&listOfDetails[2]);
	listOfDetails[1].InsertNodeEnd(&listOfDetails[3]);
	listOfDetails[2].InsertNodeEnd(&listOfDetails[3]);
	listOfDetails[4].InsertNodeEnd(&listOfDetails[3]);
	listOfDetails[5].InsertNodeEnd(&listOfDetails[0]);
	listOfDetails[6].InsertNodeEnd(&listOfDetails[0]);
	listOfDetails[7].InsertNodeEnd(&listOfDetails[5]);
	listOfDetails[7].InsertNodeEnd(&listOfDetails[6]);
	while (true) {
		cout << "Name of detail: " << endl << "(A, B, C, D, E, F, G, H)" << endl;
		cin >> name;
		for (int i = 0; i < sizeof(listOfDetails) / sizeof(LinkedLists); i++) {
			if (listOfDetails[i].details->getName() == name) {
				listOfDetails[i].details->setChange();
				changeDetail(&listOfDetails[i], &queueTakeOff, &stackPutOn);
			}
		}
		ReverseInstructions(&queueTakeOff, &stackPutOn);
		cout << endl;
	}
	system("pause");
	return 0;
}