# 1.1 Gerando séries a partir powernoise.m e pmodel
from oct2py import octave

def create_data():
	octave.addpath('./matlab/')
	octave.eval("whiteNorm = powernoise(0,4096,'normalize')")
	octave.eval("whiteRand = powernoise(0,4096,'randpower')")
	octave.eval("pinkNorm = powernoise(1,4096,'normalize')")
	octave.eval("pinkRand = powernoise(1,4096,'randpower')")
	octave.eval("redNorm = powernoise(2,4096,'normalize')")
	octave.eval("redRand = powernoise(2,4096,'randpower')")

	octave.eval("s8 = pmodel(4096,0.52,1.66)")
	octave.eval("s9 = pmodel(4096,0.62,0.45)")
	octave.eval("s10 = pmodel(4096,0.72,0.75)")

	# Salvando dados
	octave.eval("dlmwrite ('./data/s1_white_noise.csv',whiteNorm)")
	octave.eval("dlmwrite ('./data/s2_pink_noise.csv',pinkNorm)")
	octave.eval("dlmwrite ('./data/s3_red_noise.csv',redNorm)")

	octave.eval("dlmwrite ('./data/s8.csv',s8)")
	octave.eval("dlmwrite ('./data/s9.csv',s9)")
	octave.eval("dlmwrite ('./data/s10.csv',s10)")
	

	#octave.eval("dlmwrite ('./data/whiteRand.csv',whiteRand)")
	#octave.eval("dlmwrite ('./data/pinkRand.csv',pinkRand)")
	#octave.eval("dlmwrite ('./data/redRand.csv',redRand)")