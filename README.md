# **ASTRUM**
<img width="3296" height="2547" alt="Astrum (2)" src="https://github.com/user-attachments/assets/8d294b1b-0e8b-4d0e-8b1c-0917c34b3477" />  
Astrum is a full robot designed for Science Olympiad's Robot Tour Event (2025-2026). It is designed to follow a predetermined path to navigate a maze and manipulate a water bottle to specific points on the floor. It is equipped with dual GA25 motors, a controller board (Aero), wheel encoders and an IMU to keep track of orientation. These features allow Astrum to quickly navigate the predetermined path efficiently and accurately with a PID loop controlling robot turning and motor speed.  
<br><br>
Astrum was created for the purpose of "placing" at the Mid-Hudson Valley Regionals competition, and to secure Nanuet a medal. Additionally, it serves as an educational tool for other students interested in robotics and control systems. It is able to be programmed in C, as well as Arduino, making it very effective for learning embedded software. This is also practice for myself, testing my design skills with both the hardware, and efficiently programming software to run on said board.  
  
## PCB
<img width="432" height="646" alt="image" src="https://github.com/user-attachments/assets/84351c30-84c8-42b1-9c75-41a3002e1b0a" />  

## Wiring Diagram 
<img width="767" height="732" alt="wirediagram drawio" src="https://github.com/user-attachments/assets/9d2ca931-85dc-44da-ab10-a6e999b6706e" />
  
## BOM
Here's the BOM:  

 |Item #|Name                                       |Link                                     |Amount               |Cost   |
|------|-------------------------------------------|-----------------------------------------|---------------------|-------|
|1     |PCB + Assembly                             |jlcpcb.com                               |1 order (2 boards)   |$104.59|
|2     |25GA-370 Brushed Motors                    |https://www.amazon.com/dp/B07JFF3TH9?th=1|2                    |$25.94 |
|3     |Alinan AS5600 Encoder Boards               |as5600 link                              |1 pack (6 Encoders)  |$14.99 |
|4     |STEMMA QT to Male Header Cable             |https://www.adafruit.com/product/4209    |2                    |$1.90  |
|5     |2800 mAh AA NIMH Batteries                 |NIMH batteries link                      |1 pack (12 Batteries)|$19.99 |
|6     |4 x AA Battery Holder                      |https://www.adafruit.com/product/830     |2                    |$5.90  |
|7     |M3 16mm SHCS                               |M3 SHCS link                             |50                   |$6.49  |
|8     |BaneBots T6 Wheel, 2-3/8" x 0.6", Hub Mount|https://banebots.com/t61p-242bp/         |2                    |$6.60  |
|9     |MF128ZZ Bearings - 8mm x 12mm x 3.5mm      |MF128ZZ Bearings                         |1 pack (10 bearings) |$9.29  |
|10    |Polulu 1/2 Inch Metal Ball Caster Wheels   |https://www.pololu.com/product/953       |4                    |$11.80 |
|11    |Pin Headers                                |https://www.adafruit.com/product/3002    |3                    |$1.50  |
|12    |All Shipping Costs (Estimate)              |                                         |1                    |$45    |
|      |                                           |                                         |                     |Total: |
|      |                                           |                                         |                     |$253.99|
 
https://github.com/LtBrain/astrum/blob/main/Astrum%20BOM%20-%20Sheet1.csv

This covers the total sum of all the major parts.  

There is a more in depth BOM for the PCB assembly components itself: [BOM-astrum-JLCPCB Assembly Order.xls](https://github.com/user-attachments/files/23870804/BOM-astrum-JLCPCB.Assembly.Order.xls)

