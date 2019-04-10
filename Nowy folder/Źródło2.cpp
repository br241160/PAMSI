
#include <iostream>

template <typename T>
struct Element2 {
	Element2 *next, *prev;
	T value;
	Element2(T value) {
		next = prev = nullptr;
		this->value = value;
	}
	Element2(Element2 *prev, Element2 *next, T value) {
		this->prev = prev;
		this->next = next;
		this->value = value;
	}
};

template <typename T>
class Queue {
private:
	Element2<T> *front, *back;
	int size;
public:
	Queue() {
		front = back = nullptr;
		size = 0;
	}

	void enqueue(const T& newElement) {
		if (size == 0) {
			Element2<T> *elem = new Element2<T>(nullptr, nullptr, newElement);
			front = elem;
			back = elem;
			size++;
		}
		else if (size > 0) {
			Element2<T> *elem = new Element2<T>(nullptr, front, newElement);
			front->prev = elem;
			front = elem;
			size++;
		}
	}

	T dequeue() {
		if (front != nullptr) {
			Element2<T> *newBack = back->prev;
			T deqVal = back->value;
			delete back;
			back = newBack;
			size--;
			return deqVal;
		}
		else return NULL;
	}

	void showcase2() {
		Element2<T> *temp = back;
		for (int i = 0; i < (size ); i++) {
			std::cout << temp->value << std::endl;
			temp = temp->prev;
		}
	}

};