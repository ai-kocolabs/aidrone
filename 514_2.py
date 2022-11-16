import numpy as np
import time
import matplotlib.pyplot as plt

NUM_SAMPLES = 1000

np.random.seed(int(time.time()))

xs = np.random.uniform(-2, 0.5, NUM_SAMPLES)
np.random.shuffle(xs)
print(xs[:5])

ys = 2*xs**2 + 3*xs + 5
print(ys[:5])

plt.plot(xs, ys, 'b.')
plt.show()

ys += 0.1*np.random.randn(NUM_SAMPLES)

plt.plot(xs, ys, 'g.')
plt.show()