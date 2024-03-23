/*
Madushan Rajendran
22/03/2024
This is program that calculates execution time for 2 Binary Trees and saves it in a text file
*/

#include <iostream>
#include <random>
#include <fstream>
#include <unordered_map>
#include <chrono>

using namespace std;
using namespace std::chrono;

//Node Structure
struct node {
    int data;
    struct node *right, *left;
};

//Creates new Node
struct node* newNode(int value) {
    auto *temp = new struct node;
    temp->data = value;
    temp->right = temp->left = nullptr;
    return temp;
}

//Inserts Node in BST
struct node* insert(struct node* node, int value) {
    if (node == nullptr)
        return newNode(value);

    if (node->data > value)
        node->left = insert(node->left, value);
    else if (node->data < value)
        node->right = insert(node->right, value);
    return node;
}

//Searches BST
struct node* search(struct node* node, int value) {
    if (node == nullptr || node->data == value)
        return node;

    if (node->data > value)
        return search(node->left, value);

    return search(node->right, value);
}

//Prints the BST
void printBST(struct node* node) {
    if (node == nullptr)
        return;
    // In-order traversal
    printBST(node->left);
    std::cout << node->data << " ";
    printBST(node->right);
}

//Saves BST to txt file
void BSTToFile(struct node* node, ofstream& outputFile, unordered_map<int, int>& frequencyMap) {
    if (node == nullptr)
        return;
    // In-order traversal
    BSTToFile(node->left,outputFile, frequencyMap);
    outputFile << node->data << endl;
    frequencyMap[node->data]++;
    BSTToFile(node->right, outputFile, frequencyMap);
    outputFile.close();
}

void deallocateMemory(struct node* node) {
    if (node == nullptr)
        return;
    deallocateMemory(node->left);
    deallocateMemory(node->right);
    delete node;
}

int main() {
    struct node* root = nullptr;

    //creates random number
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1000, 10000);
    int size = dis(gen);

    cout  << "SCENARIO 1" << endl;
    cout  << " --------------------------------" << endl;
    cout  << " INSERTING " << endl;
    std::cout << "Number of random numbers generated: " << size << std::endl;
    auto insert_start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; i++) {
        int value = dis(gen);
        root = insert(root, value);
    }
    auto insert_stop = std::chrono::high_resolution_clock::now();
    auto insert_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(insert_stop - insert_start);
    cout << "Execution time for insertion is : " << insert_duration.count() << " nanoseconds" << endl;

    cout  << " --------------------------------" << endl;
    cout  << " SEARCHING " << endl;
    int search_value = dis(gen);
    auto search_start = std::chrono::high_resolution_clock::now();
    if (search(root, search_value) == nullptr)
        cout << search_value << " Not Found " << endl;
    else
        cout << search_value << " Found" << endl;
    auto search_stop = std::chrono::high_resolution_clock::now();
    auto search_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(search_stop - search_start);
    cout << "Execution time for search is : " << search_duration.count() << " nanoseconds" << endl;

    cout  << " --------------------------------" << endl;
    cout  << " SAVING " << endl;
    auto save_start = std::chrono::high_resolution_clock::now();
    ofstream outputFile("UnsortedInput.txt");
    if (!outputFile) {
        cerr << "Unable to find File" << endl;
    }else{
    unordered_map<int, int> frequencyMap;
    BSTToFile(root, outputFile, frequencyMap);

    }
    auto save_stop = std::chrono::high_resolution_clock::now();
    auto save_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(save_stop - save_start);
    cout << "Execution time for saving is : " << save_duration.count() << " nanoseconds" << endl;

    cout  << " --------------------------------" << endl;
    cout  << " --------------------------------" << endl;

    cout  << "SCENARIO 2" << endl;
    cout  << " --------------------------------" << endl;
    cout  << " INSERTING " << endl;
    std::cout << "Number of random numbers generated: " << size << std::endl;
    std::uniform_int_distribution<> dis2(1, size);
    auto insert_start2 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; i++) {
        int value = dis2(gen);
        root = insert(root, value);
    }
    auto insert_stop2 = std::chrono::high_resolution_clock::now();
    auto insert_duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(insert_stop2 - insert_start2);
    cout << "Execution time for insertion is : " << insert_duration2.count() << " nanoseconds" << endl;

    cout  << " --------------------------------" << endl;
    cout  << " SEARCHING " << endl;
    int search_value2 = dis2(gen);
    auto search_start2 = std::chrono::high_resolution_clock::now();
    if (search(root, search_value2) == nullptr)
        cout << search_value2 << " Not Found " << endl;
    else
        cout << search_value << " Found" << endl;
    auto search_stop2 = std::chrono::high_resolution_clock::now();
    auto search_duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(search_stop2 - search_start2);
    cout << "Execution time for search is : " << search_duration2.count() << " nanoseconds" << endl;

    cout  << " --------------------------------" << endl;
    cout  << " SAVING " << endl;
    auto save_start2 = std::chrono::high_resolution_clock::now();
    ofstream outputFile2("SortedInput.txt");
    if (!outputFile2) {
        cerr << "Unable to find File" << endl;
    }else{
        unordered_map<int, int> frequencyMap;
        BSTToFile(root, outputFile2, frequencyMap);
    }
    auto save_stop2 = std::chrono::high_resolution_clock::now();
    auto save_duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(save_stop2 - save_start2);
    cout << "Execution time for saving is : " << save_duration2.count() << " nanoseconds" << endl;

    deallocateMemory(root);


    return 0;
}
