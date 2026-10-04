#include <iostream>
#include <cstdint>
#include <bitset>

/* 
* to avoid error : conflicting declaration 
* 	'int BitMaker()' which is C3861 
*/
int bitwiseAnd();
int BitMaker(); 
int BitSetter();


/*
* could be able to copy the class
*/
class doCopy {
public:
	doCopy() = default;
	doCopy(const doCopy&) {
		std::cout << "Copy constructor called" << std::endl;
		std::abort();
	}
};

class noCopy {
public:
	noCopy() = default;

	noCopy(const noCopy&) = delete;
	noCopy& operator = (const noCopy&) = delete;
};

//noCopy aVar;
doCopy cVar;

doCopy bVar(cVar);

int bitwiseAnd() {
	uint8_t value = 0b10011001; // we need to create 0b00011001
	uint8_t mask = 0b00011001;

	std::cout << "Value:"
		<< std::bitset<8>(value)
		<< '\n';

	std::cout << "Mask:"
		<< std::bitset<8>(mask)
		<< '\n';

	uint8_t result = value & mask;

	std::cout << "Result:"
		<< std::bitset<8>(result)
		<< '\n';

	return 0;
}


 int BitMaker() {
	const int value = 0b10011001; // we need work on 7's bit.
	const int mask = 0b00000001;
	const int result = value & mask;

	std::cout << "Result:"
		<< std::bitset<8>(result)
		<< '\n';

	return 0;
}


 int BitSetter() {
	 const int value = 0b10011001; // we need work on 7's bit.
	 const int ETC_Setter = 1 << 4;
	 const uint8_t TSD_Setter = 1 << 5;
	 int abc = value & (ETC_Setter & TSD_Setter);
	 std::cout << "Value:"
		 << std::bitset<8>(abc)
		 << '\n';
	 return 0;
 }


 int main() {
	 //int aVar = 0, bVar = 0, cVar = 0;
	 std::cout << "creating doCopy object" << std::endl;
	 doCopy a;

	 std::cout << "creating noCopy object" << std::endl;
	 noCopy b;

	 //doCopy c(a); // This will call the copy constructor of doCopy
	 //noCopy d(a); // This will cause a compilation error because noCopy cannot be copied

	 return 0;
 }