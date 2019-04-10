#include <iostream>

template <typename T>
struct Element {
	Element *next, *prev;
	T value;
	Element() {

	}

	Element(T value) {
		next = prev = nullptr;
		this->value = value;
	}
	Element(Element *prev, Element *next, T value) {
		this->prev = prev;
		this->next = next;
		this->value = value;
	}
};

template <typename T>
class List {
private:
	Element<T> *front, *back;
	int size;
	Element<T> *beginptr;
	Element<T> *endptr;
	int itcount = 0;
	int itcountEnd = 0;

public:
	List() {
		front = back = nullptr;
		size = 0;
	}



	void pushfront(const T& newElement) {
		if (size == 0) {
			Element <T> *elem = new Element<T>(nullptr, nullptr, newElement);
			front = elem;
			back = elem;
			size++;
		}

		else if (size > 0) {
			Element <T> *elem = new Element<T>(nullptr, front, newElement);
			front->prev = elem;
			front = elem;
			size++;
		}
	};

	void pushback(const T& newElement) {
		if (size == 0) {
			Element <T> *elem = new Element<T>(nullptr, nullptr, newElement);
			front = elem;
			back = elem;
			size++;
		}
		
		else if (size > 0) {
			Element <T> *elem = new Element<T>(back, nullptr, newElement);
			back->next = elem;
			back = elem;
			size++;
		}

	};

	void insert(const T& newElement, int index) {
		if (size == (index - 1)) {
			pushback(newElement);
		}
		else if (size < (index - 1)) {
			std::cout << "Nie mo¿na wykonaæ." << std::endl;
		}
		else if (size >= index) {
			Element<T> *temp1 = front;
			Element<T> *temp2 = 0;

			for (int i = 0; i < (index - 1); i++) {
				//temp2 = temp1->next;
				//temp1 = temp2;
				temp2 = temp1;
				temp1 = temp1->next; //ustawic raczki elementow pomiedzy ktore insertujemy
			}
			Element <T> *elem = new Element<T>(nullptr, nullptr, newElement);
			temp2->next = elem;
			temp1->prev = elem;
			elem->next = temp1;
			elem->prev = temp2;
			size++; //Do sprawdzenia
		}
	}

	void remove(const T& element) {
		Element<T> remcount = element;
		for (int i = 0; i < element; i++) {

			if (front != nullptr) {
				Element<T> *newFront = front->next;
				//T remVal = front->value;
				delete front;
				front = newFront;
				newFront->prev = nullptr;
				size--;
				std::cout << "Usunieto element" << std::endl;
			}
			else
				std::cout << "Nie usunieto elementu" << std::endl;
		}

		
	};

	T& operator[] (int index) {
		std::cout << "Wartosc elementu" << index << ":" << std::endl;
		if (size == (index - 1)) {
			std::cout << back->value << std::endl;
		}
		else if (size < (index - 1)) {
			std::cout << "Nie ma takiego elementu." << std::endl;
		}
		else if (size >= index) {
			Element<T> *temp1 = front;
			Element<T> *temp2 = 0;

			for (int i = 0; i < (index - 1); i++) {
				//temp2 = temp1->next;
				//temp1 = temp2;
				temp2 = temp1;
				temp1 = temp1->next; 
			}
			std::cout << temp1->value << std::endl;
		}
		return index;
	}

	void showcase(){
		Element<T> *temp = front;
		for (int i = 0; i < size; i++) {
			std::cout << temp->value << std::endl;
			temp = temp->next;
		}
	}


	struct Iterator {
		int itcount = 0;
		int itcountEnd = 0;

		Iterator begin() {
			if (itcount == 0) {
				beginptr = front;
				itcount++;
				return beginptr;
				beginptr = front->next;
			}
			else {
				return beginptr;
				if (beginptr->next != nullptr) {
					beginptr->next;
					itcount++;
				}
			}
		};
		
		Iterator end() {
			if (itcountEnd == 0) {
				beginptr = back;
				itcountEnd++;
				return beginptr;
				beginptr = back->prev;
			}
			else {
				return beginptr;
				if (beginptr->prev != nullptr) {
					beginptr->prev;
					itcountEnd++;
				}
			};
		};
		//constiterator cbegin() const {};
		//constiterator cend() const {};
	};
};