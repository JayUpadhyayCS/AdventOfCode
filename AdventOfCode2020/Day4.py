import re
import itertools
class Checker:
    '''
    byr=False
    iyr=False
    eyr=False
    hgt=False
    hcl=False
    ecl=False
    pid=False
    cid=False
    counter=0
    '''
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
        elif(arr[0]=="byr" and len(arr[1])==4 and int(arr[1])<=2002 and int(arr[1])>=1920):
            self.byr=True
            print(arr[1])
        elif arr[0]=="iyr" and len(arr[1])==4 and int(arr[1])<=2020 and int(arr[1])>=2010:
            self.iyr=True
        elif arr[0]=="eyr"and len(arr[1])==4 and int(arr[1])<=2030 and int(arr[1])>=2020:
            self.eyr=True
        elif arr[0]=="hgt":
            if arr[1][-2:]=="cm" and int(arr[1][:-2])>=150 and int(arr[1][:-2])<=193:
                self.hgt=True
            elif arr[1][-2:]=="in" and int(arr[1][:-2])>=59 and int(arr[1][:-2])<=76:
                self.hgt=True
        elif arr[0]=="hcl" and arr[1][0]=="#":
            for x in arr[1][1:]:
                if (x >='a' and x<='f') or (x >='0' and x<='9'):
                    self.hcl=True
                else:
                    return #could cause edge case maybe cosnider rewriting
        elif arr[0]=="ecl" and (arr[1]=="amb" or arr[1]=="blu" or arr[1]=="brn" or arr[1]=="gry" or arr[1]=="grn" or arr[1]=="hzl"or arr[1]=="oth"):
            self.ecl=True 
        elif arr[0]=="pid" and len(arr[1])==9:
            for x in arr[1]:
                if(x <'0' and x>'9'):
                    return
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