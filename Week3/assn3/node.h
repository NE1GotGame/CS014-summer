

#ifndef __NODE_H_
#define __NODE_H_

class Node {
  friend class Tree;
private:
  std::string value;
  int count;
  Node* left;
  Node* right;
};

#endif

