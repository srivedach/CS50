import cs50
import sys
def main():
    i = 0
    j = 0
    if len(sys.argv) != 2:
        print("<Key>")
    keyWord = sys.argv[1]
    ciphertext = 0
    for i in range (i,len(keyWord),+1):
        if(keyWord[i].islower()):
            keyWord[i] = ord(keyWord[i])-'a'+'A'
        if keyWord[i].isalpha() is not True:
            print("Enter alphabets only")
    print("plaintext: ", end="")
    name = cs50.get_string()
    print("ciphertext: ", end="")
    for i in range (i,len(name),+1):
        if(name[i]>='A' and name[i]<='Z'):
            ciphertext ='A'+ord(name[i]-'A'+keyWord[(j+1)%len(keyWord)]-'A') % 26
        if(name[i]>='a'and name[i]<='z'):
            ciphertext = 'a'+ord(name[i]-'a'+keyWord[(j+1)%len(keyWord)]-'A') %26
        print (ciphertext)
if __name__ == "__main__":
    main()  