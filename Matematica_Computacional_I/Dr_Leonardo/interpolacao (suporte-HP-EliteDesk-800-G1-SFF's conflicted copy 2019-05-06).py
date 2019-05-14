import scipy
import matplotlib.pyplot as plt
import numpy as np
import csv
# teste
dados = open('dados.csv', 'rb')
reader = csv.reader(dados)

hora = []
temp = []
i = 0

#print reader
for linha in reader:
	if i != 0:
		hora.append(int(linha[2]))
		temp.append(float(linha[3]))
	i=i+1

x = scipy.array(hora)
y = scipy.array(temp)

result = scipy.poly1d([0.0])

print len(y)

for i in range(0,len(x)):
	temp_numerador = scipy.poly1d([1.0])
	denominador = 1.0

	for j in range(0,len(x)):
		if i != j:
			temp_numerador *= scipy.poly1d([1.0,-x[j]])
			denominador *= x[i]-x[j]

	result += (temp_numerador/denominador) * y[i]

print ("Resutado: ")
print (result)

print ("")
n = float(input("Entre com a Hr: "))
print ("Na hora ", n, " Temperatura ", result(n))

x_val = np.arange(min(x),max(x)+1,0.1)
plt.xlabel('Hora')
plt.ylabel('Temperatura')
plt.grid(True)

for i in range(0,len(x)):
	plt.plot([x[i]],[y[i]],'ro')


plt.plot(x_val, result(x_val))


plt.axis([min(x)-1, max(x)+1, min(y)-1, max(y)+1])
plt.show()