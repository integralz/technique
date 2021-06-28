import os
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '3'
import numpy as np
import tensorflow as tf

x_train = [[73., 80., 75.], [93., 88., 93.], [89., 91., 90.],
           [96., 98., 100.], [73., 66., 70.]]
y_train = [152., 185., 180., 196., 142.]

#학습률 : 최소의 loss를 가지는 지점을 찾아가는 와중에 다음 탐색 지점의 위치 설정을 학습률이라고 불리는 스칼라를 곱해 찾아감
#높은 Learning Rate 값을 이용하는 경우 초기에 우리의 Loss 값에 따라 Backpropagation 시 weight 값이 크게 변하며 발산하게 되고,
# 그에 따라 Loss 값 또한 커지며 발산하게 된다.
sgd = tf.keras.optimizers.SGD(learning_rate=1e-5)

model = tf.keras.models.Sequential()
#레이어 노드 갯수 1개, 변수 3개
model.add(tf.keras.layers.Dense(units=1, input_dim=3))
#default 값은 linear이다.
model.add(tf.keras.layers.Activation('linear'))
#mse loss function 채택
model.compile(loss='mse', optimizer=sgd)

#1000번 시행
model.fit(x_train, y_train, epochs=1000)

print(model.predict(np.array([[72., 93., 90.]])))