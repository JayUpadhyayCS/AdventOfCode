def main():
    with open("Day5.txt") as f:
        high=0
        a = [[False for x in range(8)] for x in range(128)]
        for x in f:
            x=x.strip()
            row=BinarySearch(x[:7], 0, 127)
            column=BinarySearch2(x[7:],0,7)
            a[row][column]=True
            if (high<(row*8+column)):
                high=row*8+column
        for x in range(len(a)-1):
            for y in range(1,(len(a[x])-1),1): #y is column
                if a[x][y]==False and a[x][y+1]==True and a[x][y-1]==True:
                    print(x*8+y)
        



def BinarySearch(x, low:int, high:int):
    if(len(x)==0):
        return low
    elif(x[0]=="F"):#lower half
        return BinarySearch(x[1:],low, ((low+high)//2))
    elif(x[0]=="B"):
        return BinarySearch(x[1:],((high+1 +low) // 2),high )
def BinarySearch2(x, low:int , high:int):
    if(len(x)==0):
        return low
    elif(x[0]=="L"):#lower half
        return BinarySearch2(x[1:],low, ((low+high)//2))
    elif(x[0]=="R"):
        return BinarySearch2(x[1:],((high+1 +low) // 2),high )


if __name__ == "__main__":
    main()