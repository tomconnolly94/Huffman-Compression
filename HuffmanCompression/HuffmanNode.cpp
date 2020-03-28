#include <cstddef>

#include "HuffmanNode.h"

HuffmanNode::HuffmanNode(int data, int frequency) {
    this->data = data;
    this->frequency = frequency;
    left = NULL;
    right = NULL;
};
