
#include <iostream>

template <typename T>
struct Element1 {
	Element1 *next;
	T value;
	Element1(T value) {
		next = nullptr;
		this->value = value;
	};
	Element1(Element1 *next, T value) {
		this->next = next;
		this->value = value;
	}
};


template <typename T>
class Stack {
private:
	Element1<T> *front;
	int size;

public:
	Stack() {
	front = nullptr;
	int	size = 0;
	};

	void push(const T& newElement) {

		if (size == 0) {
			Element1<T> *elem = new Element1<T>(nullptr, newElement);
			front = elem;
			size++;
		}

		else if (size > 0) {
			Element1<T> *elem = new Element1<T>(front, newElement);
			front = elem;
			size++;
		};
	};

	T pop() {
		if (front != nullptr) {
			Element1<T> *newFront = front->next;
			T popVal = front->value;
			delete front;
			front = newFront;
			size--;
				return popVal;
		}
		else return NULL;
	}

	void showcase1() {
		Element1<T> *temp = front;
		for (int i = 0; i < (size ); i++) {
			std::cout << temp->value << std::endl;
			temp = temp->next;
		}
	}
};

