#include <catch2/catch_test_macros.hpp>
#include <iostream>

#include "interquartile_range.h"

using namespace std;

TEST_CASE("Test 1 - All elements the same", "[edge]") {
    std::vector<int> v = {5, 5, 5, 5, 5, 5, 5};
    Node* head = nullptr;
    for (int i : v)
        head = insertEnd(head, i);

    REQUIRE(interQuartile(head) == 0.00); 

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Test 2 - Negative numbers included", "[edge]") {
    std::vector<int> v = {-10, -5, 0, 5, 10, 15, 20};
    Node* head = nullptr;
    for (int i : v)
        head = insertEnd(head, i);

    REQUIRE(interQuartile(head) == 20.00); 

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Test 3 - Alternating negatives and positives", "[custom]") {
    std::vector<int> v = {-20, -10, 0, 10, 20, 30, 40};
    Node* head = nullptr;
    for (int i : v)
        head = insertEnd(head, i);

    REQUIRE(interQuartile(head) == 40.00);

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Test 4 - Skewed dataset with many duplicates", "[custom]") {
    std::vector<int> v = {1, 1, 1, 1, 50, 100, 100, 100, 100};
    Node* head = nullptr;
    for (int i : v)
        head = insertEnd(head, i);

    REQUIRE(interQuartile(head) == 99.00); 

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Test 5 - Prime numbers only", "[unique]") {
    std::vector<int> v = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    Node* head = nullptr;
    for (int i : v)
        head = insertEnd(head, i);

    REQUIRE(interQuartile(head) == 14.00);

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
