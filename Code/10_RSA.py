# Given Constants
e = 79 #Encryption Key
d = 1019 #Decryption Key
M = 6882326879666683 #Message
n = 3337

print("Original Message : ",M)

# Split Original Message into blocks of size 3 (688,232,687,....)
M_str = str(M)
msg_block = [int(M_str[i:i+3]) for i in range(0, len(M_str), 3)]

cipher_text = ""

#Encryption
for item in msg_block:
    cipher_text+=str(((item**e)%n))

print("Cipher Text : ",cipher_text)

# Decryption
cipher_str = str(cipher_text)
cipher_block = [int(cipher_str[i:i+4]) for i in range(0, len(cipher_str), 4)]

decrypted_text = ""

for item in cipher_block:
    decrypted_text+=str(((item**d)%n))

print("Decrypted Text : ",decrypted_text)
