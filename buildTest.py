import os
import subprocess

bin = "C:\\Qt\\Tools\\mingw730_64\\bin"

def parseFiles(folder):
    includeFiles = []
    for (root, dirs, files) in os.walk(folder):
        for file in files:
            includeFiles.append((root + '/' + file).rstrip("\n"))
    return includeFiles


includeFiles = parseFiles("include")


srcFiles = parseFiles("source")

buildCmd = " -c -DBUILD_DLL " + " ".join(srcFiles)  # + " -I ./include"
environment = os.environ.copy()
environment["PATH"] = bin + ";" + environment["PATH"]

#subprocess.run([compiler, buildCmd])
for file in srcFiles:
    subprocess.run(bin + "\\g++.exe " + file + " -c -g -std=c++17 " + " -o buildTest/build/" + os.path.splitext(file)[0] + ".o" + " -I include", env=environment)
objFiles = parseFiles("buildTest/build")
subprocess.run(bin + "\\ar.exe rvs buildTest/libpdcore.a " + " ".join(objFiles), env=environment)
