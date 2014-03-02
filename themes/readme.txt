Please refer to the default theme to see an example.
SPL uses CSS for styling. Please learn how to write CSS before making a theme.

In order to create a theme that is detected by SPL just add a folder in the themes folder inside the main install folder of SPL, and add a file called "theme.style". All of the CSS goes into theme.style. If you need to load any pictures for backgrounds, etc, just put them in your theme's folder (or subfolders).

Each object (UI in the program) have a class and it's own object name.
Please note, commenting is css is /*comment*/ and will not do anything regarding styling.
Therefore you can classify an entire class (buttons for example) to be styled the same such as
QPushButton {
	color: rgb(220, 0, 0);
}

or,

Class {
	css;
}


However, if you want just one button with the object name of "button1" styled you can do
QPushButton#button1 {
	color: rgb(220, 0, 0);
}

or,

Class#objectname {
	css;
}

There are certain classes where the object contains other objects with various classes, if you want to theme them you can do various methods of styling inside of them.

QFrame#frame1 {
	/*Style the frame*/
	background-color: rgb(2, 0, 0);
}
/*Style every QPushButton inside of the frame*/
QFrame#frame1 QPushButton {
	color: rgb(220, 0, 0);
}
/*Style a single QPushButton*/
QFrame#frame1 QPushButton#button2 {
	color: rgb(221, 0, 0);
}
/*Style all label's in the container*/
Qframe#frame1 QLabel {
	background-color: rgb(0, 221, 0);
}

Also, even if a button with an object name called button1 is inside of the QFrame frame1, you can style it outside of the QFrame such as

QPushButton#button1 {
	color: rgb(245, 0, 0);
}

For more information on stylings/or examples go here:
http://qt-project.org/doc/qt-4.8/stylesheet-examples.html

Now that the basics on how to style certain objects, an entire class (Class names start with Q), and containers, here is a list of containers, buttons, labels, etc by class/Object name tabbed within their respected containers:

Key:
Class Name - Object Name

QWidget - widget (any styling to this would be the entire program)
	QFrame - Options
		QPushButton - About
		QComboBox - Language_box
		QLabel - Language_label
		QLabel - Options_2
		QComboBox - Theme_box
		QLabel - Theme_label
		QLabel - Update
		QPushButton - Updater_button
	QPushButton - closeoptions
	QFrame - controlLayout
		QPushButton - playButton
		QSlider - positionSlider
		QPushButton - volumeButton
		QSlider - volumeSlider
		QLabel - volume_label
	QPushButton - exit
	QFrame - footer
		QPushButton - Options_3
	QFrame - mainbox
		QGraphicsView - graphicsView_AccessFlashDrive
		QGraphicsView - graphicsView_FizzBuzz
		QGraphicsView - graphicsView_MCUHelper
		QGraphicsView - graphicsView_SPL
		QGraphicsView - graphicsView_TradingPost
		QLabel - miscellaneous_label
		QPushButton - program_AccessFlashDrive
		QPushButton - program_AccessFlashDrive_picture
		QPushButton - program_FizzBuzz
		QPushButton - program_FizzBuzz_picture
		QPushButton - program_MCUHelper
		QPushButton - program_MCUHelper_picture
		QPushButton - program_SPL
		QPushButton - program_SPL_picture
		QPushButton - program_TradingPost
		QPushButton - program_TradingPost_picture
		QLabel - program_label
	QPushButton - minimize
	QFrame - programs_window
		QPushButton - Back
		QTabWidget - Information
			QWidget - SourceTab
				QPushButton - back
				QPushButton - forward
				QWebView - source
		QPushButton - Run

Special thanks to mart3323 for creating a few themes.