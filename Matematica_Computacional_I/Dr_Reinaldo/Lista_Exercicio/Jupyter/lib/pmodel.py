import numpy as np
import math as mt
import statistics as st

def pmodel(noValues, p, slope):
    
    # Calculate length of time series
    noOrders = mt.ceil(mt.log2(noValues))
    noValuesGenerated = mt.pow(2, noOrders)
    
    #noValuesGenerated = 2**(noOrders)
    
    # y is the time series generated with the p-model.
    y = np.array([1])
        
    for i in range(0,noOrders):
        y = next_step_1d(y,p)
        
    if slope:
        fourierCoeff = fractal_spectrum_1d(noValues, slope/2)
        meanVal = st.mean(y)
        stdy = st.stdev(y)

        x = np.fft.ifft(y-meanVal)         #Calculate the Fourier coefficients of the original p-model time series

        phase = np.angle(x)                   #Calculate the phases, as these are kept intact, should not be changed by the Fourier filter.
        x = fourierCoeff * np.exp(1j*phase)   #Calculate the complex Fourier coefficients with the specified spectral slope, and the phases of the p-model.

        x = np.real(np.fft.fft(x))    #Generate the fractionally integrated time series
        x = x * stdy / st.stdev(x)
        x = x + meanVal
    else:
        x = y

    y = y[0:noValues + 1]
    x = x[0:noValues + 1]

    return(np.round (x,decimals=8))

def next_step_1d(y,p):
    tam = len(y)    
    y2 = np.zeros(tam*2)

    sign = np.random.uniform(0, 1, tam) - 0.5
    sign /= abs(sign)
    
    y2[::2] = y + sign * (1 - 2 * p) * y
    y2[1::2] = y - sign * (1 - 2 * p) * y
    
    return y2

def fractal_spectrum_1d(noValuesF, slope):

    ori_vector_size = noValuesF
    ori_half_size = ori_vector_size // 2
    
    a = np.zeros(ori_vector_size)
    
    ori_half_size = int(ori_half_size)
   
    for t2 in range(1, (ori_half_size + 1) + 1, 1):
        index = t2 - 1
        t4 = 2 + ori_vector_size - t2
    
        if t4 > ori_vector_size:
            t4 = t2
    
        if index == 0:
            coeff = 1
        else:
            coeff = index ** slope
        a[t2 - 1] = coeff
        a[t4 - 1] = coeff

    a[0] = 0
    return a
