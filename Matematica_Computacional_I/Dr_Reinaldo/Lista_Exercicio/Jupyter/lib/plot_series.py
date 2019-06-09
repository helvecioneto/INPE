import matplotlib.pyplot as plt

def plot_series(series, title, name):
    
    plt.figure(figsize=(20,5))
    plt.plot(series, linewidth=1)
    plt.title(title, fontsize=16)
    plt.xlabel('Time',fontsize=16)
    plt.ylabel('Amplitude',fontsize=16)
    plt.savefig('./images/'+name+'.png')