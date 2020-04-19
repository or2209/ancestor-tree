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
namespace family
{

static Tree *node = NULL;
static vector<string> list;
Tree &Tree::addFather(string son, string father)
{
    Tree *current = findMe(son);
    if (current == NULL)
    {
        throw runtime_error("exception caught:Did not find the son " + son + " in the tree");
    }
    if (current->father != NULL && current->father->name != "0")
        throw runtime_error("this son " + son + " already has a father");
    current->father = new Tree(father, current);
    current->father->g = 'm';
    return *this;
}

Tree &Tree::addMother(string son, string mother)
{
    Tree *current = findMe(son);
    if (current == NULL)
        throw runtime_error("exception caught:Did not find the son " + son + " in the tree");
    if (current->mother != NULL && current->mother->name != "0")
        throw runtime_error("this son " + son + " already has a mother");
    current->mother = new Tree(mother, current);
    current->mother->g = 'f';
    return *this;
}

void Tree::remove(string name)
{
    if (this->name == name)
        throw runtime_error("cant remove the root");
    Tree *current = findMe(name);
    if (current)
    {
        Tree &temp = *current;
        temp.father = NULL;
        temp.mother = NULL;
        Tree *a = new Tree("0");
        temp = *a;
    }
    else
    {
        __throw_out_of_range("This name not exit in Tree");
    }

    // if (this->name == name)
    //     // throw out_of_range{"cant remove the root"};
    //     // std::cerr << "cant remove the root" << '\n';
    //      throw runtime_error("cant delete the root");
    //      node=NULL;
    // Tree *current = findMe(name);
    // if (current == NULL)
    //     // throw out_of_range{"did not find the person" + name};
    //     // std::cerr << "did not find the person " + name << '\n';
    //     throw runtime_error("cant delete-this person not found in tree");
    //     // Tree *son = current->son;
    //     current->father = NULL;
    //     current->mother = NULL;
    //     current=NULL;
}

string Tree::relation(string name) //still need to check
{
    Tree *current = findMe(name);
    if (current == NULL)
        return "unrelated";
    if (this->name == name)
        return "me";
    if (this->father->name == name)
        return "father";
    if (this->mother->name == name)
        return "mother";
    if (this->father->mother != NULL)
    {
        if (this->father->mother->name == name)
            return "grandmother";
    }
    if (this->father->father != NULL)
    {
        if (this->father->father->name == name)
            return "grandfather";
    }
    if (this->mother->father != NULL)
    {
        if (this->mother->father->name == name)
            return "grandfather";
    }
    if (this->mother->mother != NULL)
    {
        if (this->mother->mother->name == name)
            return "grandmother";
    }
    string grand = "";
    string gender = "";
    if (current->g == 'm')
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
    return gender;
}

string Tree::find(string relation)
{
    string gender = "";
    if (relation == "me")
        return this->name;
    if (relation == "mother")
    {
        if (this->mother->name != "0")
            return this->mother->name;
    }
    if (relation == "father")
    {
        if (this->father->name != "0")
            return this->father->name;
    }
    if (relation.at(0) != 'g')
    {
        throw runtime_error("illegal relation input");
    }
    int size = relation.size();
    if (size > 6)
    {
        char check = relation.at(size - 6);
        if (check == 'f')
            gender = "father";
        else if (check == 'm')
            gender = "mother";
        if (relation == "grandfather" || relation == "grandmother")
        {
            if (gender == "father")
            {
                if (this->father->father != NULL && this->father->father->name != "0")
                    return this->father->father->name;
                if (this->mother->father != NULL && this->mother->father->name != "0")
                    return this->mother->father->name;
            }
            else //mother
            {
                if (this->father->mother != NULL && this->father->mother->name != "0")
                    return this->father->mother->name;
                if (this->mother->mother != NULL && this->mother->mother->name != "0")
                    return this->mother->mother->name;
            }
        }
    }
    bool f = false;
    for (int i = 0; i < relation.size(); i++)
    {
        if (relation.at(i) == '-')
            f = true;
    }
    if (!f)
    {
        throw exception();
    }
    // if (relation.at(0) != 'g')
    //     std::cerr << "illegal relation " << '\n';
    int count = 3; //levels in tree
    for (size_t i = 0; i < relation.size(); i++)
    {
        if (relation.at(i) == '-')
            count++;
    }
    list.clear();
    vector<string> list1 = getNodesAtDistance(count);
    for (size_t i = 0; i < list1.size(); i++)
    {
        Tree *current = findMe(list1.at(i));
        if (current->g == 'm' && gender == "father" && current->name != "0")
        {
            // if (current->son->father != NULL)
            return current->name;
        }
        else if (current->g == 'f' && gender == "mother" && current->name != "0")
        {
            // if (current->son->mother == NULL)
            return current->name;
        }
    }
    throw runtime_error("illegal relation input");
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
    node = NULL;
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
    getNodesAtDistance(this, distance - 1);
    return list;
}

void Tree::getNodesAtDistance(Tree *root, int distance)
{
    if (root == NULL)
        return;

    if (distance == 0)
    {
        list.push_back(root->name);
        return;
    }
    if (root->father == NULL && root->mother == NULL)
    {
        return;
    }

    if (root->mother == NULL)
    {
        getNodesAtDistance(root->father, distance - 1);
    }
    if (root->father == NULL)
    {
        getNodesAtDistance(root->mother, distance - 1);
    }

    getNodesAtDistance(root->mother, distance - 1);
    getNodesAtDistance(root->father, distance - 1);
}
} // namespace family