#include <iostream>
#include "FamilyTree.hpp"
#include <vector>
#include <stdexcept>
#include <string>
#include <bits/stdc++.h>
#include <exception>
#include <queue>
#define COUNT 10
using namespace std;
using namespace family;

static Tree *node = NULL;
static vector<string> list;
Tree &Tree::addFather(string son, string father)
{
    Tree *current = findMe(son);
    if (current == NULL)
        throw out_of_range{"Did not find the son " + son + " in the tree"};
    if (current->father != NULL)
        throw runtime_error("this son already have a father");
    current->father = new Tree(father, current);
    return *this;
}

Tree &Tree::addMother(string son, string mother)
{
    Tree *current = findMe(son);
    if (current == NULL)
        throw out_of_range{"Did not find the son " + son + " in the tree"};
    if (current->mother != NULL)
        throw runtime_error("this son already have a mother");
    current->mother = new Tree(mother, current);
    return *this;
}

void Tree::remove(string name)
{
    
    if (this->name == name)
        // throw out_of_range{"cant remove the root"};
        throw std::exception();
        Tree *current = findMe(name);
    if (current == NULL)
        // throw out_of_range{"did not find the person" + name};
       throw std::exception();
    if (current->son != NULL)
    {
        Tree *son = current->son;
        current->father = NULL;
        current->mother = NULL;
        if (son->father->name == name)
            son->father = NULL;
        else
        {
            son->mother = NULL;
        }
    }
}

string Tree::relation(string name)
{
    Tree *current = findMe(name);
    if (current == NULL)
        return "unrelated";
    if (this->name == name)
        return "me";
        if(this->father->name==name)
        return "father";
        if(this->mother->name==name)
        return "mother";
    string grand = "";
    string gender = "";
    if (current->son->father->name == name)
        gender = "father";
    else
        gender = "mother";
    int count = 0;
    while (current != NULL)
    {
        count++;
        current = current->son;
    }
    for (size_t i = 0; i < count - 3; i++)
    {
        grand += "great-";
    }
    if (count > 3)
    {
        grand += "grand" + gender;
        return grand;
    }
    if (count == 3)
        return "grand" + gender;
        //else-father or mother
        return gender;
}

string Tree::find(string relation)
{
    string gender = "";
    if (relation == "me")
        return this->name;
    if (relation.at(0) == 'm')
        return this->mother->name;
    if (relation.at(0) == 'f')
        return this->father->name;
    int size = relation.size();
    if (size > 6)
    {
        char check = relation.at(size - 6);
        if (check == 'f')
            gender = "father";
        else
            gender = "mother";
        if (relation.at(2) == 'a')
        {
            if (gender == "father")
            {
                if (this->father->father != NULL)
                    return this->father->father->name;
                if (this->mother->father != NULL)
                    return this->mother->father->name;
            }
            else //mother
            {
                if (this->father->mother != NULL)
                    return this->father->mother->name;
                if (this->mother->mother != NULL)
                    return this->mother->father->name;
            }
        }
    }
    if (relation.at(0) != 'g')
        throw out_of_range{"illegal relation"};
    int count = 3; //levels in tree
    for (size_t i = 0; i < relation.size(); i++)
    {
        if (relation.at(i) == '-')
            count++;
    }
    vector<string> list1 = getNodesAtDistance(count);
    for (size_t i = 0; i < list1.size(); i++)
    {
        Tree *current = findMe(list1.at(i));
        if (gender == "father")
        {
            if (current->son->father != NULL)
                return current->name;
        }
        else
        {
            if (current->son->mother == NULL)
                return current->name;
        }
    }
    throw out_of_range{"did not find a someone in the tree with this relation"};
}

void Tree::display()
{
    print2DUtil(this, 0);
}

bool Tree::findhelp(Tree *root, string name)
{
    if (root == NULL)
        return false;
    if (root->name == name)
    {
        node = root;
        return true;
    }
    return findhelp(root->father, name) ||
           findhelp(root->mother, name);
}

Tree *Tree::findMe(string name)
{
    bool check = findhelp(this, name);
    if (check == false)
        return NULL;
    else
        return node;
}

// https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
void Tree::print2DUtil(Tree *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->father, space);

    // Print current node after space
    // count
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->name << "\n";

    // Process left child
    print2DUtil(root->mother, space);
}
vector<string> Tree::getNodesAtDistance(int distance)
{
    getNodesAtDistance(this, distance-1);
    return list;
}

void Tree::getNodesAtDistance(Tree *root, int distance)
{
   // cout<<"list.size()"<<endl;

    if (root == NULL )
        return;

    if (distance == 0)
    {
       // cout<<"sdsd"<<endl;
        list.insert(list.begin(),root->name);
//        cout<< list.at(i)<<endl;
//        i++;
        return;
    }
    if(root->father==NULL && root->mother==NULL) {
        return;
    }

    if(root->mother==NULL){
         getNodesAtDistance(root->father,distance-1);
    }
    if(root->father==NULL){
         getNodesAtDistance(root->mother,distance-1);
    }

     getNodesAtDistance(root->mother, distance - 1);
     getNodesAtDistance(root->father, distance - 1);
}

// void Tree::deleteTree(Tree *t)
// {
//     if (t== NULL) return;

//     /* first delete both subtrees */
//     deleteTree(t->father);
//     deleteTree(t->mother);
//     free(t);
// }
