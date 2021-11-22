# Manu
This folders hold all files and classes to create the menu. The main folder contains all subclasses which are needed to creat a menu entry, window, ... 

The file ***pins.h*** contains definitions where the 4 buttons (up, down, right, left) are connected. Furthermur a pin is defined to connect a seaker to.

## How to create a new window
A window displays infromation or a menu to lead to another window. A new winfo must inher from ***Menu*** for a new Menu or from ***Frame*** to display infromation graphs and other stuff. To display the new window the method ***acitvateMe()*** has to be called.

As an argument the bause class needs an headline and the parrent instance of an window class

The mthod drawMenu() contains the code defining waht to draw. With the method buttonNext() the action can be difined if the next button is pressed. Same can be done for buttonPrev()buttonUp()	buttonDown(), But this is not needed becaus the will be handeld by the framework.

## How to draw a Menu
TO create a Menu inhere from ***Menu*** class. To create a menu entry ***drawEntry*** can be used. The name of the entrypoint will be set by the argument. To display only infromation ***drawInfo*** can be used.

To defin what should be executed wehen next utton is pressed ***activeEntry*** holds the selected menu idex
