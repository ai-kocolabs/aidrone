from tensorflow import keras
import numpy as np

model = keras.models.load_model("model.h5")

W1, b1 = model.layers[0].get_weights()
W2, b2 = model.layers[1].get_weights()
W3, b3 = model.layers[2].get_weights()

print(W1.shape, b1.shape)
print(W2.shape, b2.shape)
print(W3.shape, b3.shape)

x_test = np.array([
    -0.2296142578125, -0.1058349609375, 0.54541015625, 
    0.01397705078125, -0.0621337890625, 0.009613037109375
])

x = np.array([x_test])       # x should be array
h1 = x @ W1 + b1        # dense layer
h1 = np.maximum(0, h1)  # ReLU
h2 = h1 @ W2 + b2       # dense layer
h2 = np.maximum(0, h2)  # ReLU
y = h2 @ W3 + b3       # dense layer	

print(y)