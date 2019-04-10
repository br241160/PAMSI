#include <iostream>

template <typename T>
struct Element3 {
	Element3 *next, *prev;
	T value;
	int priority;

	Element3(T value) {
		this->next = nullptr;
		this->prev = nullptr;
		this->value = value;
	}
	Element3(Element3 *prev, Element3 *next, T value, int priority) {
		this->prev = prev;
		this->next = next;
		this->value = value;
		this->priority = priority;
	}
};

template <typename T>
class PriorityQueue {
private:
	Element3<T> *front, *back;
	int size;


public:
	PriorityQueue() {
		front = back = nullptr;
		size = 0;
	}
	void enqueue(const T& newElement, int priority) { //ogarn¹æ tutaj sprawdzanie priorytetów
		Element3<T> *sort1;
		Element3<T> *sort2;
		
		if (size == 0) {
			Element3<T> *elem = new Element3<T>(nullptr, nullptr, newElement, priority);
			front = elem;
			back = elem;


			size++;
		}
		else if (size > 0) {
			sort1 = front;
			sort2 = front;
			while (sort1 != nullptr && sort1->priority <= priority) {
				sort2 = sort1;
				sort1 = sort1->next;
			}

			Element3<T> *elem = new Element3<T>(nullptr, sort1, newElement, priority);
			if (sort1 == nullptr) {
				elem->prev = sort2;
				sort2->next = elem;
				back = elem;
			}
			else {
				elem->next = sort1->next;
				sort1->next = elem;
				if(elem->next != nullptr){
					elem->next->prev = elem;
			
				}
			}
			size++;
		}
	}

	T dequeue() {
		if (front != nullptr) {
			Element3<T> *newBack = back->prev;
			T deqVal = back->value;
			delete back;
			back = newBack;
			newBack->next = nullptr;
			size--;
			return deqVal;
		}
		else return NULL;
	}

	void showcase3() {
		Element3<T> *temp = back;
			for (int i = 0; i < (size ); i++) {
			std::cout << temp->value << std::endl;
			temp = temp->prev;
		}
	}


};