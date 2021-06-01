#include "wrapper_counter.h"

class AbstractWrapper {
	string uid;
	string _type;
public:
	AbstractWrapper(string tp = "null"): _type(tp) {
		uid = WrapperCounter::getUID(_type);
	}
	virtual ~AbstractWrapper(){ }
	virtual string type(){ return _type; }
	virtual string to_string() = 0;
	friend ostream &operator <<(ostream &out, AbstractWrapper *w) {
		return out << w->uid << ": " << w->to_string();
	}
};

class IntegerWrapper : public AbstractWrapper {
	int *ptr;
public:
	IntegerWrapper(int *ptr, string tp = "int")
		: AbstractWrapper(tp), ptr(ptr) {}
	virtual ~IntegerWrapper(){ delete ptr; }
	virtual string to_string() {
		return std::to_string(*ptr);
	}
};

class StringWrapper : public AbstractWrapper {
protected:
	char *ptr;
	int len;
public:
	StringWrapper(char *ptr, int len, string tp = "string")
		: AbstractWrapper(tp), ptr(ptr), len(len) {}
	virtual ~StringWrapper() { delete []ptr; }
	int length() { return len; }
	virtual string to_string() {
		return string(ptr, len);
	}
};

class ChineseStringWrapper : public StringWrapper {
	// 用三个char表示一个汉字
public:
	ChineseStringWrapper(char *ptr, int len, string tp = "chineseString")
		: StringWrapper(ptr, len, tp) {}
	virtual ~ChineseStringWrapper() { }
	int length(bool rawChars = true) {
		// 如果rawChars为false，则返回中文字符数；否则返回实际char数组长度
		if (rawChars) return len;
		else return len / 3;
	}
};
