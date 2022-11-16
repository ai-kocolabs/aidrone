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