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
#include <iostream>

//...............Wyswietlanie Struktur STL.............

void showlist(std::list <int> g)
{
	std::cout << "Test listy:" << std::endl;
	std::list <int> ::iterator it;
	for (it = g.begin(); it != g.end(); ++it)
		std::cout << '\t' << *it;
	std::cout << '\n';
}

void showstack(std::stack <int> s)
{
	std::cout << "Test stosu:" << std::endl;
	while (!s.empty())
	{
		std::cout << '\t' << s.top();
		s.pop();
	}
	std::cout << '\n';
}


void showq(std::queue <int> q)
{
	std::cout << "Test kolejki:" << std::endl;
	std::queue <int> g = q;
	while (!g.empty())
	{
		std::cout << '\t' << g.front();
		g.pop();
	}
	std::cout << '\n';
}

void showpq(std::priority_queue <int> q)
{
	std::cout << "Test kolejki priorytetowej:" << std::endl;
	std::priority_queue <int> g = q;
	while (!g.empty())
	{
		std::cout << '\t' << g.top();
		g.pop();
	}
	std::cout << '\n';
}

void showmap(std::map <int, int> m) 
{
	std::cout << "Test mapy:" << std::endl;
	std::map<int, int>::iterator itr;
	std::cout << "\tKEY\tELEMENT\n";
	for (itr = m.begin(); itr != m.end(); ++itr) {
		std::cout << '\t' << itr->first
			<< '\t' << itr->second << '\n';
	}
}



//...............TESTY STL..............

void testlistastl() {
	std::list<int> liststl;
	for (int i = 0; i < 5; i++) {
		liststl.push_back(i);
	}
	liststl.remove(2);
	liststl.push_front(9);

	showlist(liststl);
	std::cout << '\n' << std::endl;

}

void teststackstl() {
	std::stack < int > stackstl;
	for (int i = 0; i < 5; i++) {
		stackstl.push(i);
	}
	stackstl.pop();

	showstack(stackstl);
	std::cout << '\n' << std::endl;
}

void testqueuestl() {
	std::queue<int> queuestl;
	for (int i = 0; i < 5; i++) {
		queuestl.push(i);
	}
	queuestl.pop();
	showq(queuestl);
	std::cout << '\n' << std::endl;

}

void testpqueuestl() {
	std::priority_queue<int> pqueuestl;
	for (int i = 0; i < 5; i++) {
		pqueuestl.push(i);
	}
	pqueuestl.pop();
	pqueuestl.push(10);
	pqueuestl.push(7);
	showpq(pqueuestl);
	std::cout << '\n' << std::endl;
}

void testmapstl() {
	std::map<int, int> mapstl;
	mapstl.insert(std::pair<int, int>(2, 40));
	mapstl.insert(std::pair<int, int>(6, 30));
	mapstl.insert(std::pair<int, int>(3, 70));
	mapstl.insert(std::pair<int, int>(1, 100));

	showmap(mapstl);


}




//...............TESTY WLASNYCH.................

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
		pqueue1.enqueue(i, i + 2);
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
	Map<std::string, int, hashString> map1;

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
	testlistastl();
	teststackstl();
	testqueuestl();
	testpqueuestl();
	testmapstl();

	//testlista();
	//teststack();
	//testqueue();
	//testpqueue();
	//testhash();

	int a;
	std::cin >> a;
	return 0;
}
