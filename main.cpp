#include <iostream>
#include <fstream>
#include "node.pb.h"

using namespace std;

// add node to node_list
void add_node(NodeList& node_list, int id, string name, int parent_id, int exe_id)
{
    Node* node = node_list.add_nodes();
    node->set_id(id);
    node->set_name(name);
    node->set_parent_id(parent_id);
    node->set_exe_id(exe_id);
}

void add_executor(ExecutorMap& executor_map, int id, string name, int parent_id)
{
    Executor executor;
    executor.set_id(id);
    executor.set_name(name);
    executor.set_parent_id(parent_id);
    executor_map.mutable_executors()->insert(std::make_pair(id, executor));
}

int main()
{
    // Create a NodeList message
    NodeList node_list;

    // Create a Node message and add it to the NodeList
    add_node(node_list, 1, "Node 1", 0, 0);

    // Create another Node message and add it to the NodeList
    add_node(node_list, 2, "Node 2", 1, 0);

    for (int i = 0; i < 10000; ++i) {
        add_node(node_list, i, "Node " + to_string(i), i - 1, 0);
    }

    // Serialize the NodeList to a file
    std::ofstream node_list_output("node_list.bin", std::ios::binary);
    if (!node_list.SerializeToOstream(&node_list_output)) {
        std::cerr << "Failed to serialize NodeList." << std::endl;
        return 1;
    }

        // Create an ExecutorMap message
    ExecutorMap executor_map;

    for (int i = 0; i < 100; ++i) {
        add_executor(executor_map, i, "Executor " + to_string(i), i - 1);
    }

    // Print the ExecutorMap
    for (const auto& e : executor_map.executors()) {
        std::cout << "Executor " << e.second.id() << ": " << e.second.name() << std::endl;
    }

    // Serialize the ExecutorMap to a file
    std::ofstream executor_map_output("executor_map.bin", std::ios::binary);
    if (!executor_map.SerializeToOstream(&executor_map_output)) {
        std::cerr << "Failed to serialize ExecutorMap." << std::endl;
        return 1;
    }
    return 0;
}