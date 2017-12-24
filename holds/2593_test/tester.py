import filecmp
import subprocess
import random

a = input("ref source: ")
b = input("test source: ")

testNum = 10000
for id in range(testNum) :
	with open("input.txt", "w") as f :
		N = random.randint(1, 100000)
		f.write(str(N) + '\n')
		for _ in range(4) :
			f.write(str(random.randint(1, N)) + '\n')
	
	subprocess.call(['./'+ a + ' <input.txt >out1.txt'], shell = True)
	subprocess.call(['./'+ b + ' <input.txt >out2.txt'], shell = True)

	if not filecmp.cmp('out1.txt', 'out2.txt') :
		print("FAIL :(")
		sys.exit()
	print(str(id) + " OKEY!")
	
