#include "builder.h"

#include <iostream> // cout and more
#include <fstream> // ifstream
#include <sstream> // istringstream
#include <vector> // vector
#include <cassert> // assert

struct BinTreeNode {
    int value;
    BinTreeNode *left = NULL, *right = NULL;
};

BinTreeNode* buildTreeFromFile(const char *filename); // TODO: memory must be free before throwing exception
void deleteTree(BinTreeNode *head); // TODO: fix (NULL != NULL)
int findPathWithMaxSum(BinTreeNode *head, std::string &maxPath); // TODO: fix (set static variables to zero)

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
                throw std::runtime_error("Incorrect input data. First line must contain only 1 number.");
            }
            prevQuantityOfNumbers = 1;

            head = nodes[0];
            leaves.push_back(head);

        } else if (nodes.size() > 1) {
            if ( nodes.size() != (prevQuantityOfNumbers + 1) ) {
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

    if (head == NULL) {
        return;
    }

    if ((head->left == NULL) && (head->right == NULL)) {
        delete head;
        return;
    }

    deleteTree(head->left);
    deleteTree(head->right);

    delete head;
}

int findPathWithMaxSum(BinTreeNode *head, std::string &maxPath) {

    static int sum = 0;
    static int maxSum = 0;
    static std::string currPath;

    if (head->left == NULL) {
        return sum + head->value;
    }

    sum += head->value;

    maxSum = std::max(sum, maxSum);

    int s;

    currPath += 'L';
    if ( (s = findPathWithMaxSum(head->left, maxPath)) > maxSum ) {
        maxSum = s;
        maxPath = currPath;
    }
    currPath.pop_back();

    currPath += 'R';
    if ( (s = findPathWithMaxSum(head->right, maxPath)) > maxSum ) {
        maxSum = s;
        maxPath = currPath;
    }
    currPath.pop_back();

    sum -= head->value;


    return maxSum;
}

void testFindPathWithMaxSum() {

    BinTreeNode* head;
    std::string maxPath;

    head = buildTreeFromFile("../tests/1.txt");
    assert(findPathWithMaxSum(head, maxPath) == 29);
    assert(maxPath == "RLRLRR");
    deleteTree(head);

    head = buildTreeFromFile("../tests/2.txt");
    assert(findPathWithMaxSum(head, maxPath) == 17);
    assert(maxPath == "LRRRRR");
    deleteTree(head);

    head = buildTreeFromFile("../tests/test.txt");
    assert(findPathWithMaxSum(head, maxPath) == 20);
    assert(maxPath == "RRR");
    deleteTree(head);
}