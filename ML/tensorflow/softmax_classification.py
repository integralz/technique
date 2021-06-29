#Softmax classification 실습
import os
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '3'
import numpy as np
import tensorflow as tf

x_train =  [[1, 2, 1, 1], [2, 1, 3, 2], [3, 1, 3, 4], [4, 1, 5, 5], [1, 7, 5, 5], [1, 2, 5, 6], [1, 6, 6, 6], [1, 7, 7, 7]]
y_train = [[0, 0, 1], [0, 0, 1], [0, 0, 1], [0, 1, 0], [0, 1, 0], [0, 1, 0], [1, 0, 0], [1, 0, 0]]

#class는 3개이다.
classes = 3

# 그에 따라 Loss 값 또한 커지며 발산하게 된다.
optimizer = tf.keras.optimizers.SGD(learning_rate=0.1)

model = tf.keras.models.Sequential()

model.add(tf.keras.layers.Dense(units=classes, input_dim=4))
#sigmoid 가설을 사용하므로 softmax로 설정.
model.add(tf.keras.layers.Activation('softmax'))
#loss function은 categorical_crossentropy, metrics에 추가되는 것 또한 표현이 됨
model.compile(loss='categorical_crossentropy', optimizer=optimizer, metrics=['accuracy'])

history = model.fit(x_train, y_train, epochs=1000)

print(model.predict([[1, 11, 7, 9], [1, 3, 4, 3], [1, 1, 0, 1]]))