# VideoStreamWifiCar
၁) Arduino + adafruit motor shield version 1 အတွက် arduino ထဲက sketch ကို  upload လုပ်ပါ

၂) Raspberry pi(with camera) တွင် ros kinetic install လုပ်ပီးရင် Arduino အတွက် rosserial install လုပ်ပါ။ ပီးရင် video_stream, ros_car_master package များကို workspace/src ထဲထည့်ပီး catkin_make လုပ်ပါ။
    ပီးရင် raspberry pi boot အတက်မှာ ros_car_master/launch/ထဲက auto_start_master.launch ကို auto start ဖြစ် အောင်လုပ်ပါ။ (see ROS MYANMAR YOUTUBE URL-)
၃) Android apk ကိုအသုံးပြုပီးကားမောင်းပါ။ (apk က တော့ play store ကဟာပါ) https://play.google.com/store/apps/details?id=com.github.rosjava.android_apps.teleop.indigo

၄) Ubuntu pc ကဆိုရင် pc မှာ ros_car_client pkg ထဲ့ပီး auto_start_client ကို launch လုပ်ပီးမောင်းပါ။

၅) SSD neural network များသုံးပြုပီး  image topic ကို စိတ်ကူးရှိသလို program လုပ်ပါ။


1) Upload sketch to Arduion(with adafruit motor shield v1)
2) compile video_stream,ros_car_master package ( Raspberrypi<with camera module> )
3) Control video stream car from Ubuntu pc ( Using ros_car_client )
4) Control video stream car from Android ( teleop Apk )


<p align="center">
  <img src="https://github.com/GreenGhostMan/VideoStreamWifiCar/blob/master/image.jpg" width="500"/>
</p>
