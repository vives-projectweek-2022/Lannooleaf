#include "include/graph.h"

namespace Lannooleaf {

  Graph::Graph() { }

  Graph::~Graph() {
    std::map < uint8_t, Node * > ::iterator i;
    for (i = map.begin(); i != map.end(); i++) {
      delete i -> second;
    }
  }

  void Graph::add_node(const uint8_t & address) {
    nodemap::iterator itr = map.find(address);

    if (itr == map.end()) {
      Node * node;
      node = new Node(address);
      map[address] = node;
      return;
    }
  }

  void Graph::add_edge(const uint8_t & from, const side & from_side, const uint8_t & to) {
    Node * f = (map.find(from) -> second);
    Node * t = (map.find(to) -> second);

    std::pair < side, Node * > from_edge = std::make_pair(from_side, t);

    f -> adj.push_back(from_edge);
  }

  void Graph::clear(void) {
    std::map < uint8_t, Node * > ::iterator i;
    for (i = map.begin(); i != map.end(); i++) {
      delete i -> second;
    }

    map.clear();
  }

  std::string Graph::to_string(void) {
    std::stringstream stream;
    std::map <uint8_t, Node *> ::iterator i;
    for (i = map.begin(); i != map.end(); i++) {
      stream << "Node: "  << std::to_string(i -> second -> i2c_address) << "\r\n";

      stream << "Adjecent nodes: ";
      for (std::vector < std::pair < side, Node * >> ::iterator itr = i -> second -> adj.begin(); itr != i -> second -> adj.end(); ++itr) {
        stream << "side: " << side_to_char(itr -> first) << " -> " << std::to_string(itr -> second -> i2c_address);
      }

      stream << "\r\n";
    }

    return stream.str();
  }

}