import random

file1 = open("./example.txt","w")
file3 = open("./gRPC/src/Models/example.txt","w") 
file2 = open("./words.txt", "r")

PsudoRandomWords = []

for word in file2.read().split():
   PsudoRandomWords.append(f'{word} ')

index = 0
TAM_FILE = 125000 # bytes
for x in range(TAM_FILE):
   index = random.randint(0,len(PsudoRandomWords) - 1)
   file1.write(PsudoRandomWords[index])
   file3.write(PsudoRandomWords[index])

   if x % 20 == 0:
      file1.write('\n')

   if x % 20 == 0:
      file3.write('\n')