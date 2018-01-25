# ShowMnist
显示MNIST图片

# 该程序依赖opencv
linux系统安装opencv: sudo apt-get install libopencv-dev

# 相关介绍与编译
mnist_util.cpp 获取MNIST数据，并将数据保存在向量中，
ShowMnist.cpp 显示图片
编译命令:  g++ `pkg-config --cflags opencv` -o ShowMnist ShowMnist.cpp mnist_util.cpp `pkg-config --libs opencv`
