def main():
    with open('day3.txt') as f:
        lines=f.read().splitlines()
        findTrees(lines,1,1)
        findTrees(lines,3,1)
        findTrees(lines,5,1)
        findTrees(lines,7,1)
        findTrees(lines,1,2)

def findTrees(lines, right, down):
    index=-right
    counter=0
    for y in range(0,len(lines),down):
        index+=right
        if(index>30):
            index-=31
        if (lines[y][index]=='#'):
            counter+=1
    print(counter)
if __name__ == "__main__":
    main()