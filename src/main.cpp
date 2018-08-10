#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <bitset>

void hash(std::string& hashed){
	for(auto ch : hashed){
		ch ^= hashed[0];
	}
	for(int ch : hashed){
		hashed[ch] ^= 123;
	}
}
int main(int argc, char * argv[]){
    std::fstream t(argv[1]);
	std::string hashed((std::istreambuf_iterator<char>(t)),
                 std::istreambuf_iterator<char>());
	hash(hashed);
	unsigned long long int ret(2310); 
	for(auto ch: hashed){
		ret ^= (ch * 233);
	}
	std::cout << argv[1] << ":" <<std::hex << (ret << 4) << std::endl;
	return(0);
}
