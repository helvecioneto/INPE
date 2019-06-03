import numpy as np
import math as mt

def pmodel(noValues=256, p=0.375, slope=None):

    noOrders = mt.ceil(mt.log2(noValues))
    noValuesGenerated = mt.pow(2, noOrders)

    y = np.array([1])
    for n in range(noOrders):
        y = next_step_1d(y, p)

    if slope:
        fourierCoeff = fractal_spectrum_1d(noValues, slope / 2)
        meanVal = np.mean(y)
        stdy = np.std(y)
        x = np.fft.ifft(y - meanVal)
        phase = np.angle(x)
        x = fourierCoeff * np.exp(1j * phase)
        x = np.real(np.fft.fft(x))
        x = x * stdy / np.std(x)
        x = x + meanVal
    else:
        x = y

    y = y[0:noValues + 1]
    x = x[0:noValues + 1]

    # return x
    return np.round(x, decimals=8)

def next_step_1d(y, p):
    len_ = len(y)
    y2 = np.zeros(len_ * 2)

    sign = np.random.uniform(0, 1, len_) - 0.5
    sign /= abs(sign)
    y2[::2] = y + sign * (1 - 2 * p) * y
    y2[1::2] = y - sign * (1 - 2 * p) * y

    return y2


def fractal_spectrum_1d(noValues, slope):
    ori_vector_size = noValues
    ori_half_size = ori_vector_size // 2

    a = np.zeros(ori_vector_size)

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