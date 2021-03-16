# Red-Black-Tree
Implement a red black tree data structure using C programming constructs 

This is a ReadMe file for instructions to be done for the user to follow during compilation of the red black tree

Our inputs is taken in an infinite loop and the user has the benefit of using any of the functions associated so this becomes 
a switch case situation for the user.

So the input can be anything from 1 to 6 (integer input)
if the input is 1: It is the case to insertion into the red black tree and we need to input a number to insert into the RBT

if the input is 2: It is the case of deletion into the red black tree. In this a a number is inputted and that number is then searched 
into the Red Black tree and it is deleted.
# VERY IMPORTANT is that the number which is going to be deleted should be a part of the RBT from previously otherwise the program will give a memory error(SEGMENTATION FAULT) will be given and compilation terminated so delete it only if it is there in the RBT.

if the input is 3:In this case it will directly output the total number of leaves in the Red Black Tree directly

if the input is 4: In this case the height of the Red black Tree is directly given as output(The distance from the root to any black
leaf of the RBT) is returned

if the input is 5: In this case we output all elements in the range of 2 given limits. So we have to give 2 inputs with the difference of a spacebar and the output is printed(integers aldready in the RBT ) are given

if the input is 6: In this case the output is the entire tree is printed. 
#VERY IMPORTANT to noted that the tree is printed in the inorder traversal when this function is called based on the number of remaining elements

the cycle of all the inputs is put inside an infinite loop so after completion of a particular input the loop starts again and the next desired input is given and the program runs just don't forget the segmentation fault in the case 2.

press 0 to exit from the loop to complete the compilation of the program
if any number in the switch case other than 1-6 will demand in another input which is valid else compilation will not proceed
in the case of insertion,range checking any valid integer will do.



