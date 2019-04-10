#include <iostream>
#include "èrÛd≥o.cpp"
#include "èrÛd≥o1.cpp"
#include "èrÛd≥o2.cpp"
#include "èrÛd≥o3.cpp"
#include "Source.cpp"
#include <string>
#include <list>
#include <cstddef>
#include <stack>
#include <queue>
#include <map>


void testlistastl() {
	std::list<int> liststl;
	for (int i = 0; i < 5; i++) {
		liststl.push_back(i);
	}
	liststl.remove(2);
	liststl.push_front(9);
	std::cout << '\n' << std::endl;

}

void teststackstl() {
	std::stack < int > stackstl;
	for (int i = 0; i < 5; i++) {
		stackstl.push(i);
	}
	stackstl.pop();

	std::cout << '\n' << std::endl;
}

void testqueuestl() {
	std::queue<int> queuestl;
	for (int i = 0; i < 5; i++) {
		queuestl.push(i);
	}
	queuestl.pop();
	std::cout << '\n' << std::endl;

}

void testpqueuestl() {
	std::priority_queue<int> pqueuestl;
	for (int i = 0; i < 5; i++) {
		pqueuestl.push(i);
	}
	pqueuestl.pop();
	pqueuestl.push(10);
	std::cout << '\n' << std::endl;
}





void testlista() {
	std::cout << "Test listy:" << std::endl;
	List<int> lista1;
	for (int i = 0; i < 5; i++) {
		lista1.pushback(i);
	}
	lista1.remove(2);
	lista1.insert(8, 2);
	lista1.pushfront(9);
	lista1.showcase();
	lista1[3];
	std::cout << '\n' << std::endl;
};


void teststack() {
	std::cout << "Test stosu:" << std::endl;
	Stack<int> stack1;
	for (int i = 0; i < 5; i++) {
		stack1.push(i);
	}
	stack1.pop();
	stack1.showcase1();
	std::cout << '\n' << std::endl;
};

void testqueue() {
	std::cout << "Test kolejki:" << std::endl;
	Queue<int> queue1;
	for (int i = 0; i < 5; i++) {
		queue1.enqueue(i);
	}
	queue1.dequeue();
	queue1.showcase2();
	std::cout << '\n' << std::endl;

}

void testpqueue() {
	std::cout << "Test kolejki priorytetowej:" << std::endl;
	PriorityQueue<int> pqueue1;
	for (int i = 0; i < 5; i++) {
		pqueue1.enqueue(i, i+2);
	}
	pqueue1.dequeue();
	pqueue1.enqueue(19, 10);
	pqueue1.showcase3();
	std::cout << '\n' << std::endl;
}

int hashString(const std::string& key)
{
		int sum = 0;
		for (int i = 0; i < (size(key)); i++) {
			sum += key[i];
		}
		return sum % 10;
}

int hashInt(const int& key)
{
		return key % 10;
	
}

void testhash() {
	std::cout << "Test hashmapy:" << std::endl;
	Map<std::string,int, hashString> map1;
	
	map1.insert("mapa", 3);
	map1.insert("funkcja", 2);
	map1.insert("baza", 5);
	map1.insert("przykladowedane", 7);
	map1["mapa"];
	map1["baza"];
	map1.remove("mapa");
	map1["mapa"];
	
}


int main() {
	testlista();
	teststack();
	testqueue();
	testpqueue();
	testhash();

	int a;
	std::cin >> a;
	return 0;
}
