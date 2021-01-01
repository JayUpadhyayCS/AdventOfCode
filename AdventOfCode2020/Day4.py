import re
import itertools
class Checker:
    byr=False
    iyr=False
    eyr=False
    hgt=False
    hcl=False
    ecl=False
    pid=False
    cid=False
    counter=0
    def __init__(self):
        self.byr=False
        self.iyr=False
        self.eyr=False
        self.hgt=False
        self.hcl=False
        self.ecl=False
        self.pid=False
        self.cid=False
        self.counter=0
    def reset(self):
        if(self.byr==True and self.iyr==True and self.eyr==True and self.hgt==True and self.hcl==True and self.ecl==True and
        self.pid==True):
            self.counter+=1
        self.byr=False
        self.iyr=False
        self.eyr=False
        self.hgt=False
        self.hcl=False
        self.ecl=False
        self.pid=False
        self.cid=False
    def check(self):
        if(self.byr==True and self.iyr==True and self.eyr==True and self.hgt==True and self.hcl==True and self.ecl==True and
        self.pid==True):
            self.counter+=1
            self.byr=False
            self.iyr=False
            self.eyr=False
            self.hgt=False
            self.hcl=False
            self.ecl=False
            self.pid=False
            self.cid=False
        
    def checker(self,statement):
        arr=statement.split(":")
        if arr==['']:
            self.reset()
        elif(arr[0]=="byr"):
            self.byr=True
        elif arr[0]=="iyr":
            self.iyr=True
        elif arr[0]=="eyr":
            self.eyr=True
        elif arr[0]=="hgt":
            self.hgt=True
        elif arr[0]=="hcl":
            self.hcl=True
        elif arr[0]=="ecl":
            self.ecl=True 
        elif arr[0]=="pid":
            self.pid=True
        elif arr[0]=="cid":
            self.cid=True   
        self.check()

def main():
    Processor=Checker()
    with open('day4.txt') as f:
        #hcl:#6b5442 ecl:brn iyr:2019
        for x in f:#takes a string line
            x=x.strip()#gets rid of /n at end of line
            array=re.split(' ',x)#supposed to split the string by spaces
            for i in array:
                Processor.checker(i)
                #print(array[i])
            #for x in range(0,(len(array) -1), 2):
            #    checker(array[x], array[x+1])
    print(Processor.counter)
if __name__ == "__main__":
    main()