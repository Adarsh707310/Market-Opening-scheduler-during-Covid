# Market-Opening-scheduler-during-Covid
Approach and solution steps-

	Structured market structure in the form of a single array containing market type in the given order - 

Example: T=3, k=3, m=2 -> n = T*m*k = 3*3*2 = 18 (total number of shops)

1	2	3
10	11	12
	
4	5	6
13	14	15
	
7	8	9
16	17	18

Initial state :

1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18


	Initial state has been created with, market type starting from 1 to n, in the subsequent slot.

1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18

Calculated G_0(initial state goodness value)

	Formed all possible child states by swapping all possible index pairs (if those indexes do not belong to the same market).

E.G. - say swapped index 3 & index 9 – 

1	2	9	4	5	6	7	8	3	10	11	12	13	14	15	16	17	18


And find goodness value for this child-state (G_i)

Similarly, if we have “m” child, we have to calculate goodness value and state for all of them and keep track of all children which have a greater goodness value than the parent node, and select one child out of them with greatest goodness value. To make it our new state in order to move further.
If not a single child if found with greater goodness value then parent we stop searching there, and consider the current node as the best market structure.

 
Approach & Algorithm -

Move in the direction of best improvement, Greedy best first search. 
Hill Climbing. 

Pseudo code - (Return state with largest goodness possible)


Initial_state = { 1,2,3…..n}
G_0 = Goodness( Initial_state);

while( child with better goodness value found )
{
new_state            = best_chid
New_goodness  = best_chid_goodness
} 

Return new_state
