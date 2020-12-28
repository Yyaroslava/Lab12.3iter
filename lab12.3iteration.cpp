#include <iostream> 
#include <iomanip>
#include <Windows.h>

using namespace std;

struct Elem {
	int info;
	Elem* next;
	Elem* prev;
};

Elem* Add_Before(Elem* &head, Elem*&end, Elem* &elem, int info) {
	Elem* p = new Elem;
	p->info = info;
	if(elem != NULL) {
		cout << "Вставка " << info << " перед " << elem->info <<  endl;
		p->next = elem;
		p->prev = elem->prev;
		if (elem->prev == NULL) {
			head = p;
		}
		else {
			elem->prev->next = p;
		}
		elem->prev = p;
	}
	else if (elem == head) { 
		// вставити на початок списку
		cout << "Вставка " << info << " на початок " << endl;
		p->prev = NULL;
		p->next = head;
		head = p;
		if (p->next == NULL) {
			end = p;
		}
		else {
			p->next->prev = p;
		}
	}
	else if (elem == end) {
		// вставити в кінець списку
		cout << "Вставка " << info << " в кінець" << endl;
		p->next = NULL;
		p->prev = end;
		if (p->prev == NULL) {
			head = p;
		}
		else {
			p->prev->next = p;
		}
		end = p;
	}
	
	return p;
}

Elem* Add_After(Elem*& head, Elem*& end, Elem*& elem, int info) {
	Elem* p = new Elem;
	p->info = info;
	if (elem != NULL) {
		cout << "Вставка " << info << " після " << elem->info << endl;
		p->prev = elem;
		p->next = elem->next;
		elem->next = p;
		if (p->next == NULL) {
			end = p;
		}
		else {
			p->next->prev = p;
		}
	}
	else if (elem == head) {
		// вставити на початок списку
		cout << "Вставка " << info << " на початок " << endl;
		p->prev = NULL;
		p->next = head;
		head = p;
		if (p->next == NULL) {
			end = p;
		}
		else {
			p->next->prev = p;
		}
	}
	else if (elem == end) {
		// вставити в кінець списку
		cout << "Вставка " << info << " в кінець" << endl;
		p->next = NULL;
		p->prev = end;
		if (p->prev == NULL) {
			head = p;
		}
		else {
			p->prev->next = p;
		}
		end = p;
	}
	return p;
}

void Print(Elem* head) {
	Elem* p = head;
	while (p!=NULL) {
		cout << p->info << " ";
		p = p->next;
	}
	cout << endl;
}

bool Found(Elem* head, int info) {
	Elem* p = head;
	while (p != NULL) {
		if (p->info == info) return true;
		p = p->next;
	}
	return false;
}

// Перевіка, що список1 містить список2
bool Contains(Elem* List1_Head, Elem* List2_Head) {
	Elem* p = List2_Head;
	while (p != NULL) {
		if (!Found(List1_Head, p->info)) return false;
		p = p->next;
	}
	return true;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Elem* List1_Head = NULL;
	Elem* List1_End = NULL;

	Elem* List2_Head = NULL;
	Elem* List2_End = NULL;

	cout << "Список1: " << endl;
	Elem* item15  = Add_After(List1_Head, List1_End, List1_Head, 15);
	Print(List1_Head);
	Elem* item42 = Add_Before(List1_Head, List1_End, List1_End, 42);
	Print(List1_Head);
	Elem* item6 = Add_Before(List1_Head, List1_End, List1_End, 6);
	Print(List1_Head);
	Elem* item66 = Add_Before(List1_Head, List1_End, item6, 66);
	Print(List1_Head);
	Elem* item333 = Add_Before(List1_Head, List1_End, item42, 333);
	Print(List1_Head);
	Elem* item13 = Add_After(List1_Head, List1_End, item6, 13);
	Print(List1_Head);
	Elem* item1 = Add_After(List1_Head, List1_End, List1_End, 1);
	Print(List1_Head);

	cout << endl << "Список2: " << endl;
	Add_After(List2_Head, List2_End, List2_Head, 66);
	Add_After(List2_Head, List2_End, List2_Head, 42);
	Print(List2_Head);

	cout << endl;
	if (Contains(List1_Head, List2_Head)) {
		cout << "Список1 містить список2 " << endl;
	}
	else {
		cout << "Список1 НЕ містить список2 " << endl;
	}

	return 0;
}

