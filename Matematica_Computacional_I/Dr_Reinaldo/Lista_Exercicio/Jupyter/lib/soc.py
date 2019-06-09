import numpy as np
import pylab as plt

def SOC(data, n_bins=10):
    n = len(data)
    mean = np.mean(data)
    var = np.var(data)
    #print("mean: ", mean, " var: ", var)
    """ Computa a Taxa Local de Flutuação para cada valor da ST """
    Gamma = []
    for i in range(0,n):
        Gamma.append((data[i] - mean)/var)
    
    """ Computa P[Psi_i] """
    # Retorna o número de elementos em cada bin, bem como os delimitares dos bins
    counts, bins = np.histogram(Gamma, n_bins)
    Prob_Gamma = []
    for i in range(0, n_bins):
        Prob_Gamma.append(counts[i]/n)
    
    return Prob_Gamma, counts

nomeArquivo = 'sol3ghz.dat'
data = np.genfromtxt(nomeArquivo, dtype = 'float32',filling_values = 0)

Prob_Gamma, counts = SOC(data)
plt.plot(np.log10(Prob_Gamma), np.log10(counts))

plt.title('SOC', fontsize = 16)
plt.plt.xlabel('log(ni)')
plt.plt.ylabel('log(Yi)')
plt.plt.grid()
