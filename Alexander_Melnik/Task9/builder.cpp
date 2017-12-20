#include "builder.h"

#include <iostream> // cout and more
#include <fstream> // ifstream
#include <sstream> // istringstream
#include <vector> // vector
#include <cassert> // assert

struct BinTreeNode {
    int value;
    BinTreeNode *left = nullptr, *right = nullptr;
};

BinTreeNode* buildTreeFromFile(const char *filename);
void deleteTree(BinTreeNode *head); // TODO: crashes during pointer deleting
int findPathWithMaxSum(BinTreeNode *head, int &sum, int &maxSum, std::string &currPath, std::string &maxPath);

void testFindPathWithMaxSum();

void initTask9() {

    std::cout << "Task9" << std::endl;

    std::cout << "Testing..." << std::endl;
    testFindPathWithMaxSum();
    std::cout << "Tests passed!" << std::endl;
}

BinTreeNode* buildTreeFromFile(const char *filename) {

    std::ifstream fi(filename);

    BinTreeNode *head;
    size_t prevQuantityOfNumbers = 0;
    std::vector<BinTreeNode*> leaves;

    while ( !fi.eof() ) {
        std::string s;
        std::getline(fi, s);

        std::istringstream ss(s);
        std::vector<BinTreeNode*> nodes;

        while ( !ss.eof() ) {
            int a;
            ss >> a;
            BinTreeNode *node = new BinTreeNode;
            node->value = a;
            nodes.push_back(node);
        }

        if (nodes.size() == 1) {
            if (prevQuantityOfNumbers != 0) {
                // free allocated memory
                delete nodes[0];
                // then throw an exception
                throw std::runtime_error("Incorrect input data. First line must contain only 1 number.");
            }
            prevQuantityOfNumbers = 1;

            head = nodes[0];
            leaves.push_back(head);

        } else if (nodes.size() > 1) {
            if ( nodes.size() != (prevQuantityOfNumbers + 1) ) {
                // free allocated memory
                deleteTree(head);
                for (BinTreeNode *p : nodes) {
                    delete p;
                }
                // then throw an exception
                throw std::runtime_error("Incorrect input data. Quantity of numbers in every next line must be greater by 1 than quantity of numbers in previous line.");
            }
            prevQuantityOfNumbers = nodes.size();

            for (size_t i = 0; i < leaves.size(); i++) {
                leaves[i]->left = nodes[i];
                leaves[i]->right = nodes[i+1];
            }

            leaves.clear();
            for (BinTreeNode *p : nodes) {
                leaves.push_back(p);
            }
        }
    }

    fi.close();

    return head;
}

void deleteTree(BinTreeNode *head) {

    if (head == nullptr) {
        return;
    }

    if ((head->left == nullptr) && (head->right == nullptr)) {
        // TODO
        // delete head;
        head = nullptr; // memory leak
        return;
    }

    deleteTree(head->left);
    deleteTree(head->right);

    // TODO
    // delete head;
    head = nullptr; // memory leak
}

int findPathWithMaxSum(BinTreeNode *head, int &sum, int &maxSum, std::string &currPath, std::string &maxPath) {

    if (head->left == nullptr) {
        return sum + head->value;
    }

    sum += head->value;

    maxSum = std::max(sum, maxSum);

    int s;

    currPath += 'L';
    if ( (s = findPathWithMaxSum(head->left, sum, maxSum, currPath, maxPath)) > maxSum ) {
        maxSum = s;
        maxPath = currPath;
    }
    currPath.pop_back();

    currPath += 'R';
    if ( (s = findPathWithMaxSum(head->right, sum, maxSum, currPath, maxPath)) > maxSum ) {
        maxSum = s;
        maxPath = currPath;
    }
    currPath.pop_back();

    sum -= head->value;


    return maxSum;
}

void testFindPathWithMaxSum() {

    BinTreeNode *head;

    int sum = 0;
    int maxSum = -1;
    std::string currPath;
    std::string maxPath;

    // 1st test
    head = buildTreeFromFile("../Alexander_Melnik/Task9/tests/1.txt");
    assert(findPathWithMaxSum(head, sum, maxSum, currPath, maxPath) == 29);
    assert(maxPath == "RLRLRR");
    deleteTree(head);


    sum = 0;
    maxSum = -1;
    currPath.clear();

    // 2nd test
    head = buildTreeFromFile("../Alexander_Melnik/Task9/tests/2.txt");
    assert(findPathWithMaxSum(head, sum, maxSum, currPath, maxPath) == 17);
    assert(maxPath == "LRRRRR");
    deleteTree(head);


    sum = 0;
    maxSum = -1;
    currPath.clear();

    // 3rd test
    head = buildTreeFromFile("../Alexander_Melnik/Task9/tests/test.txt");
    assert(findPathWithMaxSum(head, sum, maxSum, currPath, maxPath) == 20);
    assert(maxPath == "RRR");
    deleteTree(head);
}
