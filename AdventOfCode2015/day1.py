def main():
    """ Main program """
    # Code goes over here.
    f = open('AdventOfCode2015\day1.txt','r')
    #with open("day1.txt") as f:
    lines = f.readlines()
    counter=0
    counter2=0
    for line in lines:

        for chara in line:
            counter2+=1
            if(chara == '('):
                counter+=1
            elif chara == ")":
                counter-=1
            if counter==-1:
                print(counter2)
                
    print( counter)

if __name__ == "__main__":
    main()