//Pionniers du TJ, benissiez-moi par votre Esprits Saints!
#include <string>
#include <vector>
#include <iostream>
inline char mapping(char x){
	switch (x){
		case 'a':
			return '\a';
		case 'b':
			return '\b';
		case 'e':
			return '\x1B';
		case 'E':
			return '\x1B';
		case 'f':
			return '\f';
		case 'n':
			return '\n';
		case 'r':
			return '\r';
		case 't':
			return '\t';
		case 'v':
			return '\v';
		default:
			return 0;
	}
}
class Console;
class agm{
protected:
	std::string op;
public:
	agm(): op(""){ }
	agm(std::string s1): op(s1){ }
	virtual void execute(Console &) = 0;
} ;
class opagm: public agm{
public:
	opagm(): agm(){ }
	opagm(std::string s1): agm(s1){ }
	void execute(Console &);
} ;
class otagm: public agm{
public:
	otagm(): agm(){ }
	otagm(std::string s1): agm(s1){ }
	void execute(Console &);
} ;
class Console{
	bool NewLine, Interpre, prtd, halt;
	std::ostream &os;
	bool judge(std::string s){
		if (s[0] != '-' || prtd) return false;
		for (int i = 1, l = s.length(); i < l; ++i)
			if (s[i] != 'e' && s[i] != 'E' && s[i] != 'n') return false;
		return true;
	}
public:
	Console(std::ostream &os1 = std::cout)
		: NewLine(true), Interpre(true), prtd(false), halt(false), os(os1){ }
	void SetInterpre(bool f){ Interpre = f; }
	void SetNewLine(bool f){ NewLine = f; }
	void Print(std::string s){
		if (halt) return ;
		if (!prtd) prtd = true; else os << " ";
		if (Interpre){
			int len = s.length();
			for (int i = 0; i < len - 1; ++i)
				if (s[i] == '\\'){
					char x = mapping(s[i + 1]);
					if (x) s.erase(i, 1), s[i] = x;
					else if (s[i + 1] == 'c'){
						s.erase(i), halt = true;
						break;
					}
				}
		}
		os << s;
	}
	void NextArg(std::string s){
		agm *cur = judge(s) ? (agm*)(new opagm(s)) : (agm*)(new otagm(s));
		cur->execute(*this);
	}
	~Console(){
		if (NewLine && !halt) os << std::endl;
	}
} ;
void opagm::execute(Console &con){
	if (op.find("n") != op.npos) con.SetNewLine(false);
	if (op.find("E") != op.npos) con.SetInterpre(false);
	if (op.find("e") != op.npos) con.SetInterpre(true);
}
void otagm::execute(Console &con){
	con.Print(op);
}
int main(int argc, char **argv){
	Console cur;
	for (int i = 1; i < argc; ++i) cur.NextArg(argv[i]);
	return 0;
}

