# CSE305
# Assignment 6 Problem 2b
# Thomas Waring III

def qsort(a):
	def list_gen(l,thk):
		n = len(l)
		for i in range(n):
			thk(l[i])
	
	#see if x < the pivot
	def thunk1(x):
		if x < a[0]:
			left.append(x)
	#see if x >= the pivot
	def thunk2(x):
		if x >= a[0]:
			right.append(x)
	
	left=[]
	right=[]
	if a == []:
		return[]

	#run list_gen for left and right, as done in qsort1.py
	list_gen(a[1:], thunk1)
	list_gen(a[1:], thunk2)
	return qsort(left) + [a[0]] + qsort(right)

ans=[5,4,6,3,7,9,2,8,1,0]
print(qsort(ans))
