# Overview of topics
This directory mainly contains the definitions of topics of types such as connectivity, location, media, miai, sensor, and system, as well as the data types contained in each topic.
In Vela OS, the application APP does not directly access the device driver node to control and obtain sensor data, but subscribes to sensor topics through the uORB API to obtain sensor event data. Each topic supports multiple instances (instance), the publisher frequency is the sampling rate (interval), and the maximum publishing delay is batch latency. Each topic has a unique ID, and each uORB topic has a unique type. The type of topics determines the data structure of the uORB topic.

## Classification of topics
Subscribers of **notification-type** topics do not care whether there is a publisher or whether it has been published, but directly obtain the current status. For example, the power information is advertised and published by healthd on Vela, and then the advertisement is cancelled; when the application subscribes, it directly obtains the latest data in the current device node as the current state. To publish notification topic messages, you need to use the API with the persist suffix to publish the topic, and the subscriber behavior is consistent with the general topic.

Subscribers of **general** topics do not care about the past status, and the data they obtain must be what happened at the moment or in the future. For example, for an accelerometer, the application only cares about the data reported when the sensor triggers the data ready interrupt next time, rather than the data at a certain moment in the past.

Each published or subscribed topic corresponds to a character device node. Subscribers and publishers share data through an internal ring buffer. In implementation, if the caller opens the device node in O_WRONLY mode, it is called a publisher, and if the caller opens the device node in O_RDONLY mode, it is called a subscriber. The publisher writes to the node to publish data, and the subscriber reads from the node to subscribe to data. Both parties can use poll to monitor the node to receive events of interest. The publisher and subscriber control the device node through ioctl operations.

## How to define a topic
examples of topics declaration:
```c
ORB_DECLARE(sensor_accel);
```

examples of topics definition:
```c
ORB_DEFINE(sensor_accel, sensor_accel_s);
```

generate a pointer to the uORB metadata for the given topics, which must have been declared in the ORB_DECLARE() range:
```c
ORB_ID(sensor_accel)
```
## How to listen to a topic
The usage can be viewed through `uorb_lstener -h`.
```shell
#Open configuration
CONFIG_UORB_LISTENER=y
#For example：
uorb_listener sensor_accel -r 50 -n 10  Subscribe to 10 acceleration events at 50HZ
uorb_listener sensor_accel,sensor_gyro -r 50 -n 10  Subscribe to 10 acceleration and gyroscope events at 50HZ
uorb_listener battery_state -t 20 Monitor 20s battery information data, if there is a release within 20s, the subscription is successful
```

## Code location
```shell

#System topics
frameworks/system/topics
#Topics published by physical sensors
apps/system/uorb/sensor