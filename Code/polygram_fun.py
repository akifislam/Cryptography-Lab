dict = {'BAN':'PQR','GLA':'ABC','DES':'XYZ'}
plaintext = "BANGLADES"
ciphertext = plaintext
for key,value in dict.items():
    ciphertext = ciphertext.replace(key,value)
print("Cipher : ",ciphertext)


 