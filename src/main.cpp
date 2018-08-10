#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <bitset>

void hash(std::string& hashed){
	for(auto ch : hashed){
		ch ^= (ch >> 7);
	}
	for(int ch : hashed){
		hashed[ch] ^= (hashed[ch+1] >> hashed[ch]);
	}
}

int main(int argc, char * argv[]){ 
	auto file = std::ifstream(argv[1]).rdbuff();
	std::cout << file << std::endl;
	std::ostringstream o;
	o << file;
	std::string hashed = o.str();
	hash(hashed);
	unsigned long long int ret(0); 
	for(auto ch: hashed){
		ret ^= ch;
	}
	return(ret << 4);
}
