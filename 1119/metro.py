from collections import defaultdict

class Tree():
	def __init__(self):
		self.edges = defaultdict(set)
		self.weights = {}
	
	def addEdge(self, fromNode, toNode, weight):
		self.edges[fromNode].add(toNode)
		self.edges[toNode].add(fromNode)
		self.weights[(fromNode, toNode)] = weight

	def removeEdge(self, fromNode, toNode):
		self.edges[fromNode].remove(toNode)

	def __repr__(self):
		return "Tree({})".format(self.edges)

class Node:
	def __init__(self, x, y):
		self.x = x
		self.y = y

	def __repr__(self):
		return "Node({},{})".format(self.x, self.y)

	def __eq__(self, other):
		return self.x == other.x and self.y == other.y

	def __hash__(self):
		return hash(self.x) + hash(self.y)

def dijsktra(graph, initial, end):
    # shortest paths is a dict of nodes
    # whose value is a tuple of (previous node, weight)
    shortest_paths = {initial: (None, 0)}
    current_node = initial
    visited = set()
    while current_node != end:
        visited.add(current_node)
        destinations = graph.edges[current_node]
        weight_to_current_node = shortest_paths[current_node][1]

        for next_node in destinations:
            weight = graph.weights[(current_node, next_node)] + weight_to_current_node
            if next_node not in shortest_paths:
                shortest_paths[next_node] = (current_node, weight)
            else:
                current_shortest_weight = shortest_paths[next_node][1]
                if current_shortest_weight > weight:
                    shortest_paths[next_node] = (current_node, weight)
        
        next_destinations = {node: shortest_paths[node] for node in shortest_paths if node not in visited}
        if not next_destinations:
            return "Route Not Possible"
        # next node is the destination with the lowest weight
        current_node = min(next_destinations, key=lambda k: next_destinations[k][1])
    return shortest_paths[end][1]

tree = Tree()

n, m = [int(x) for x in input().split(' ')]

k = int(input())

tuplesList = []


startingNode = Node(0, 0)

nodesSet = set([startingNode])

while nodesSet:
	currentNode = nodesSet.pop()

	if currentNode.x + 1 <= n:
		topNode = Node(currentNode.x + 1, currentNode.y)
		tree.addEdge(currentNode, topNode, 100)
		nodesSet.add(topNode)

	if currentNode.y + 1 <= m:
		rightNode = Node(currentNode.x, currentNode.y + 1)
		tree.addEdge(currentNode, rightNode, 100)
		nodesSet.add(rightNode)

for i in range(k):
	x, y = [int(x) for x in input().split(' ')]
	tree.addEdge(Node(x - 1, y -1), Node(x, y), 141.4214)
	tree.removeEdge(Node(x - 1, y -1), Node(x - 1, y))
	tree.removeEdge(Node(x - 1, y -1), Node(x, y - 1))


print(round(dijsktra(tree, Node(n, m), Node(0,0))))