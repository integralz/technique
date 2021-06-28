import os
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '3'
import numpy as np
import tensorflow as tf

x_train = [1, 2, 3]
y_train = [1, 2, 3]

w = tf.Variable(tf.random.normal([1]), name='weight')
b = tf.Variable(tf.random.normal([1]), name='bias')

#학습률 : 최소의 loss를 가지는 지점을 찾아가는 와중에 다음 탐색 지점의 위치 설정을 학습률이라고 불리는 스칼라를 곱해 찾아감
sgd = tf.keras.optimizers.SGD(learning_rate=0.01)

model = tf.keras.models.Sequential()
#레이어 노드 갯수 1개, 변수 1개
model.add(tf.keras.layers.Dense(1, input_dim=1))
#mse loss function 채택
model.compile(loss='mean_squared_error', optimizer=sgd)
#1000번 시행
model.fit(x_train, y_train, epochs=1000)

print(model.predict(np.array([5])))