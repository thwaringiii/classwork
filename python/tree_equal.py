# CSE305
# Assignment 6 Problem 3
# Thomas Waring III


class Tree:
	def __init__(self, n):
		self.value = n
		self.left  = []
		self.right = []

	def insert(self, n):
		if self.value == n: return
		if self.value < n:
			if not self.right: self.right = Tree(n)
			else: self.right.insert(n)
		elif not self.left: self.left = Tree(n)
		else: self.left.insert(n)

	def __next__(self):
		for x in self: yield x

	def __iter__(self):
		for x in self.left: yield x
		yield self.value
		for x in self.right: yield x

def treeEqual(tr1, tr2): 
	#This is where we made our changes
	#How boring is tr_iter1 and tr_iter2? So uncreative.
	tr_iter1 = iter(tr1)
	tr_iter2 = iter(tr2)
	while True: 
		try:
			#Compare the values of the 2 trees
			#before proceeding.
			x = next(tr_iter1)
			y = next(tr_iter2)
			if x != y: return False
		except StopIteration: break
	return True
	

tr1 = Tree(100)
tr1.insert(50)
tr1.insert(150)
tr1.insert(175)
tr1.insert(25)
tr1.insert(75)

for x in tr1: print(x)

tr2 = Tree(50)
tr2.insert(25)
tr2.insert(75)
tr2.insert(150)
tr2.insert(100)
tr2.insert(175)

for x in tr2: print(x)

print(treeEqual(tr1, tr2))
