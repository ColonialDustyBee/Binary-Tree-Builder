# Binary-Tree-Builder

A short C++ program that builds a simple binary tree from a txt file that is provided.

The txt file that is provided to the program will contain the binary tree you wish to build and must be in the following format for the program to execute without crashing:

a,b L/R

Where:
a is the parent node, the node that you are added a child node to
b is the child node, the node that you are adding to the parent node,
L/R which is referred to as the edge case, which tells the program whether to add the child node on the left or right of the parent node. You must only pick one 

You must ensure that each "a,b L/R" input is on separate lines to ensure that the tree is built properly, failure to do so will most likely result in a crash.

An example .txt file will be provided in this repo which is proven to work with this program.

This program will go through the following processes:

1. Asks you for the name of the .txt file
2. Reads from the txt file and creates the binary tree based on the input provided
3. Asks you whether you would like to do preorder, inorder, or postorder traversals, currently it only allows for one selection and if you make an incorrect selection you'll have to restart the program. I will most likely improve on this at a later time.


Feel free to tweak this program if you'd like, I will most likely revise this at a later time to make it more verbose.
