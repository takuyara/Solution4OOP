代码架构：
VAAdapter: 虚方法play, pause, doublespeed
VideoAdapter: public VAAdapter，有一个Video*的指针，实现三个虚方法
AudioAdapter: public VAAdapter，有一个Audio*的指针，实现三个虚方法
Player：std::vector<VAAdapter*>，直接调用三个接口就行

设计思路：在适配器模式中，由于Audio和Video没有同样的接口，应当设计一个适配器，包含一个抽象的基类VAAdapter，有play、pause、doublespeed三种接口，来包装上两种不同的适配器。
VAAdapter有两个子类，VideoAdapter和AudioAdapter，采取组合的方式，分别有一个Video*和Audio*的成员变量，实现VAAdapter的接口。Player中的成员设置为VAAdapter即可，调用时只需要调用VAAdapter的接口，不需要考虑Video或Audio的区别。