

import os
file_name = './Models/example.txt'

def divide_file():
  FILE_SIZE = os.stat(file_name).st_size

  num_workers = 2
  file_number = 1
  CHUNK_SIZE = FILE_SIZE // num_workers

  with open('./Models/example.txt', 'r') as f:
    chunk = f.read(CHUNK_SIZE)
    while chunk:
      with open(f'./divided_files/divided_file_{str(file_number)}.txt', 'w') as chunk_file:
        chunk_file.write(chunk)
        file_number += 1
        chunk = f.read(CHUNK_SIZE)

def read_file(worker):
  with open(f'./divided_files/divided_file_{str(worker)}.txt', 'r') as file:
    text = str(file.read())
  
  return text
