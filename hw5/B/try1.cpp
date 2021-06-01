#include <regex>
#include <iostream>
int main(){
	std::regex re(R"(\d{4}(\-|\.)\d{1,2}(\-|\.)\d{1,2})");
	std::string a("I am zhangshuaishuai. I was born on 2000.10.20. My phone number is 18866667777 and you can also reach me by my ");
	if (std::regex_search(a, re)) std::cout << "Match"; else std::cout << "Unmatch";
}

