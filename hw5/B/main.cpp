//Pionniers du TJ, benissiez-moi par votre Esprits Saints!
//It rained on us at 4am.
#include <regex>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
std::vector<std::pair<std::pair<std::string, std::string>, std::pair<std::string, std::string> > > v;
bool check(char x){
	return ('0' <= x && x <= '9') || ('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z');
}
int main(){
	int n;
	std::cin >> n;
	std::string nullstr;
	std::getline(std::cin, nullstr);
	while (n--){
		std::string a, name, date, phone, email;
		std::getline(std::cin, a);
		//if (a.find("shenteng") != a.npos) std::cout << a << std::endl;
		char name1[] = "I am ", name2[] = "My name is ";
		int l1 = a.find(name1), z1 = l1 + strlen(name1);
		int l2 = a.find(name2), z2 = l2 + strlen(name2);
		int stp, st, ed;
		if (l1 == a.npos) stp = z2;
		else if (l2 == a.npos) stp = z1;
		else if (l1 < l2) stp = z1; else stp = z2;
		//if (a.find(name2) == a.find(name1)) puts(a.c_str());
		name = a.substr(stp, a.find(".") - stp);
		//puts("name match");
		a = a.substr(a.find(".") + 1, a.npos);
		std::regex re(R"(\d{4}(\-|\.)\d{1,2}(\-|\.)\d{1,2})");
		std::smatch sm;
		std::regex_search(a, sm, re);
		date = sm[0];
		//std::cout << "date: " << sm.size() << std::endl;
		int dot1 = date.find("-"), dot2 = date.find("-", dot1 + 1);
		if (dot1 != date.npos && dot2 != date.npos)
			date.replace(dot1, 1, "."), date.replace(dot2, 1, ".");
		dot1 = date.find("."), dot2 = date.find(".", dot1 + 1);
		bool bq1 = dot2 - dot1 == 2, bq2 = date.size() - dot2 == 2;
		if (bq1) date.insert(dot1 + 1, "0"), ++dot2;
		if (bq2) date.insert(dot2 + 1, "0");
		std::regex re2(R"(\d{11})");
		std::regex_search(a, sm, re2);
		phone = sm[0];
		/* 
		int ps1 = a.find("@");
		for (int i = ps1 - 1; ~i; --i)
			if (!check(a[i])){ st = i + 1; break; }
		for (int i = ps1 + 1, tms = 0; i < a.size(); ++i)
			if (!check(a[i]))
				if (a[i] == '.' && !tms) ++tms; else { ed = i - 1; break; }
		*/
		std::regex re3(R"(\w[-\w.+]*@([A-Za-z0-9][-A-Za-z0-9]+\.)+[A-Za-z]{2,14})");
		std::regex_search(a, sm, re3);
		email = sm[0];
		v.push_back(std::make_pair(std::make_pair(date, name), std::make_pair(phone, email)));
	}
	std::sort(v.begin(), v.end());
	for (auto i: v) std::cout << i.first.second << "-" << i.first.first << "-" <<
		i.second.first << "-" << i.second.second << std::endl;
	return 0;
}

