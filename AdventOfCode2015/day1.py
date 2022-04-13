def main():
    """ Main program """
    # Code goes over here.
    f = open('AdventOfCode2015\day1.txt','r')
    #with open("day1.txt") as f:
    lines = f.readlines()
    counter=0
    for line in lines:
        for chara in line:
            if(chara == '('):
                counter+=1
            elif chara == ")":
                counter-=1
    print( counter)

if __name__ == "__main__":
    main()