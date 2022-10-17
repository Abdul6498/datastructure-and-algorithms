import glob
import os
path = "/home/abdul/datastructure-and-algorithms/Solutions/"
files = sorted(glob.glob(path+"*.py"))

for file in files:
    name = file.split("/")[-1].split(" ")[1:]
    #print(name)
    final_name = ""
    for n in name:
        final_name += n
    print(path+final_name)
    os.rename(file, path+final_name)