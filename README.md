# VideoStreamWifiCar
၁) Arduino + adafruit motor shield version 1 အတြက္ *ino ဖိုင္ကို arduino folder ထဲမွယူပီး upload လုပ္ပါ။

၂) Raspberry pi(with camera) တြင္ ros kinetic install လုပ္ပီးရင္ Arduino အတြက္ rosserial install လုပ္ပါ။ ပီးရင္ video_stream, ros_car_master package မ်ားကို workspace/src ထဲသြင္းပီး catkin_make လုပ္ပါ။
    ပီးရင္ boot အတက္မွာ ros_car_master/launch/ထဲမွ auto_start_master.launch တက္လာေအာင္လုပ္ပါ။ (see ROS MYANMAR YOUTUBE URL-)
၃) Android apk ကိုအသံုးျပဳပီး ကားေမာင္းပါ။ 

၄) Ubuntu pc မွ ေမာင္းခ်င္ရင္ pc မွာ ros_car_client pkg ထဲ့ပီး auto_start_client ကို launch လုပ္ပီးေမာင္းပါ။

၅) SSD neural network မ်ားအသံုးျပဳပီး image topic ကို စိတ္ကူးရွိသလိုစိတ္ၾကိဳက္အသံုးျပဳပါ။


1) Upload sketch to Arduion(with adafruit motor shield v1)
2) compile video_stream,ros_car_master package ( Raspberrypi<with camera module> )
3) Control video stream car from Ubuntu pc ( Using ros_car_client )
4) Control video stream car from Android ( teleop Apk )


<p align="center">
  <img src="https://github.com/GreenGhostMan/VideoStreamWifiCar/blob/master/image.png" width="350"/>
</p>
