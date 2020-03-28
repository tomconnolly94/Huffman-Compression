#pragma once

class HuffmanNode {
public:
    int data;
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;
    HuffmanNode(int data, int frequency);
};