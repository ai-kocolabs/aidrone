from mydata import I, T

x_train = I
y_train = T

x_train = x_train/32768

print(x_train.shape)
print(y_train.shape)

print(x_train.shape[0], x_train.shape[1], x_train.shape[2])

x_train = x_train.reshape(x_train.shape[0], x_train.shape[2])
y_train = y_train.reshape(y_train.shape[0], y_train.shape[2])

print(x_train.shape)
print(y_train.shape)

import random
import numpy as np

xy_train = [*zip(x_train, y_train)]
random.shuffle(xy_train)

x_train = np.array([xy[0].tolist() for xy in xy_train])
y_train = np.array([xy[1].tolist() for xy in xy_train])

NUM_SAMPLES = x_train.shape[0]
NUM_SPLIT = int(0.8*NUM_SAMPLES)

x_train, x_test = np.split(x_train, [NUM_SPLIT])
y_train, y_test = np.split(y_train, [NUM_SPLIT])
print(x_train.shape, x_test.shape)
print(y_train.shape, y_test.shape)