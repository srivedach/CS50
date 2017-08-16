import cs50
import sys

def main():
    if len(sys.argv) != 2:
        print("You should provide cmd line arguments!")
        exit(1)
    key = int(sys.argv[1])
    i = 0
    ciphertext = 0
    if(key <0):
        print("please enter a valid key")
    else:
        print("plaintext: ")
        name = cs50.get_string()
        print("ciphertext: ")
        for i in range (i,len(name),+1):
            if(name[i].isalpha()):
                if(name[i].isupper()):
                    ciphertext = ((ord(name[i]) - 65 + key) % 26) + 65
                    print(chr(ciphertext),end = "")
                elif(name[i].islower()):
                    ciphertext  = ((ord(name[i]) - 97 + key) % 26) + 97
                    print(chr(ciphertext),end = "")
            else:
                print(name[i])
if __name__ == "__main__":
    main()