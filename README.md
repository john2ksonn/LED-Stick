# Workflow
* Convert any image using fileConverter.py
	./fileConverter.py > output.hex
* Copy output.hex onto a sd card
* Connect all the hardware
	* arduino (nano)
	* micro sd card adapter / reader
	* 144 led strip
	* 5V 4A PSU
* Insert sd card in adapter
* power the hardware
* wait until the program got executed ones
* start a long expo
* reset the arduino (to start the program from the beginning again)
* move the stick horizontally while holding it vertically

![Input image of a kitten from placekitten](https://github.com/john2ksonn/lightpaintingStick/raw/master/144.jpg)
![Input image of a kitten from placekitten](https://github.com/john2ksonn/lightpaintingStick/raw/master/kittenTestExpo.JPG)

In this example the image is flipped. This can be easily fixed in code or by moving the stick in the opposite direction.
