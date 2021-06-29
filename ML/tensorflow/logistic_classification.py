#logistic classification 실습
import os
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '3'
import numpy as np
import tensorflow as tf

x_train = [[1, 2], [2, 3], [3, 1], [4, 3], [5, 3], [6, 2]]
y_train = [[0], [0], [0], [1], [1], [1]]

# 그에 따라 Loss 값 또한 커지며 발산하게 된다.
optimizer = tf.keras.optimizers.SGD(learning_rate=0.01)

model = tf.keras.models.Sequential()

model.add(tf.keras.layers.Dense(units=1, input_dim=2))
#sigmoid 가설을 사용하므로 sigmoid로 설정.
model.add(tf.keras.layers.Activation('sigmoid'))
#loss function은 binary_crossentropy, metrics에 추가되는 것 또한 표현이 됨
model.compile(loss='binary_crossentropy', optimizer=optimizer, metrics=['accuracy'])

history = model.fit(x_train, y_train, epochs=5000)

print(model.predict([[1, 2], [2, 3], [3, 1], [4, 3], [5, 3], [6, 2]]))