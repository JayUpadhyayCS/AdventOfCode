
def main():
    with open('day2.txt') as f:
        lines=[]
        lines=f.read().splitlines()
        part1(lines)
        part2(lines)

def part1(lines):
    counter=0
        #print (len(lines))
    for line in lines:
            #6-7 z: dqzzzjbzz
        lowBound=(int(line.split('-')[0]))
        highBound=(int(line.split('-')[1].split(' ')[0]))
        key=(line.split(' ')[1][0])
        inputs=(line.split(" ")[2])
        if(inputs.count(key)<=highBound and inputs.count(key)>=lowBound):
            counter+=1
    print(counter)
        #print(highBound)
        #print(lowBound)
        #print(key)

def part2(lines):
    counter=0
    for line in lines:
            #6-7 z: dqzzzjbzz
        lowBound=(int(line.split('-')[0]))
        highBound=(int(line.split('-')[1].split(' ')[0]))
        key=(line.split(' ')[1][0])
        inputs=(line.split(" ")[2])
        if((inputs[(lowBound-1)]==key) ^ (inputs[(highBound-1)]==key)):
            counter+=1
    print(counter)

if __name__ == "__main__":
    main()