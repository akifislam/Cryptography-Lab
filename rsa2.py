e = 79
d = 1019
n = 3337
M = 6882326879666683

print("Original message: ", M)

plaintext = str(M)
blocks = [int(plaintext[i : i + 3]) for i in range(0, len(plaintext), 3)]

ciphertext = ""
for item in blocks:
    ciphertext += str((item**e) % n)

print("Encrypted message: ", ciphertext)

ciphertext = str(ciphertext)
cipher_blocks = [int(ciphertext[i : i + 4]) for i in range(0, len(ciphertext), 4)]

decrypted = ""
for item in cipher_blocks:
    decrypted += str((item**d) % n)

print("Decrypted message: ", decrypted)
