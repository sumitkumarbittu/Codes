"""

import pandas as pd
import matplotlib.pyplot as plt
#%matplotlib inline

data_filename = 'Advertising.csv'
df = pd.read_csv(data_filename)

plt.scatter(df['TV'],df['Sales'])
plt.xlabel('TV budget')
plt.ylabel('Sales')
plt.title('TV budget vs Sales')

"""


