Assignment 2: K-d Trees
Huzaifa Iqbal 31563

/* *****************************************************************************
 *  Describe the Node data type you used to implement the
 *  2d-tree data structure.
 **************************************************************************** */
To implement my 2D-tree, I used a private struct Node inside the KdTreeST class. In each Node, I stored five key pieces of data: Point2D p (which holds the actual coordinates of the point), Value val (to store the value associated with that point, since it's a symbol table), and a RectHV rec. This rectangle is crucial because it represents the entire 2D space that the node and its children occupy, which helps optimize searches. Finally, I included two child pointers, Node *leftbot and Node *righttop, to link to the next nodes in the tree, representing either the left/right or bottom/top sub-regions.

/* *****************************************************************************
 *  Describe your method for range search in a k-d tree.
 **************************************************************************** */
My method for range search starts with a public range function that takes the query rectangle (RectHV). This function just creates an empty vector for the results and then calls a private recursive helper function, starting at the root.

This private helper function does all the real work. When it visits a node, it first checks if the node is null, and just returns if it is. Then, it checks if the point in the current node is contained within the query rectangle. If it is, I add that point to my results vector.

The most important part is the pruning. Before recursively visiting the children, I check if the query rectangle intersects with the child's own rectangle (the rec I stored in each node). If the query rectangle and the leftbot child's rectangle overlap, I recursively search that child. I do the exact same check for the righttop child. This way, if a whole section of the tree is in a rectangle that doesn't even touch my query rectangle, I don't waste time searching it.


/* *****************************************************************************
 *  Describe your method for nearest neighbor search in a k-d tree.
 **************************************************************************** */
My method for finding the nearest neighbor starts with a public nearest function that just handles the basic setup. It throws an error if the tree is empty, otherwise, it sets the closest point (which I call champ) to be the root's point and minimum distance (which I call champdist) to be the distance to the root. Then, it calls the private, recursive nearest helper function to do the real search, starting at the root.

This private helper function is where the pruning logic happens.

First, it checks if the current node (r) is null. It also has a key optimization: it checks if the distance from the query point p to the node's entire rectangle (r->rec) is already greater than or equal to the best distance found so far (champdist). If either of these is true, it means there's no way a closer point could be in this branch, so I just return and prune this entire subtree.

If I don't prune, I calculate the distance from the query point to the current node's point. If this distance is better than champdist, I update champ to this node's point and champdist to this new, smaller distance.

Next, I have to decide which child to search first. Based on the current direction (whether we're splitting on x or y), I compare the query point's coordinate to the current node's. I set first to be the child on the same side as the query point and second to be the child on the other side.

I always search the first subtree recursively. This is because the closest point is most likely to be on the same side as my query point.

After that first call returns (which might have updated champdist), I then make the recursive call to search the second (other) subtree. The key is that this second call benefits from any closer point found in the first. If the first call found a really close point, the pruning check (in step 1) will now have a much smaller champdist, and it might be able to prune the entire second subtree right at the start.

/* *****************************************************************************
 *  How many nearest-neighbor calculations can your PointST implementation
 *  perform per second for input1M.txt (1 million points), where the query
 *  points are random points in the unit square?
 *
 *  Fill in the table below, rounding each value to use one digit after
 *  the decimal point. Use at least 1 second of CPU time. Do not use -Xint.
 *  (Do not count the time to read the points or to build the 2d-tree.)
 *  (See the checklist for information on how to do this)
 *
 *  Repeat the same question but with your KdTreeST implementation.
 *
 **************************************************************************** */


                 # calls to         /   CPU time     =   # calls to nearest()
                 client nearest()       (seconds)        per second
                ------------------------------------------------------
PointST:                1024       /     164.6      =      6.2

KdTreeST:              261120      /      1.4       =      188624.7  

Note: more calls per second indicates better performance.

/* *****************************************************************************
 *  Suppose you wanted to add a method numberInRange(RectHV rect) to your       
 *  KdTreeST, which should return the number of points that are inside rect
 *  (or on the boundary), i.e. the number of points in the iterable returned by
 *  calling range(rect).
 *
 *  Describe a pruning rule that would make this more efficient than the
 *  range() method. Also, briefly describe how you would implement it.
 *
 *  Hint: consider a range search. What can you do when the query rectangle
 *  completely contains the rectangle corresponding to a node?
 **************************************************************************** */
To make numberInRange more efficient than just calling range and getting its size, I'd add a new pruning rule. My range method already prunes branches that don't intersect the query rectangle. For numberInRange, I'd add a second rule: if the query rectangle completely contains the rectangle associated with the current node, I can stop searching that entire branch and just return the total number of nodes in that node's subtree. This is so much faster because my range method has to keep going down to every single leaf to collect all the points, but since I only need the count here, I can just grab the total size of that subtree in one go. To implement this, I'd first have to add a new int subtreesize field to my Node struct. Then, I'd update my put method so that when the recursion unwinds, it calculates and sets this size for each node (it would be 1 for the node itself, plus the subtreesize of its left and right children). Finally, my new recursive helper for numberInRange would use this: if the query rectangle contains the node's rectangle, it returns node->subtreesize. If there's no intersection, it returns 0. If it's a partial overlap, it would count the current node if it's in the rect, and then add the results from recursively calling on both children.
/* *****************************************************************************
 *  Describe your unit test results
 **************************************************************************** */
Overall Test Status:<in one sentence>.
Overall Test Status: My KdTreeST implementation passed all 5 test categories, demonstrating correct functionality for empty and single-node trees, basic operations, value updates, range searches, and nearest-neighbor searches.

Specific Test Cases:
1. **BasicKdTreeTest:** Passed.
2. **ModerateKdTreeTest:** Passed.
3. **HarderKdTreeTest:** Passed.
4. **EdgeCaseKDTreeTest:** Passed.
5. **NearestNeighborTest:** Passed.

Detailed Test Output:<a table of inputs and outputs for each of the tests>

Test Category                   Input(s)                                                                                  Output

EdgeCase (Empty)               tree.empty()                                                                                true
                              
                               tree.size()                                                                                   0
                               
                               tree.contains((0.5, 0.5))                                                                   false

                               tree.nearest((0.5, 0.5))                                                       Caught expected error: map is empty!



EdgeCase (Single)              tree.put((0.1, 0.1), "A")                                                                     -

                               tree.empty()                                                                                false

                               tree.size()                                                                                   1

                               tree.contains((0.1, 0.1))                                                                    true

                               tree.nearest((0.9, 0.9))                                                                  (0.1, 0.1)



BasicKdTreeTest                tree.put((0.7, 0.2), "P1")                                                                    -
(put, get, contains)
                               tree.put((0.5, 0.4), "P2")                                                                    -

                               tree.put((0.2, 0.3), "P3")                                                                    -

                               tree.size()                                                                                   3

                               tree.get((0.5, 0.4))                                                                          P2

                               tree.get((0.2, 0.3))                                                                          P3
 
                               tree.contains((0.7, 0.2))                                                                    true

                               tree.contains((0.9, 0.9))                                                                    false



Moderate (Iterator)            tree.put((0.4, 0.7), "P4")                                                                     -
                
                               tree.put((0.9, 0.6), "P5")                                                                     -

                               tree.size()                                                                                    5

                               Iterate from tree.begin()                          { (0.7, 0.2):P1 (0.5, 0.4):P2 (0.9, 0.6):P5 (0.2, 0.3):P3 (0.4, 0.7):P4 }



Moderate (Range)               tree.range(r1 [0.1, 0.6] x [0.1, 0.5])                                            { (0.5, 0.4), (0.2, 0.3) }

                               tree.range(r2 [0, 1] x [0, 1])                              { (0.7, 0.2), (0.5, 0.4), (0.2, 0.3), (0.4, 0.7), (0.9, 0.6) }

                               tree.range(r3 [0.8, 0.9] x [0.8, 0.9])                                               { No points found }



Harder (Update)                tree.get((0.7, 0.2))                                                                     P1 (Original)

                               tree.put((0.7, 0.2), "P1-Updated")                                                             -

                               tree.size()                                                                         5 (Size should not change)

                               tree.get((0.7, 0.2))                                                                   P1-Updated (Updated)

                               tree.get((0.5, 0.4))                                                                     P2 (Original)

                               tree.put((0.5, 0.4), "P2-Updated")                                                              -

                               tree.get((0.5, 0.4))                                                                   P2-Updated (Updated)



Nearest Neighbor               tree.nearest((0.25, 0.25))                                                                  (0.2, 0.3)

                               tree.nearest((0.8, 0.5))                                                                    (0.9, 0.6)

                               tree.nearest((0.5, 0.5))                                                                    (0.5, 0.4)

                               tree.nearest((0, 0))                                                                        (0.2, 0.3)

                               tree.nearest((0.4, 0.65))                                                                   (0.4, 0.7)





/* *****************************************************************************
 *  List any other comments here. Feel free to provide any feedback   
 *  on  how helpful the class meeting was and on how much you learned 
 * from doing the assignment, and whether you enjoyed doing it.
 **************************************************************************** */
