import cs50

def main():
    n = cs50.get_float()
    if (n<0):
        print("O hai! How much change is owed?")
    d = n*100
    c = 0;
    while(d-25>=0):
        c = c + 1
        d = d-25
    while(d-10>=0):
        c = c + 1
        d = d-10
    while(d-5>=0):
        c = c + 1
        d = d-5
    while(d-1>=0):
        c = c + 1
        d = d-1
    print(c)
if __name__ == "__main__":
    main()