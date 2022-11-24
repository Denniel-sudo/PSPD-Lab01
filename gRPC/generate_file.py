import random

file1 = open("./src/Models/example.txt","w") 
file2 = open("./words.txt", "r")

PsudoRandomWords = []

for word in file2.read().split():
   PsudoRandomWords.append(f'{word} ')

index = 0
TAM_FILE = 10000 # bytes
for x in range(10000):
   index = random.randint(0,len(PsudoRandomWords) - 1)
   file1.write(PsudoRandomWords[index])

   if x % 20 == 0:
      file1.write('\n')