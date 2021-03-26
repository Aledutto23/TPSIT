import string
from random import *


caratteri = 'qwertyuiopasdfghjklzxcvbnm0123456789QWERTYUIOPASDFGHJKLZXCVBNM"£$%&/()='  #inseisco tutti i caratteri che possono esserci nelle password
password_semplice =  "".join(choice(caratteri) for x in range(8))  #operazione per generare una password casuale con 8 caratteri
password_complicata =  "".join(choice(caratteri) for x in range(20))  #operazione per generare una password casuale con 12 caratteri
 

password = int(input("vuoi la password corta o lunga?(1 o 2)"))

#stampo le 2 password
if password == 1:
    print (password_semplice)

if password == 2:    
    print (password_complicata)