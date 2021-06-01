#include "graph.h"
#include "plusminus.h"

Graph::Graph(int num_node) {
    // 预分配节点空间
    nodes_.initialize(num_node);
}

void Graph::InsertPlaceholder(const string &node_name) {
    nodes_.insert(node_name, new PlaceholderNode(node_name));
}

void Graph::InsertConstant(const string &node_name, float value) {
    nodes_.insert(node_name, new ConstantNode(node_name, value));
}

void Graph::InsertOperation(const string &node_name, const string &operation_type, 
                                const string &input1, const string &input2) {
    if (operation_type == "+")
    	nodes_.insert(node_name, new PlusOperationNode(node_name, nodes_[input1], nodes_[input2]));
    if (operation_type == "-")
    	nodes_.insert(node_name, new MinusOperationNode(node_name, nodes_[input1], nodes_[input2]));
}

void Graph::Eval(const string &node_name, const int &argument_num, 
                    const string* argument_name_list_, const float* argument_value_list_) {

	for (int i = 0; i < argument_num; ++i){
		PlaceholderNode *p = dynamic_cast<PlaceholderNode*>(nodes_[argument_name_list_[i]]);
		if (p) p->set_val(argument_value_list_[i]);
	}
    nodes_[node_name]->calc();
    float temp_value = nodes_[node_name]->value();
    cout << std::fixed << setprecision(2) << temp_value << endl;   
}

Graph::~Graph() {
    
}


