
def main():
    print("Hello World!") 
    array=[]
    inputs=open("E:\AdventOfCode\AdventOfCode2020\day1.txt", "r")
    for input in inputs:
        array.append(int(input.strip('\n')))
    for num in array:
        for num2 in array:
            if num+num2==2020:
                print(num*num2)


if __name__ == "__main__":
    main()