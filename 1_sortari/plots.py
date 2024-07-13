import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

####################################
n = [
    1.0e3,
    1.0e4, 2e4, 3e4, 4e4, 5e4
]

o_nlogn = [
    0.000423,
    0.005270, 0.009708, 0.015994, 0.017076, 0.011250
]

o_n2 = [
    0.005784,
    0.279038, 1.051321, 2.313756, 4.125225, 6.154047
]


n_mare = [
    1.0e3, 1.0e4, 1.0e5, 1.0e6, 1.0e7, 1.0e8
]

o_nlogn_mare = [
    0.000425,
    0.005299,
    0.045269,
    0.278074,
    3.148144,
    35.950620
]



pts = o_nlogn + o_n2
complexities = [r'$O(n*log(n))$', r'$O(n^2)$']

# pts = o_nlogn_mare
# n = n_mare
# complexities = [r'$O(n*log(n))$']

####################################

nr = len(n)
# print([x for complexity in complexities for x in nr * [complexity]])

df = pd.DataFrame(
    {
        "n": len(pts) // len(n) * n,
        "t": pts,
        "complexity": [x for complexity in complexities for x in nr * [complexity]],
    }
)

sns.set_theme(style='darkgrid')

plot = sns.relplot(data=df, x='n', y='t', hue='complexity', style='complexity', kind='line', dashes=False, markers=True)
plot.set_ylabels('t (s)')
#plt.xscale('log')
#plt.yscale('log')
#plt.loglog(basex=10, basey=2)
if n[-1] == 5e4:
    plt.savefig('plot1.pdf')
else:
    plt.xscale('log')
    plt.yscale('log')
    plt.savefig('plot2.pdf')


# https://seaborn.pydata.org/tutorial/relational.html
# https://matplotlib.org/stable/tutorials/text/mathtext.html
