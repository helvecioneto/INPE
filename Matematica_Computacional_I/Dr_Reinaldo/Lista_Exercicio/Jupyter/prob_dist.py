import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np

def uniforme():

	uniform10000 = np.random.uniform(0,1,10000)
	uniform1000 = np.random.uniform(0,1,1000)
	uniform100 = np.random.uniform(0,1,100)
	uniform10 = np.random.uniform(0,1,10)

	plt.figure(figsize=(12, 4))

	sns.distplot(uniform10000,hist=False, color='blue',label='N=10000')
	sns.distplot(uniform1000,hist=False, color='red',label='N=1000')
	sns.distplot(uniform100,hist=False, color='green',label='N=100')
	sns.distplot(uniform10, hist=False, color="black", label='N=100')

	plt.xlabel('Variáveis Aleatórias')
	plt.ylabel('Probabilidade')
	plt.title('(i)Uniforme')

def binomial():
	binomial1 = np.random.binomial(100,.15, 1000)
	binomial2 = np.random.binomial(100,.35, 1000)
	binomial3 = np.random.binomial(100,.65, 1000)
	binomial4 = np.random.binomial(100,.85, 1000)

	plt.figure(figsize=(12, 4))

	sns.distplot(binomial1,hist=False, color='blue',label='n=100 p=0.15')
	sns.distplot(binomial2,hist=False, color='red',label='n=100 p=0.35')
	sns.distplot(binomial3,hist=False, color='green',label='n=100 p=0.65')
	sns.distplot(binomial4,hist=False, color='black',label='n=100 p=0.85')

	plt.xlabel('Variáveis Aleatorias')
	plt.ylabel('Probabilidade')
	plt.title('(ii)Binomial')

def beta():
	beta1 = np.random.beta(2, 8, 1000)  #Alpha = 2, Beta = 8
	beta2 = np.random.beta(4, 8, 1000)
	beta3 = np.random.beta(6, 8, 1000)

	plt.figure(figsize=(12, 4))

	sns.distplot(beta1,hist=False, color='blue',label='alpha=2')
	sns.distplot(beta2,hist=False, color='red',label='alpha=4')
	sns.distplot(beta3,hist=False, color='green',label='alpha=6')

	plt.xlabel('Beta = 8')
	plt.ylabel('Probabilidade')
	plt.title('(iii)Beta')

def laplace():
	laplace1 = np.random.laplace(0, .1, 1000)	#Loc , Scale, Size
	laplace2 = np.random.laplace(0, .2, 1000)
	laplace3 = np.random.laplace(0, .4, 1000)
	laplace4 = np.random.laplace(0, .6, 1000)

	plt.figure(figsize=(12, 4))

	sns.distplot(laplace1,hist=False, color='blue',label='loc=0 b=1')
	sns.distplot(laplace2,hist=False, color='red',label='loc=0 b=2')
	sns.distplot(laplace3,hist=False, color='green',label='loc=0 b=4')
	sns.distplot(laplace4,hist=False, color='black',label='loc=5 b=4')

	plt.xlabel('Variáveis Aleatorias')
	plt.ylabel('Probabilidade')
	plt.title('(iv)LaPlace')

def gamma():
	gamma1 = np.random.gamma(1, 2, 1000)	#Shape, Scale, Size
	gamma2 = np.random.gamma(2, 2, 1000)
	gamma3 = np.random.gamma(3, 2, 1000)
	gamma4 = np.random.gamma(5, 1, 1000)
	gamma5 = np.random.gamma(9, 0.5, 1000)

	plt.figure(figsize=(12, 4))

	sns.distplot(gamma1,hist=False, color='blue',label='α=1 θ=2')
	sns.distplot(gamma2,hist=False, color='red',label='α=2 θ=2')
	sns.distplot(gamma3,hist=False, color='green',label='α=3 θ=2')
	sns.distplot(gamma4,hist=False, color='black',label='α=5 θ=1')
	sns.distplot(gamma5,hist=False, color='yellow',label='α=9 θ=0.5')

	plt.xlabel('Variáveis Aleatorias')
	plt.ylabel('Probabilidade')
	plt.title('(v)Gamma')

def exponencial():
	exponential1 = np.random.exponential(0.5, 1000)	#Scale
	exponential2 = np.random.exponential(1, 1000)
	exponential3 = np.random.exponential(2, 1000)
	exponential4 = np.random.exponential(4, 1000)


	plt.figure(figsize=(12, 4))

	sns.distplot(exponential1,hist=False, color='blue',label='λ=0.5')
	sns.distplot(exponential2,hist=False, color='red',label='λ=1')
	sns.distplot(exponential3,hist=False, color='green',label='λ=2')
	sns.distplot(exponential4,hist=False, color='black',label='λ=4')

	plt.xlabel('Variáveis Aleatorias')
	plt.ylabel('Probabilidade')
	plt.title('(vi)Exponencial')

def quiquadrado():
	quiquadrado1 = np.random.chisquare(1, 1000)		#k graus
	quiquadrado2 = np.random.chisquare(2, 1000)
	quiquadrado3 = np.random.chisquare(3, 1000)
	quiquadrado4 = np.random.chisquare(4, 1000)
	quiquadrado5 = np.random.chisquare(9, 1000)

	plt.figure(figsize=(12, 4))

	sns.distplot(quiquadrado1,hist=False, color='blue',label='k=1')
	sns.distplot(quiquadrado2,hist=False, color='red',label='k=2')
	sns.distplot(quiquadrado3,hist=False, color='green',label='k=3')
	sns.distplot(quiquadrado4,hist=False, color='black',label='k=4')
	sns.distplot(quiquadrado5,hist=False, color='black',label='k=9')

	plt.xlabel('Variáveis Aleatorias')
	plt.ylabel('Probabilidade')
	plt.title('(vi)Qui-Quadrado')

def cauchy():
	cauchy1 = np.random.standard_cauchy(10)
	cauchy2 = np.random.standard_cauchy(100)
	cauchy3 = np.random.standard_cauchy(1000)
	cauchy4 = np.random.standard_cauchy(10000)

	plt.figure(figsize=(12, 4))

	sns.distplot(cauchy1,hist=False, color='blue',label='n=10')
	sns.distplot(cauchy2,hist=False, color='red',label='n=100')
	sns.distplot(cauchy3,hist=False, color='blue',label='n=1000')
	sns.distplot(cauchy4,hist=False, color='red',label='n=10000')
	#sns.distplot(quiquadrado3,hist=False, color='green',label='k=3')
	#sns.distplot(quiquadrado4,hist=False, color='black',label='k=4')
	#sns.distplot(quiquadrado5,hist=False, color='black',label='k=9')

	plt.xlabel('Variáveis Aleatorias')
	plt.ylabel('Probabilidade')
	plt.title('(vii)Cauchy')
