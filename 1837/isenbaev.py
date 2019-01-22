
class Team(object):
	def __init__(self, first, second, third):
		self.first = first
		self.second = second
		self.third = third
		self.hasIsenbaev = first == "Isenbaev" or second == "Isenbaev" or third == "Isenbaev"
	
	def __repr__(self):
		return "Team(" + self.first + ", " + self.second + ", " + self.third + ")"

class Node:
	def __init__(self, personName, connectedNodes=[]):
		self.personName = personName
		self.connectedNodes = connectedNodes
	def __repr__(self):
		return "Node(" + self.personName + ", " + str(self.connectedNodes) + ")"

class Tree:
	def __init__(self, topNode):
		self.topNode = topNode

	def addNode(self, connectionPersonName, node):
		searchingNodes = [self.topNode]
		nextNodes = []
		while searchingNodes:
			currentNode = searchingNodes.pop()
			if currentNode.personName == connectionPersonName:
				currentConnectedNodes = list(currentNode.connectedNodes)
				currentConnectedNodes.append(node)
				currentNode.connectedNodes = currentConnectedNodes
				return
			nextNodes.extend(currentNode.connectedNodes)
			if not searchingNodes:
				searchingNodes.extend(nextNodes)
				nextNodes = []

	def getDepthMapping(self):
		searchingNodes = []
		searchingNodes.append(self.topNode)
		nextNodes = []
		depth = 0
		peopleDict = dict()
		while searchingNodes:
			currentNode = searchingNodes.pop()
			peopleDict[currentNode.personName] = depth
			nextNodes.extend(currentNode.connectedNodes)
			if not searchingNodes:
				searchingNodes.extend(nextNodes)
				nextNodes = []
				depth = depth + 1
		return peopleDict

teamsCount = int(input())

teamsList = []
allPeople = set()

for i in range(teamsCount):
	first, second, third = input().split(' ')
	teamsList.append(Team(first, second, third))
	allPeople.update([first, second, third])

teammatesMap = {}

for team in teamsList:
	if not team.first in teammatesMap:
		teammatesMap[team.first] = set()
	if not team.second in teammatesMap:
		teammatesMap[team.second] = set()
	if not team.third in teammatesMap:
		teammatesMap[team.third] = set()
	
	teammatesMap[team.first].update([team.second, team.third])
	teammatesMap[team.second].update([team.first, team.third])
	teammatesMap[team.third].update([team.first, team.second])

isenbaevNode = Node("Isenbaev")
tree = Tree(isenbaevNode)

insertedInTree = set(["Isenbaev"])
iterationSet = set(["Isenbaev"])
nextIterationSet = set()

while iterationSet:
	person = iterationSet.pop()
	personTeammates = teammatesMap.get(person, [])
	for teamMate in personTeammates:
		if not teamMate in insertedInTree:
			tree.addNode(person, Node(teamMate))
			insertedInTree.add(teamMate)
			nextIterationSet.add(teamMate)
	if not iterationSet:
		iterationSet = set(nextIterationSet)
		nextIterationSet.clear()

allPeople = sorted(allPeople)
depthMap = tree.getDepthMapping()

for person in allPeople:
	if person in depthMap:
		print(person, depthMap[person])
	else:
		print(person, "undefined")
