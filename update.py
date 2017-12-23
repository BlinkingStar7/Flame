import os

"""

"""

problems = []
for path, dirs, files in os.walk("holds") :
	for file in files :
		if file.endswith(".md") :
			problems.append(os.path.join(path, file))

articles = []
for path, dirs, files in os.walk("steps") :
	for file in files :
		if file.endswith(".md") :
			articles.append(os.path.join(path, file))

with open("links.md", "w") as f :
	for file in files :
		f.write("[{}]: 





