
#include <string>
#include <iostream>

template <typename KeyType>
using HashFunction = int(*)(const KeyType& key);


template <typename KeyType, typename ValueType, HashFunction<KeyType> hashFunction>
class Map {
private:
	int tabsize;
	ValueType *tabVal;
	int *tabHelp;

public:
	Map() {
		tabsize = 10;
		tabHelp = new int[tabsize];
		tabVal = new ValueType[tabsize];
		for (int i = 0; i < tabsize; i++) {
			tabHelp[i] = 0;
		}
	}

	~Map() {
		delete[] tabHelp;
		delete[] tabVal;
	}



	
	void insert(const KeyType& key, const ValueType& value){
	
		int index = hashFunction(key);
		tabVal[index] = value;
		tabHelp[index] = 1;
		
		
	}

	ValueType& operator[](const KeyType& key){
		int index = hashFunction(key);
		if (tabHelp[index] == 1) {
			std::cout << tabVal[index] << std::endl;
			return tabVal[index];
		}
		else std::cout << "Nie ma takiego elementu" << std::endl;
		return tabVal[index];
	}

	void remove(const KeyType& key){
		int index = hashFunction(key);
		tabHelp[index] = 0;
	}

};
