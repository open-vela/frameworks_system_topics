# topic 概述
本目录主要包含了connectivity、location、media、miai、sensor、system类型的topic的定义, 以及每个topic包含了哪些数据类型。
Vela OS中，应用程序APP不直接访问设备驱动节点来控制和获取sensor 数据，而是通过uORB API对sensor topics进行订阅，即可获取sensor事件数据。每一个topics支持多实例(instance)，发布者频率为采样率(interval)，最大发布延迟为batch latency。每个topics都有一个唯一的ID，每个uORB topics都有一个唯一的类型，topics的类型决定了uORB主题的数据结构。

## topic分类
**通知类**topics的订阅者不关心是否存在发布者或是否已发布，而是直接获取当前状态。如电量信息Vela上由healthd广告并发布电量信息，之后取消广告；应用订阅时，直接获取当前设备节点中最新的数据作为当前状态。发布通知类主题消息，需要使用带persist后缀的API进行主题的发布，订阅者行为与通用主题一致。

**通用类**topics的订阅者不关心过往的状态，它获取的数据一定是此刻或未来发生的。例如加速度传感器，应用只关注下次传感器出发data ready中断上报的数据，而不是过去某个时刻的数据。

每个发布或订阅的topics都对应一个字符设备节点，订阅者和发布者通过内部环形缓冲区共享数据。在实现上，若caller以O_WRONLY模式打开设备节点的称为发布者，以O_RDONLY模式打开设备节点的称为订阅者，发布者对节点进行write操作为发布数据，订阅者对节点进行read操作为订阅数据，双方可使用poll对节点进行监控，以接收感兴趣的events。发布者和订阅者对设备节点的控制通过ioctl操作实现。

## 如何定义一个topic
topics声明示例：
```c
ORB_DECLARE(sensor_accel);
```

topics定义示例：
```c
ORB_DEFINE(sensor_accel, sensor_accel_s);
```

为给定topics生成指向uORB元数据的指针,该主题必须已在ORB_DECLARE()范围中声明:
```c
ORB_ID(sensor_accel)
```

## 如何监听一个topic
使用方式可通过 `uorb_lstener -h` 来查看。
```shell
#打开配置
CONFIG_UORB_LISTENER=y

#例如：
uorb_listener sensor_accel -r 50 -n 10  以50HZ订阅加速度10个事件
uorb_listener sensor_accel,sensor_gyro -r 50 -n 10  以50HZ订阅加速度和陀螺仪共10个事件
uorb_listener battery_state -t 20 监控20s电池信息数据，若20s内有发布，则订阅成功
```
## 代码位置

```shell

#系统topics
frameworks/system/topics
#物理sensor发布的topic
apps/system/uorb/sensor
