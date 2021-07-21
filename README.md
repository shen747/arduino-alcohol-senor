# Arduino (AtMega-328) based Gas-Sensor
This is an Arduino Uno based implementation of an Gas Sensor.

The first build of this project started on the perf board like any other hobby project but I ran out of space on my project enclosure
due to the amount of wires required to connect the 16x2 LCD screen.

Therefor I decided to create a Custom board for this using EasyEDA to clean up the wiry mess.The image below shows a before and after result of the project:

![Alt text](assets/first-prototype-vs-pcb-build.jpg?raw=true "Title")

also as seen in the image the project used to be powered by a 9v Battery but after the PCB I also decided to use a 12v DC mains power supply with a 12v to 5v DC to DC step down circuit made using the 7805 IC. The schematic for this small circut is shown below taken from [Circuits DIY](https://circuits-diy.com/12v-to-5v-converter-using-lm7805-ic-power-supply/)

![Alt text](assets/12V-to-5V-Converter-circuit.png?raw=true "Title")

And after all that this is how the final build of the project looks like :

![Alt text](assets/final_prject_box.jpg?raw=true "Title")

The PCB design file is available in the assets folder and you can open it using the EasyEDA editor available to be downloaded for free [here](https://easyeda.com/page/download)
