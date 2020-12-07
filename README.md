# Data-Structures-Project-Chestnut-Tree
- Goal of this project was to implement a data structure not viable called a Chestnut Tree (CTree). This is when a node is imbalanced if the 
difference of the sizes of the left and right subtrees exceeds two. We call this the size-balance property (analagous to the height-balance property for AVL trees). 
Insertion and deletion proceed as for an unbalanced binary search tree until we notice that the balance condition is violated; then we must rebalance the 
subtree of the CTree rooted at this node. 

- The implementation requirements were to make a correct and efficient implementation of CTree implementing the basic, using an array-based restructuring method. As well as an 
analysis of special cases in which trinode restructuring could be applied for faster rebalancing; implementation of trinode restructuring for one or more of these cases. 
