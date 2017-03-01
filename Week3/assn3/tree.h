#ifndef __TREE_H
#define __TREE_H

#include "node.h"

using namespace std;

class Tree {

private:
  Node *root;

private:
  void preOrder(Node *t){
    if(!t){
      return;
    }
    cout << t->value << ' ';
    if(t->left)
      preOrder(t->left);
    if(t->right)
      preOrder(t->right);
  }

public:
  Tree(){
    root = NULL;
  }
  ~Tree(){}
  void insert( const string &word ){ 
    if(search(word))
      insert_increment(root, word);
    else
      root = insert(word, root);
  }
  bool search( const string &word ){ 
    Node* temp = root;
    bool success = false;
    if(root == NULL)
      return false;
    else if(root->value == word)
      return true;
    else if(word <= root->value){
      root = root->left;
      success = search(word);
    }
    else{
      root = root->right;
      success = search(word);
    }
    root = temp;
    return success;
  }

  void inOrder( ){ 
    inOrder(root);
  }

  void postOrder( ){ 
    postOrder(root);
  }

  void preOrder( ){ 
    preOrder(root);
  }
  
  string largest( ){ 
    if(root == NULL)
      return "";
    else
      return largest(root);
  }

  string smallest( ){ 
    if(root == NULL)
      return "";
    else
      return smallest(root);
  }

  int height( const string &word ){ 
    int final = (get_max_depth() - 1) - get_depth(word);
    return final;
  }

  void remove( const string &word ){ 
    root = remove(root, word);
  }



private:
    
    static Node* insert(string word, Node *t){ 
    
    if(t == NULL){
      t = new Node;
      t->value = word;
      t->count = 0;
      t->left = NULL;
      t->right = NULL;
    }
    else if (word < t->value)
      t->left = insert(word, t->left);
    else if (word > t->value)
      t->right = insert(word, t->right);
    else
      t->value = word;
    return t;
  }
  
  void insert_increment(Node* t, const string &word){
    Node* temp = t;
    if(temp->value == word)
      temp->count++;
    else if( word <= temp->value){
      temp = temp->left;
      insert_increment(temp, word);
    }
    else{
      temp = temp->right;
      insert_increment(temp, word);
    }
    return;
  }
  
  void inOrder(Node *t){
    if(!t){
      cout << "";
      return;
    }
    if(t->left)
      inOrder(t->left);
    cout << t->value << ' ';
    if(t->right)
      inOrder(t->right);
  }
  
  void postOrder(Node *t){
    if(!t){
      cout << "";
      return;
    }
    if(t->left)
      postOrder(t->left);
    if(t->right)
      postOrder(t->right);
    cout << t->value << ' ';
  }
  
  string largest(Node* t){
    while(t->right)
      t = t->right;
    return t->value;
  }
  
  string smallest(Node* t){
    while(t->left)
      t = t->left;
    return t->value;
  }
  
  Node* remove(Node* t, const string& word){
    if(t){
      if(word > t->value)
        t->right = remove(t->right, word);
      else if(word < t->value)
        t->left = remove(t->left, word);
      else{
        if(t->right){
          Node* holder = t->right;
          while(holder->left)
            holder = holder->left;
          t->value = holder->value;
          t->right = remove(t->right, t->value);
        }
        else if(t->left){
          Node* holder = t->left;
          while(holder->right)
            holder = holder->right;
          t->value = holder->value;
          t->left = remove(t->left, t->value);
        }
        else{
          delete t;
          t = NULL;
        }
      }
    }
    return t;
  }
  
  int get_max_depth(){
    return get_max_depth(root);
  }
  
  int get_max_depth(Node *t){
    if(t == NULL)
      return 0;
    else{
      int left = get_max_depth(t->left);
      int right = get_max_depth(t->right);
      if(right < left)
        return(left + 1);
      else
        return(right + 1);
    }
  }
  
  int get_depth(string word){
    int depth = get_depth(root, word, 0);
    return depth;
  }
  
  int get_depth(Node *t, string word, int depth){
    if (t == NULL)
      return 0;
 
    if (t->value == word)
      return depth;
 
    int down = get_depth(t->left, word, depth+1);
    if (down != 0)
       return down;
 
    down = get_depth(t->right, word, depth+1);
    return down;
  }
};

#endif