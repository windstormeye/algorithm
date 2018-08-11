//
//  traversalOfBinaryTree.cpp
//  nowCoder
//
//  Created by pjpjpj on 2018/8/11.
//  Copyright © 2018年 pjpjpj. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <typeinfo>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
    val(x), left(nullptr), right(nullptr) {}
};

class TreePrinter {
public:
    // Printer by BFS
    std::vector<std::vector<int> > printTree(TreeNode* root) {
        std::queue<TreeNode *> queue;
        std::vector<std::vector<int> > finalVec;
        
        if (root) {
            queue.push(root);
            queue.push(nullptr);
            std::vector<int> layerVec;
            
            while (!queue.empty()) {
                TreeNode *frontNode = queue.front();
                queue.pop();
                
                if (frontNode) {
                    layerVec.push_back(frontNode->val);
                    
                    if (frontNode->left != nullptr) {
                        queue.push(frontNode->left);
                    }
                    if (frontNode->right != nullptr) {
                        queue.push(frontNode->right);
                    }
                } else {
                    finalVec.push_back(layerVec);
                    layerVec.clear();
                    if (!queue.empty()) {
                        queue.push(nullptr);
                    }
                }
            }
        }
        return finalVec;
    }
    
    
    // serialization by BFS
    bool serializationBinaryTree(std::vector<std::vector<int> > finalVec) {
        std::ofstream fileOut;
        fileOut.open("traversalOfBinaryTree.txt");
        
        if (!fileOut) {
            return false;
        }
        
        for (std::vector<std::vector<int> >::iterator vec = finalVec.begin(); vec != finalVec.end(); vec ++) {
            std::vector<int> tempVec = *vec;
            for (std::vector<int>::iterator instance = tempVec.begin(); instance != tempVec.end(); instance ++) {
                std::cout << *instance << std::ends;
                fileOut << *instance;
            }
            fileOut << std::endl;
            std::cout << std::endl;
        }
        
        fileOut.close();
        return true;
    }
    
    
    // deserialization by BFS
    TreeNode* deserializationBinaryTree() {
        std::ifstream fileIn;
        fileIn.open("traversalOfBinaryTree.txt");
        
        std::vector<std::vector<int>> finalVec;
        
        if (!fileIn) {
            return nullptr;
        }
        
        TreeNode *rootNode = nullptr, *currentNode = nullptr;
        std::queue<int> queue;
        std::queue<TreeNode *> nodeQueue;
        
        while(!fileIn.eof()) {
            std::string tmpString;
            std::getline(fileIn, tmpString);
            
            for (int i = 0; i < tmpString.length(); i ++) {
                queue.push(tmpString[i] - 48);
            }
            // int queue don't accept nullptr, becauese of it's real null pointer
            queue.push(-1);
        }
        
        
        while (!queue.empty()) {
            if (!rootNode) {
                rootNode = new TreeNode(queue.front());
                nodeQueue.push(rootNode);
                queue.pop();
                
                currentNode = rootNode;
            } else {
                if (queue.front() == -1) {
                    queue.pop();
                } else {
                    if (!currentNode->left) {
                        currentNode->left = new TreeNode(queue.front());
                        nodeQueue.push(currentNode->left);
                        queue.pop();
                    } else if (!currentNode->right) {
                        currentNode->right = new TreeNode(queue.front());
                        nodeQueue.push(currentNode->right);
                        queue.pop();
                    } else {
                        currentNode = nodeQueue.front();
                        nodeQueue.pop();
                    }
                }
            }
        }
        
        fileIn.close();

        return rootNode;
    }
    
    // try to use template
    void clear(std::queue<TreeNode *>& q) {
        std::queue<TreeNode *> empty;
        swap(empty, q);
    }
};


int main(int argc, const char * argv[]) {
    
    TreeNode *rootNode = new TreeNode(1);
    TreeNode *node1 = new TreeNode(2);
    rootNode->left = node1;
    TreeNode *node2 = new TreeNode(3);
    rootNode->right = node2;
    TreeNode *node3 = new TreeNode(4);
    node1->left = node3;
    TreeNode *node4 = new TreeNode(5);
    node1->right = node4;
    TreeNode *node5 = new TreeNode(6);
    node2->left = node5;
    TreeNode *node6 = new TreeNode(7);
    node2->right = node6;
    
    
    TreePrinter *printer = new TreePrinter();
//    std::vector<std::vector<int>> finalVec = printer->printTree(rootNode);
//    for (std::vector<std::vector<int> >::iterator vec = finalVec.begin(); vec != finalVec.end(); vec ++) {
//        std::vector<int> tempVec = *vec;
//        for (std::vector<int>::iterator instance = tempVec.begin(); instance != tempVec.end(); instance ++) {
//            std::cout << *instance << std::ends;
//        }
//        std::cout << std::endl;
//    }
    
//    printer->serializationBinaryTree(finalVec);
    
    
    std::vector<std::vector<int>> finalVec = printer->printTree(printer->deserializationBinaryTree());
    for (std::vector<std::vector<int> >::iterator vec = finalVec.begin(); vec != finalVec.end(); vec ++) {
        std::vector<int> tempVec = *vec;
        for (std::vector<int>::iterator instance = tempVec.begin(); instance != tempVec.end(); instance ++) {
            std::cout << *instance << std::ends;
        }
        std::cout << std::endl;
    }

    
    return 0;
}
