import tensorflow as tf
import numpy as np

xs = np.array([2])
yts = np.array([10])

model = tf.keras.Sequential([
	tf.keras.layers.InputLayer(input_shape=(1,)),
	tf.keras.layers.Dense(1)    
])

model.compile(optimizer='sgd', loss='mean_squared_error')

model.fit(xs, yts, epochs=5)

p = model.predict([2])

print('p:', p)