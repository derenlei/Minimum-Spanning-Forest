# Minimum-Spanning-Forest
Modified Kruskal’s algorithm with a disjoint set data structure

## Commands
#### BID node_number node_number cost
The bid command adds a new edge to the graph. It will never overwrite an existing edge. It
might add one or two new nodes (if either node_number hasn’t been encountered before, then it
is new). There is no response to this command; the program should keep reading input.

#### MANDATORY node_number node_number cost
The mandatory command adds a new edge that must be included in the solution, even if it forms a cycle. There is no 
response to this command; the program should keep reading input.

#### COST?
The cost command is a query about the minimum total cost to connect nodes. The entirety of 
previous solutions should be included in the cost. The output is a single integer number followed
by a newline (std::cout << cost << std::endl; // This could be legit)

#### COMPONENTS?
The components command wants to know how many connected components there are in the
current solution. The output is a single integer number followed by a newline.

#### CYCLE?
Know if a mandatory edge has forced your solution to have a cycle. Print YES or NO followed by a newline.

#### LIST?
List out the edges in the solution sorted in order of least cost to greatest cost,
independent of their mandatory status or which component they belong to. Edge form 
is in a pair sorted (smaller,bigger). Separate the from and to with a single comma (no
space), individual edges a single space (no comma), and end with a newline. A space MAY
exist before the newline. It might simplify your code, depending on your print routine.

#### END
The end command tells you to terminate your program. Calling exit(0) is acceptable.

#### SHORTEST_PATH? node_number node_number
The shortest path command asks you to return a path built from edges from your solution (not
from the entire graph) that represents the least-cost route between the two nodes subject to the
constraint that the route is present in the solution. Note that this will be asked on a graph where
cycles exist in the solution. The shortest path should be output in path order (if the query is
“SHORTEST_PATH? 15 99” and the path goes from 15 to 68 to 3 to 55 to 99, the output should
be “15 68 3 55 99”.
