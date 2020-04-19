#pragma once
#include <stdexcept>
#include <string>
#include <vector>
  

using namespace std;

namespace family
{ 
class Tree
{
    string name;
    Tree *father;
    Tree *mother;
    Tree *son;
    char g;

public:
    Tree(string name)
    {
        this->name = name;
        this->father = NULL;
        this->mother = NULL;
        this->son = NULL;
    }
//constructor for add new father or new mother
    Tree(string name, Tree *son)
    {
        this->name = name;
        this->son = son;
        this->father = this->mother = NULL;
    }
    ~Tree() {
                delete this->father;
                delete this->mother;
                // printf("distractor to: %s\n", this->name.c_str());
            }
    //all the functions
    Tree &addFather(string son, string father);
    Tree &addMother(string son,string mother);
    void display();
    void remove(string name);
    string relation(string name);
    string find(string relation);
    void deleteTree(Tree* t);
private:
    Tree* findMe(string name);
    void levelByLevel(Tree* root);
    bool findhelp(Tree* root,string name);  
    void print2DUtil(Tree *root, int space);
    vector<string>getNodesAtDistance(int distance);
    void getNodesAtDistance(Tree* root,int distance);
            
};
} // namespace family

